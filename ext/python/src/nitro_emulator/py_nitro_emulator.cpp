//
// Created by mart on 6/17/20.
//

#include "../../include/nitro_emulator/py_nitro_emulator.h"
#include "../../../../include/nitro_emulator.h"

typedef struct {
    PyObject_HEAD
    nitro_emulator* emulator;
} PyObject_NitroEmulator;

static int NitroEmulator_Init(PyObject_NitroEmulator *self, PyObject *args, PyObject *kwds) {
    self->emulator = new nitro_emulator();
    return 0;
}

PyTypeObject PyType_NitroEmulator = {
        PyObject_HEAD_INIT(NULL)
        .tp_name = "NitroEmulator",
        .tp_basicsize = sizeof(PyObject_NitroEmulator),
        .tp_itemsize = 0,
        .tp_flags = Py_TPFLAGS_DEFAULT,
        .tp_init = (initproc) NitroEmulator_Init,
        .tp_new = PyType_GenericNew,
};

