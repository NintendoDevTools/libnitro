//
// Created by mart on 6/16/20.
//

#ifndef LIBNITRO_NITRO_DEVICE_H
#define LIBNITRO_NITRO_DEVICE_H

#include <libusb-1.0/libusb.h>

class nitro_device {
private:
    short product_id;
    short vendor_id = 0x0f6e;

protected:
    libusb_device_handle * device;

    nitro_device(short prod_id);
    ~nitro_device();

public:
    bool debug = false;

    bool valid();
};


#endif //LIBNITRO_NITRO_DEVICE_H
