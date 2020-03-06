#ifndef _PY_VECTOR_TYPE_H
#define _PY_VECTOR_TYPE_H

#include "../globconf.h"
#include "../src/vector/_vector.h"

namespace pyvector
{

typedef struct
{
    PyObject_HEAD;
    Vector<PyObject> *vector;
} PyVector;

#endif // _PY_VECTOR_TYPE_H

}
