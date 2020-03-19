#include "pymatrix.h"

namespace pymatrix {

int __init__(PyMatrix * self, PyObject * args)
{
    int m, n;
    PyObject * list;
    double ** array;

    if (!PyArg_ParseTuple(args, "O", &list))
    {
        return -1;
    }

    m = PyList_Size(list);
    array = new double * [m];
    PyObject * iter = PyObject_GetIter(list);
    if (!iter) {
        std::cout << "Not iterable" << std::endl;
        return -1;
    }

    for(int i = 0; i < m; i++)
    {
        PyObject * row = PyIter_Next(iter);
        n = PyList_Size(row);
        array[i] = new double[n];
        if (!row) break;
        if (!PyList_Check(row)) return -1;

        PyObject * col = PyObject_GetIter(row);
        for(int j = 0; j < n; j++)
        {
            PyObject *el = PyIter_Next(col);
            if (!el) break;
            array[i][j] = PyFloat_AsDouble(el);
        }
    }
//    self->matrix = new Matrix(m, n, array);
    return 0;
}

void __del__(PyMatrix * self)
{
    Py_TYPE(self)->tp_free(self);
}

PyObject * __repr__(PyMatrix * self)
{
    std::string str = self->matrix->to_str();
    char * cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());

    PyObject * res_str = Py_BuildValue("s", cstr);
    delete [] cstr;
    return res_str;
}

PyObject * __add__(PyMatrix * self, PyMatrix * other)
{
    Matrix m = ((*(self->matrix)) + (*(other->matrix)));
    PyMatrix py_matrix =
    {
        .matrix = & m
    };
    return to_list(& py_matrix);
//    return Py_TYPE(self)->tp_new(Py_TYPE(self), (PyObject * )& py_matrix, NULL);
}

PyObject * __sub__(PyMatrix * self, PyMatrix * other)
{
    Matrix m = ((*(self->matrix)) - (*(other->matrix)));
    PyMatrix py_matrix
    {
        .matrix = & m
    };
    return to_list(& py_matrix);
}

PyObject * __iadd__(PyMatrix * self, PyMatrix * other)
{
    (*(self->matrix)) += (*(other->matrix));
    return to_list(self);
}

PyObject * __isub__(PyMatrix * self, PyMatrix * other)
{
    (*(self->matrix)) -= (*(other->matrix));
    return to_list(self);
}

PyObject *__mul__(PyMatrix * self, PyMatrix * other)
{
    Matrix m = (*(self->matrix)) * (*(other->matrix));
    PyMatrix py_matrix
    {
        .matrix = & m
    };
    return to_list(& py_matrix);
}

PyObject *__mul__(PyMatrix * self, PyObject * other)
{
    double k = PyFloat_AsDouble(other);
    Matrix m = (*(self->matrix)) * k;
    PyMatrix py_matrix
    {
        .matrix = & m
    };
    return to_list(& py_matrix);
}

PyObject *__neg__(PyMatrix * self)
{
    Matrix m = - (*(self->matrix));
    PyMatrix py_matrix
    {
        .matrix = & m
    };
    return to_list(& py_matrix);
}

PyObject * __pos__(PyMatrix * self)
{
    Matrix m = + (*(self->matrix));
    PyMatrix py_matrix
    {
        .matrix = & m
    };
    return to_list(& py_matrix);
}

PyObject * __abs__(PyMatrix * self)
{
    return determinant(self);
}

PyObject * __invert__(PyMatrix * self)
{
    return to_list(self);
}

PyObject * __rshift__(PyMatrix * self, PyObject * other)
{
    return to_list(self);
}

PyObject * __lshift__(PyMatrix * self, PyObject * other)
{
    return to_list(self);
}

PyObject * __imul__(PyMatrix * self, PyMatrix * other)
{
    (*(self->matrix)) *= (*(other->matrix));
    return to_list(self);
}

PyObject * __imul__(PyMatrix * self, PyObject * other)
{
    double k = PyFloat_AsDouble(other);
    (*(self->matrix)) *= k;
    return to_list(self);
}

PyObject * __ilshift__(PyMatrix * self, PyObject * other)
{
    return to_list(self);
}

PyObject * __irshift__(PyMatrix * self, PyObject * other)
{
    return to_list(self);
}

PyObject * to_list(PyMatrix * self)
{
    double ** array = self->matrix->get_array();
    unsigned int * size = (self->matrix)->get_size();
    int n = size[1];
    int m = size[0];

    PyObject * list = PyList_New(m);

    for(int i = 0; i < m; i++)
    {
        PyObject * row_list = PyList_New(n);
        PyList_SetItem(list, i, row_list);

        for(int j = 0; j < n; j++)
        {
            PyObject * item = PyLong_FromDouble(array[i][j]);
            PyList_SetItem(row_list, j, item);
        }
    }

    return Py_BuildValue("O", list);
}

void transpose(PyMatrix * self)
{
    (self->matrix)->transpose();
}

//PyObject * determinant(PyMatrix * self)
//{
//    self->det = (self->matrix)->determinant();
//    return Py_BuildValue("d", self->det);
//}

} // pymatrix
