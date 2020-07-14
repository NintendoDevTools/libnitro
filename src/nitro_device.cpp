//
// Created by mart on 6/16/20.
//

#include <cstdlib>
#include <cstdio>
#include "../include/nitro_device.h"

static libusb_context* context;

nitro_device::nitro_device(short prod_id) {
    product_id = prod_id;
    libusb_init(&context);
    device = libusb_open_device_with_vid_pid(context, vendor_id, product_id);
    if (device == nullptr) {
        printf("LibNitro:ERR:Device not found, exiting...\n");
        exit(1);
    }
    libusb_claim_interface(device, 0);
}

nitro_device::~nitro_device() {
    libusb_close(device);
    device = nullptr;
}

bool nitro_device::valid() {
    return (device != nullptr);
}