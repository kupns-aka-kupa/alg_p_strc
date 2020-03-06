#ifndef _PY_MATRIX_TYPE_H
#define _PY_MATRIX_TYPE_H

#include "../globconf.h"
#include "../src/matrix/_matrix.h"

namespace pymatrix
{

typedef struct
{
    PyObject_HEAD;
    Matrix *matrix;
} PyMatrix;

int __init__(PyMatrix *self, PyObject *args);
void __del__(PyMatrix *self);
PyObject *__new__(PyTypeObject *type, PyObject *args, PyObject *kwargs),
         *__repr__(PyMatrix *self),

         *__add__(PyMatrix *self, PyMatrix *other),
         *__sub__(PyMatrix *self, PyMatrix *other),

         *__mul__(PyMatrix *self, PyMatrix *other),
         *__mul__(PyMatrix *self, PyObject *other),

         *__neg__(PyMatrix *self),
         *__pos__(PyMatrix *self),
         *__abs__(PyMatrix *self),
         *__invert__(PyMatrix *self),

         *__lshift__(PyMatrix *self, PyObject *other),
         *__rshift__(PyMatrix *self, PyObject *other),

         *__iadd__(PyMatrix *self, PyMatrix *other),
         *__isub__(PyMatrix *self, PyMatrix *other),

         *__imul__(PyMatrix *self, PyMatrix *other),
         *__imul__(PyMatrix *self, PyObject *other),

         *__ilshift__(PyMatrix *self, PyObject *other),
         *__irshift__(PyMatrix *self, PyObject *other),

         *determinant(PyMatrix *self),
         *to_list(PyMatrix *self);

void transpose(PyMatrix *self);

#endif // _PY_MATRIX_TYPE_H

} // pymatrix
