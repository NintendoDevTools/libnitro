//
// Created by mart on 6/20/20.
//

#ifndef LIBNITRO_PY_UTIL_H
#define LIBNITRO_PY_UTIL_H

#include <Python.h>

int PyModule_AddType(PyObject *module, const char *name, PyTypeObject *type) {
    if (PyType_Ready(type)) {
        return -1;
    }
    Py_INCREF(type);
    if (PyModule_AddObject(module, name, (PyObject *) type)) {
        Py_DECREF(type);
        return -1;
    }
    return 0;
}

#endif //LIBNITRO_PY_UTIL_H
