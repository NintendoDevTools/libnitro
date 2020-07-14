//
// Created by mart on 6/16/20.
//

#include <algorithm>
#include <cstdio>
#include "../include/nitro_emulator.h"
#include "../include/util.h"

#define MODE_WRITE 0
#define MODE_READ  1
#define MODE_DEBUG 2

// CONSTRUCTOR/DESTRUCTOR

nitro_emulator::nitro_emulator() : nitro_device(0x0404) {
    libusb_device* _device = libusb_get_device(device);
    max_in_size = libusb_get_max_packet_size(_device, in_endpoint);
    max_out_size = libusb_get_max_packet_size(_device, out_endpoint);
    video_settings = 0x00;
}

// PRIVATE METHODS

int nitro_emulator::do_write(char *data, int size) {
    int written = 0;
    printf("Writing data [%d]\n", size);
    for (int i = 0; i < size; i++) {
        char c = data[i];
        printf("%02x", c);
    }
    printf("\n");
    while (written < size) {
        int tmp;
        int err = libusb_bulk_transfer(device, out_endpoint, (__u_char*)&data[written], std::min(size-written, max_out_size), &tmp, 0);
        if (err != 0) {
            printf("LibNitro:ERR:Lost connection to device.\n");
            libusb_close(device);
            device = nullptr;
            return err;
        }
        written += tmp;
    }
    return 0;
}


int nitro_emulator::_write(WRITE_COMMAND_CODE command, MEMORY_REGION region, int address, char *data, int size) {
    int err;
    char* cmd = (new buffer(16 + size))
            -> pack((short)command)
            -> pack((char)MODE_WRITE)
            -> pack((char)region)
            -> pack(address)
            -> pack(size)
            -> pack(0x00000000)
            -> pack(data, size)
            -> getBuf();
    err = do_write(cmd, 16 + size);
    free(cmd);
    return err;
}

int nitro_emulator::do_read(char *buf, int size) {
    int read = 0;
    while (read < size) {
        int tmp;
        int err = libusb_bulk_transfer(device, in_endpoint, (__u_char*)&buf[read], std::min(size-read, max_in_size), &tmp, 0);
        if (err != 0) {
            printf("LibNitro:ERR:Lost connection to device.\n");
            libusb_close(device);
            device = nullptr;
            return err;
        }
        read += tmp;
    }
    return 0;
}

int nitro_emulator::_read(READ_COMMAND_CODE command, MEMORY_REGION region, int address, char *buf, int size) {
    int err;
    char* cmd = (new buffer(16))
            -> pack((short)command)
            -> pack((char)MODE_READ)
            -> pack((char)region)
            -> pack(address)
            -> pack(size)
            -> pack(0x00000000)
            -> getBuf();
    // Write header, then read
    if ((err = do_write(cmd, 16)) == 0) {
        err = do_read(buf, size);
    }
    free(cmd);
    return err;
}

// PUBLIC_METHODS

int nitro_emulator::write_cmd(WRITE_COMMAND_CODE command, int address, char *data, int size) {
    return _write(command, REGION_CONTROL, address, data, size);
}

int nitro_emulator::read_cmd(READ_COMMAND_CODE command, int address, char *buf, int size) {
    return _read(command, REGION_CONTROL, address, buf, size);
}

int nitro_emulator::debug_cmd(DEBUG_COMMAND_CODE command, int address, char *buf, int size) {
    int err;
    char* cmd = (new buffer(16))
            -> pack((short)command)
            -> pack((char)MODE_DEBUG)
            -> pack((char)REGION_CONTROL)
            -> pack(address)
            -> pack(size)
            -> pack(0x00000000)
            -> getBuf();
    // Write header, then read(?), needs checking
    if ((err = do_write(cmd, 16)) == 0) {
        err = do_read(buf, size);
    }
    free(cmd);
    return err;
}

int nitro_emulator::write_memory(MEMORY_REGION region, int address, char *data, int size) {
    if (region == REGION_CONTROL) return -1;
    return _write((WRITE_COMMAND_CODE)0, region, address, data, size);
}

