cmake_minimum_required(VERSION 3.16)
project(libnitro_test)
add_executable(libnitro_test test.cpp src/util.cpp src/nitro_device.cpp src/nitro_emulator.cpp)
target_link_libraries(libnitro_test usb-1.0)