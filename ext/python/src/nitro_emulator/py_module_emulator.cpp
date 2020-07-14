//
// Created by mart on 6/20/20.
//

#include "../../include/py_util.h"
#include "../../include/nitro_emulator/py_module_emulator.h"
#include "../../include/nitro_emulator/py_nitro_emulator.h"
#include "../../include/nitro_emulator/py_nitro_emulator_enums.h"

static PyModuleDef PyModule_NitroEmulator = {
        PyModuleDef_HEAD_INIT,
        "nitro_emulator",
        NULL,
        -1
};

PyObject* PyModule_NitroEmulator_Init() {
    PyObject* mod = PyModule_Create(&PyModule_NitroEmulator);

    Py_XINCREF(mod);

    PyModule_AddType(mod, "NitroEmulator", &PyType_NitroEmulator);
    PyModule_AddObject(mod, "MEMORY_REGION", PyEnum_MemoryRegion_Init());
    PyModule_AddObject(mod, "WRITE_COMMAND_CODE", PyEnum_WriteCommandCode_Init());
    PyModule_AddObject(mod, "READ_COMMAND_CODE", PyEnum_ReadCommandCode_Init());

    return mod;
}