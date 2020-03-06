#ifndef PYLINALG_H
#define PYLINALG_H

#include "pymatrix.h"
#include "pyvector.h"

using namespace pymatrix;
using namespace pyvector;

namespace pylinalgmodule
{

PyObject * (* mmm)(PyMatrix *, PyMatrix *) = __mul__,
         * (* mmk)(PyMatrix *, PyObject *) = __mul__,
         * (* immm)(PyMatrix *, PyMatrix *) = __mul__,
         * (* immk)(PyMatrix *, PyObject *) = __imul__;

PyNumberMethods PyMatrix_as_number_methods =
{
    .nb_add = (binaryfunc) __add__,
    .nb_subtract = (binaryfunc) __sub__,
    .nb_multiply = (binaryfunc) mmk,

    .nb_negative = (unaryfunc) __neg__,
    .nb_positive = (unaryfunc) __pos__,
    .nb_absolute = (unaryfunc) __abs__,
    .nb_invert = (unaryfunc) __invert__,

    .nb_lshift = (binaryfunc) __lshift__,
    .nb_rshift = (binaryfunc) __rshift__,

    .nb_inplace_add = (binaryfunc) __iadd__,
    .nb_inplace_subtract = (binaryfunc) __isub__,
    .nb_inplace_multiply = (binaryfunc) immk,

    .nb_inplace_lshift = (binaryfunc) __ilshift__,
    .nb_inplace_rshift = (binaryfunc) __irshift__,

    .nb_matrix_multiply = (binaryfunc) mmm,
    .nb_inplace_matrix_multiply = (binaryfunc) immm,
};

PyMethodDef PyMatrix_methods[] =
{
    {"transpose", (PyCFunction) transpose, METH_VARARGS, "transpose matrix"},
    {"to_list", (PyCFunction) to_list, METH_VARARGS, "return converted matrix to py_list"},
    {"det", (PyCFunction) determinant, METH_VARARGS, "return matrix (int)determinant"},
    {NULL, NULL, 0, NULL}
};

PyTypeObject PyTypeMatrix =
{
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cilen.Matrix",
    .tp_basicsize = sizeof(PyMatrix),
    .tp_dealloc = (destructor) __del__,
    .tp_repr = (reprfunc) __repr__,
    .tp_as_number = (PyNumberMethods *) & PyMatrix_as_number_methods,
    .tp_str = (reprfunc) __repr__,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_doc = "Linalg matrix object",
    .tp_methods = (PyMethodDef *) PyMatrix_methods,
    .tp_init = (initproc) __init__,
    .tp_alloc = (allocfunc) PyType_GenericAlloc,
    .tp_new = (newfunc) PyType_GenericNew,
};

PyTypeObject PyTypeVector =
{
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cilen.Vector",
    .tp_basicsize = sizeof(PyVector),
    .tp_new = PyType_GenericNew,
};

PyModuleDef Linalg =
{
    PyModuleDef_HEAD_INIT,
    .m_name = "linalg",
    .m_doc = "C++ linalg module objects wrapper",
    .m_size = -1,
};

int PyModule_AddType(PyObject * module, const char * name, PyTypeObject * type);

PyMODINIT_FUNC PyInit_linalg();

} // pylinalgmodule

#endif // PYLINALG_H
