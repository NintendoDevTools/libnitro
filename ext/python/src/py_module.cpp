//
// Created by mart on 6/16/20.
//

#include <Python.h>
#include "../include/py_module.h"
#include "../include/nitro_emulator/py_module_emulator.h"

static PyModuleDef libnitro_native = {
    PyModuleDef_HEAD_INIT,
    "libnitro_native",
    NULL,
    -1
};

#ifdef __cplusplus
extern "C" {
#endif

PyObject* PyInit_libnitro_native() {
    PyObject *mod = PyModule_Create(&libnitro_native);

    if (mod == NULL) {
        return NULL;
    }

    Py_XINCREF(mod);

    // Add objects
    PyModule_AddObject(mod, "nitro_emulator", PyModule_NitroEmulator_Init());

    return mod;
}

#ifdef __cplusplus
}
#endif
