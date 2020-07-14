//
// Created by mart on 6/17/20.
//

#ifndef LIBNITRO_PY_NITRO_EMULATOR_ENUMS_H
#define LIBNITRO_PY_NITRO_EMULATOR_ENUMS_H

#include <Python.h>

PyObject* PyEnum_MemoryRegion_Init();
PyObject* PyEnum_WriteCommandCode_Init();
PyObject* PyEnum_ReadCommandCode_Init();

#endif //LIBNITRO_PY_NITRO_EMULATOR_ENUMS_H