int nitro_emulator::read_memory(MEMORY_REGION region, int address, char *buf, int size) {
    if (region == REGION_CONTROL) return -1;
    return _read((READ_COMMAND_CODE)0, region, address, buf, size);
}

int nitro_emulator::write_nec(int address, char *data, int size, int write_size) {
    if (size % write_size != 0) return -1;
    if (write_size != 1 && write_size != 2 && write_size != 4) return -1;
    int err;

    char* nec_command = (new buffer(8 + size))
            -> pack((char)WRITE_NEC)
            -> pack((char)write_size)
            -> pack((short)(size / write_size))
            -> pack(address)
            -> pack(data, size)
            -> getBuf();

    err = write_cmd(WRITE_NEC, 0x00000000, nec_command, 8+size);
    free(nec_command);

    return err;
}

int nitro_emulator::write_nec_noincrement(int address, char *data, int size, int write_size) {
    if (size % write_size != 0) return -1;
    if (write_size != 1 && write_size != 2 && write_size != 4) return -1;
    int err;

    char* nec_command = (new buffer(8 + size))
            -> pack((char)WRITE_NEC_NOINCREMENT)
            -> pack((char)write_size)
            -> pack((short)(size / write_size))
            -> pack(address)
            -> pack(data, size)
            -> getBuf();

    err = write_cmd(WRITE_NEC_NOINCREMENT, 0x00000000, nec_command, 8+size);
    free(nec_command);

    return err;
}

int nitro_emulator::enable_video() {
    write_nec(0x08000010, (char*)"\x59\x00", 2, 2);
    write_nec(0x08000012, (char*)"\x4F\x00", 2, 2);
    write_nec(0x08000014, (char*)"\x4B\x00", 2, 2);
    write_nec(0x08000016, (char*)"\x4F\x00", 2, 2);
    /*
    return write_nec(
        0x08000010,
        (char*)"Y\x00O\x00K\x00O\x00",  // YOKO, Romanji for "Monitor" according to Gericom
        8,
        2
    );*/
    return 0;
}

int nitro_emulator::set_video_color(int color){
    short r = (color >> 16) & 0xFF;
    short g = (color >> 8) & 0xFF;
    short b = color & 0xFF;
    // TODO: Try sending in different packets
    char* color_packet = (new buffer(6))
            -> pack(r)
            -> pack(g)
            -> pack(b)
            -> getBuf();
    int err = write_nec(0x08000018, color_packet, 6, 2);
    free(color_packet);
    return err;
}

int nitro_emulator::set_video_config_deflicker(bool deflicker_type, bool deflicker_state) {
    short state = (video_settings & 0b00111111) +
            (deflicker_type << 7) +
            (deflicker_state << 6);
    char* buf = (new buffer(2))
            -> pack(state)
            -> getBuf();
    int err = write_nec(0x0800001e, buf, 2, 2);
    if (err == 0) {
        video_settings = state;
    }
    free(buf);
    return err;
}

int nitro_emulator::set_video_config_av1(VIDEO_STATE mode) {
    short state = (video_settings & 0b11001111) + (mode << 4);
    char* buf = (new buffer(2))
            -> pack(state)
            -> getBuf();
    int err = write_nec(0x0800001e, buf, 2, 2);
    if (err == 0) {
        video_settings = state;
    }
    free(buf);
    return err;
}

int nitro_emulator::set_video_config_av2(VIDEO_STATE mode) {
    short state = ((video_settings & 0b11111100) + mode) & 0xFF;
    char* buf = (new buffer(2))
            -> pack(state)
            -> getBuf();
    int err = write_nec(0x0800001e, buf, 2, 2);
    if (err == 0) {
        video_settings = state;
    }
    free(buf);
    return err;
}

int nitro_emulator::set_video_config_rotation(bool right, bool enable) {
    short state = (video_settings & 0b11110011) +
                  (right << 3) +
                  (enable << 2);
    char* buf = (new buffer(2))
            -> pack(state)
            -> getBuf();
    int err = write_nec(0x0800001e, buf, 2, 2);
    if (err == 0) {
        video_settings = state;
    }
    free(buf);
    return err;
}
