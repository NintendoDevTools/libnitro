//
// Created by mart on 6/18/20.
//

#include "../../include/nitro_emulator/py_nitro_emulator_enums.h"
#include "../../../../include/nitro_emulator_enums.h"

#define EnumField(mod, name, c_num) PyModule_AddObject(mod, name, PyLong_FromLong(c_num))

static PyModuleDef PyEnum_MemoryRegion = {
    PyModuleDef_HEAD_INIT,
    "MEMORY_REGION",
    NULL,
    -1
};

static PyModuleDef PyEnum_WriteCommandCode = {
    PyModuleDef_HEAD_INIT,
    "WRITE_COMMAND_CODE",
    NULL,
    -1
};

static PyModuleDef PyEnum_ReadCommandCode = {
    PyModuleDef_HEAD_INIT,
    "READ_COMMAND_CODE",
    NULL,
    -1
};

PyObject* PyEnum_MemoryRegion_Init() {
    PyObject* mod = PyModule_Create(&PyEnum_MemoryRegion);
    EnumField(mod, "REGION_CONTROL", REGION_CONTROL);
    EnumField(mod, "REGION_NDS_SRAM", REGION_NDS_SRAM);
    EnumField(mod, "REGION_AGB_SRAM", REGION_AGB_SRAM);
    EnumField(mod, "REGION_UNKNOWN_0x03", REGION_UNKNOWN_0x03);
    EnumField(mod, "REGION_AGB_BUS", REGION_AGB_BUS);
    EnumField(mod, "REGION_AGB_BUS_EXTRA", REGION_AGB_BUS_EXTRA);
    return mod;
}

PyObject* PyEnum_WriteCommandCode_Init() {
    PyObject* mod = PyModule_Create(&PyEnum_WriteCommandCode);

    return mod;
}

PyObject* PyEnum_ReadCommandCode_Init() {
    PyObject* mod = PyModule_Create(&PyEnum_ReadCommandCode);

    return mod;
}