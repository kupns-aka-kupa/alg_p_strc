#include "_sqmatrix.h"

int SqMatrix::_k(int i)
{
    return (i % 2 == 0 ? 1: -1);
}

SqMatrix::SqMatrix(){}

SqMatrix::SqMatrix(int m, double **array) : Matrix(m, m, array)
{
    this->m = m;
}

SqMatrix::SqMatrix(const SqMatrix &m) : Matrix(m){}

SqMatrix::~SqMatrix(){}

double SqMatrix::_2x2_det(double **m)
{
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

double SqMatrix::_3x3_det(double **m)
{
    double det = 0;
    for (int i = 0; i < 3; i++)
    {
        double ** minor = Matrix::_minor_alloc(m, i, 2);
        det += _k(i) * m[0][i] * _2x2_det(minor);
        Matrix::_minor_dealloc(minor, 2);
    }
    return det;
}

double SqMatrix::_nxn_det(double **m, int n)
{
    double sum = 0;
    if (n < 5)
    {
        for (int i = 0; i < n; i++)
        {
            double ** minor = Matrix::_minor_alloc(m, i, 3);
            sum += _k(i) * m[0][i] * _3x3_det(minor);
            Matrix::_minor_dealloc(minor, 3);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            double **minor = Matrix::_minor_alloc(m, i, n - 1);
            sum += _k(i) * m[0][i] * _nxn_det(minor, n - 1);
            Matrix::_minor_dealloc(minor, n - 1);
        }
    }
    return sum;
}

const SqMatrix operator ~ (const SqMatrix &m)
{
    SqMatrix tmp = SqMatrix(m);
    tmp.inverse();
    return SqMatrix(tmp);
}

const SqMatrix operator / (const SqMatrix &m, const SqMatrix &im)
{
    Matrix tmp = (m * (~im));
    return (const SqMatrix &)tmp;
}

SqMatrix & operator /= (SqMatrix &m, const SqMatrix &im)
{
    (Matrix)m = (m * (~im));
    return (SqMatrix &)m;
}

double SqMatrix::determinant()
{
    if (m == 1)
    {
        return array[0][0];
    }
    else if (m == 2)
    {
        return _2x2_det(array);
    }
    else if (m == 3)
    {
        return _3x3_det(array);
    }
    else
    {
        return _nxn_det(array, m);
    }

}

void SqMatrix::inverse()
{
    double det = determinant();
    transpose();
    *this /= det;
}
