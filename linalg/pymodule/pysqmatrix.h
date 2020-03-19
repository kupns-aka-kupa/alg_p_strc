#ifndef PYSQMATRIX_H
#define PYSQMATRIX_H

#include "../globconf.h"
#include "../src/matrix/_sqmatrix.h"

namespace pysqmatrix
{

typedef struct
{
    PyObject_HEAD;
    SqMatrix *matrix;
} PySqMatrix;

int __init__(PySqMatrix *self, PyObject *args);
PyObject *__new__(PyTypeObject *type, PyObject *args, PyObject *kwargs);
void __del__(PySqMatrix *self);
PyObject *__repr__(PySqMatrix *self);

PyObject *__add__(PySqMatrix *self, PySqMatrix *other),
         *__sub__(PySqMatrix *self, PySqMatrix *other),

         *__mul__(PySqMatrix *self, PySqMatrix *other),
         *__mul__(PySqMatrix *self, PyObject *other);

PyObject *__neg__(PySqMatrix *self),
         *__pos__(PySqMatrix *self),
         *__abs__(PySqMatrix *self),
         *__invert__(PySqMatrix *self),

         *__lshift__(PySqMatrix *self, PyObject *other),
         *__rshift__(PySqMatrix *self, PyObject *other);

PyObject *__iadd__(PySqMatrix *self, PySqMatrix *other),
         *__isub__(PySqMatrix *self, PySqMatrix *other),

         *__imul__(PySqMatrix *self, PySqMatrix *other),
         *__imul__(PySqMatrix *self, PyObject *other),

         *__ilshift__(PySqMatrix *self, PyObject *other),
         *__irshift__(PySqMatrix *self, PyObject *other);

PyObject *determinant(PySqMatrix *self);

#endif // PYSQMATRIX_H

}
