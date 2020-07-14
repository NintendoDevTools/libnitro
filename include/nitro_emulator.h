//
// Created by mart on 6/16/20.
//

#ifndef LIBNITRO_NITRO_EMULATOR_H
#define LIBNITRO_NITRO_EMULATOR_H

#include "./nitro_emulator_enums.h"
#include "./nitro_device.h"

class nitro_emulator : public nitro_device {
private:
    char in_endpoint = 0x82;
    char out_endpoint = 0x01;

    int max_in_size;
    int max_out_size;

    char video_settings;

    int do_write(char* data, int size);
    int _write(WRITE_COMMAND_CODE command, MEMORY_REGION region, int address, char *data, int size);
    int do_read(char* buf, int size);
    int _read(READ_COMMAND_CODE command, MEMORY_REGION region, int address, char *buf, int size);

public:
    nitro_emulator();

    int write_cmd(WRITE_COMMAND_CODE command, int address, char *data, int size);
    int read_cmd(READ_COMMAND_CODE command, int address, char *buf, int size);
    int debug_cmd(DEBUG_COMMAND_CODE command, int address, char *buf, int size);
    int write_memory(MEMORY_REGION region, int address, char *data, int size);
    int read_memory(MEMORY_REGION region, int address, char *bug, int size);
    int write_nec(int address, char* data, int size, int write_size);
    int write_nec_noincrement(int address, char* data, int size, int write_size);

    int enable_video();
    int set_video_color(int color);
    int set_video_config_deflicker(bool deflicker_type, bool deflicker_state);
    int set_video_config_av1(VIDEO_STATE mode);
    int set_video_config_av2(VIDEO_STATE mode);
    int set_video_config_rotation(bool right, bool enable);

};

#endif //LIBNITRO_NITRO_EMULATOR_H

