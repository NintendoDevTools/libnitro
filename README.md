# Libnitro

This is my attempt at writing a driver for the IS-NITRO series of development kits made by Nintendo for the DS.
The method used was to look at existing software as well as the code on the NEC chips on each device, and work backwards from there.

# Goals

The goals of this project are:

- Support all 3 Nitro Devices (EMULATOR, CAPTURE, WRITER)
    - Note: This does not include the HUB as I can't find one
- Implement the following features:
    - [x] Read/Write memory on the GBA/NDS sectors
    - [ ] Load encrypted GBA/NDS roms and run them
    - [ ] Support debug-roms
    - [ ] Enable video

# Credits

A big thank-you goes out to the IS-NITRO research discord, and especially to Gericom, 
who made various tools based on wireshark analysis before me and was willing to share his code.
Another person I'd like to thank in particular is Stickteo, who made a fairly extensive list of registers and instructions.

# License
This code is licensed under MIT.