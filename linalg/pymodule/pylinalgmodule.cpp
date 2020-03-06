#include "pylinalgmodule.h"

namespace pylinalgmodule {

int PyModule_AddType(PyObject *module, const char *name, PyTypeObject *type)
{
    if (PyType_Ready(type) < 0) {
        return -1;
    }
    Py_INCREF(type);
    if (PyModule_AddObject(module, name, (PyObject *)type) < 0) {
        Py_DECREF(type);
        Py_DECREF(module);
        return -1;
    }
    return 0;
}

PyMODINIT_FUNC
PyInit_linalg()
{
    PyObject *module = PyModule_Create(&Linalg);
    if (module == NULL) return NULL;

    PyModule_AddType(module, "Matrix", &PyTypeMatrix);
    PyModule_AddType(module, "Vector", &PyTypeVector);

    return module;
}

} // pylinalgmodule
