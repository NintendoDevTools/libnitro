//
// Created by mart on 6/22/20.
//

#include "include/nitro_emulator.h"

int main() {
    nitro_emulator* emu = new nitro_emulator();
    if (!emu->valid()) return 1;
    emu->enable_video();
    // emu->set_video_color(0xFF0000);
    emu->set_video_config_av1(VIDEO_TOP);
    emu->set_video_config_av2(VIDEO_BOTTOM);
    return 0;
}
