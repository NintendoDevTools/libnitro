//
// Created by mart on 6/16/20.
//

#ifndef LIBNITRO_NITRO_EMULATOR_ENUMS_H
#define LIBNITRO_NITRO_EMULATOR_ENUMS_H

typedef enum {
    REGION_CONTROL,
    REGION_NDS_SRAM,
    REGION_AGB_SRAM,
    REGION_UNKNOWN_0x03,
    REGION_AGB_BUS,
    REGION_AGB_BUS_EXTRA
} MEMORY_REGION;

typedef enum {
    WRITE_UNKNOWN_0x01 = 0x01,
    WRITE_UNKNOWN_0x02,
    WRITE_UNKNOWN_0x03,
    WRITE_UNKNOWN_0x04,
    WRITE_UNKNOWN_0x05,
    WRITE_UNKNOWN_0x06,
    WRITE_UNKNOWN_0x0a = 0x0a,
    WRITE_NEC = 0x24,
    WRITE_UNKNOWN_0x25,
    WRITE_NEC_NOINCREMENT,
    WRITE_UNKNOWN_0x27,
    WRITE_UNKNOWN_0x80 = 0x80,
    WRITE_UNKNOWN_0x81,
    WRITE_UNKNOWN_0x83 = 0x83,
    WRITE_UNKNOWN_0x84,
    WRITE_UNKNOWN_0x85,
    WRITE_UNKNOWN_0x86,
    WRITE_UNKNOWN_0x87,
    WRITE_SELECTED_CPU = 0x8b,
    WRITE_UNKNOWN_0x8c,
    WRITE_UNKNOWN_0x9f = 0x9f,
    WRITE_UNKNOWN_0xa0,
    WRITE_UNKNOWN_0xa1,
    WRITE_UNKNOWN_0xa3 = 0xa3,
    WRITE_UNKNOWN_0xa4,
    WRITE_UNKNOWN_0xa5,
    WRITE_UNKNOWN_0xa8 = 0xa8,
    WRITE_UNKNOWN_0xa9,
    WRITE_UNKNOWN_0xaa,
    WRITE_UNKNOWN_0xab,
    WRITE_UNKNOWN_0xac,
    WRITE_UNKNOWN_0xad,
    WRITE_UNKNOWN_0xae,
    WRITE_UNKNOWN_0xaf,
    WRITE_UNKNOWN_0xb0,
    WRITE_UNKNOWN_0xb1,
    WRITE_UNKNOWN_0xb2,
    WRITE_UNKNOWN_0xb3,
    WRITE_UNKNOWN_0xb4,
    WRITE_UNKNOWN_0xb5,
    WRITE_UNKNOWN_0xb6,
    WRITE_UNKNOWN_0xb7,
    WRITE_UNKNOWN_0xb8,
    WRITE_UNKNOWN_0xb9,
    WRITE_UNKNOWN_0xba,
    WRITE_UNKNOWN_0xbb,
    WRITE_UNKNOWN_0xbc,
    WRITE_UNKNOWN_0xbd,
    WRITE_UNKNOWN_0xbe,
    WRITE_UNKNOWN_0xbf,
    WRITE_UNKNOWN_0xc0,
    WRITE_UNKNOWN_0xc1,
    WRITE_UNKNOWN_0xc2,
    WRITE_UNKNOWN_0xc3,
    WRITE_UNKNOWN_0xc4,
} WRITE_COMMAND_CODE;

typedef enum {
    READ_LCA1_DATA = 0x00,
    READ_UNKNOWN_0x01,
    READ_UNKNOWN_0x02,
    READ_UNKNOWN_0x03,
    READ_UNKNOWN_0x04,
    READ_UNKNOWN_0x05,
    READ_UNKNOWN_0x06,
    READ_UNKNOWN_0x07,
    READ_UNKNOWN_0x09 = 0x09,
    READ_DEVICE_SERIAL = 0x13,
    READ_NEC = 0x17,
    READ_UNKNOWN_0x18,
    READ_NEC_NOINCREMENT = 0x1a,
    READ_UNKNOWN_0x81 = 0x81,
    READ_UNKNOWN_0x82,
    READ_UNKNOWN_0x84,
    READ_UNKNOWN_0x87,
    READ_UNKNOWN_0x88,
    READ_UNKNOWN_0x89,
    READ_UNKNOWN_0x8b = 0x8b,
    READ_UNKNOWN_0x8c,
    READ_UNKNOWN_0x8d,
    READ_UNKNOWN_0x8e,
    READ_UNKNOWN_0x8f,
    READ_UNKNOWN_0x90,
    READ_UNKNOWN_0x91,
    READ_UNKNOWN_0x92,
    READ_UNKNOWN_0x93,
    READ_UNKNOWN_0x94,
    READ_UNKNOWN_0x95,
    READ_LCA3_SUBVERSION,
    READ_UNKNOWN_0x97,
    READ_FIFO_DATA_WRITE,
    READ_UNKNOWN_0x99,
    READ_FIFO_DATA_READ,
    READ_IPL_STATE,
    READ_IPL_DATA,
    READ_UNKNOWN_0x9d,
    READ_UNKNOWN_0x9e,
    READ_UNKNOWN_0xa0 = 0xa0,
    READ_UNKNOWN_0xa1,
    READ_UNKNOWN_0xa2,
    READ_UNKNOWN_0xa3,
    READ_UNKNOWN_0xa4,
    READ_UNKNOWN_0xa5,
    READ_UNKNOWN_0xa6,
    READ_UNKNOWN_0xa7,
    READ_UNKNOWN_0xa8,
    READ_UNKNOWN_0xa9,
} READ_COMMAND_CODE;

typedef enum {
    DEBUG_UNKNOWN_0x80 = 0x80,
} DEBUG_COMMAND_CODE;

typedef enum {
    VIDEO_DISABLED,
    VIDEO_TOP,
    VIDEO_BOTTOM,
    VIDEO_BOTH
} VIDEO_STATE;

#endif //LIBNITRO_NITRO_EMULATOR_ENUMS_H