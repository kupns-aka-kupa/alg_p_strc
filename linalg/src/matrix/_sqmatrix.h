#ifndef _SQMATRIX_H
#define _SQMATRIX_H

#include "_matrix.h"

class SqMatrix : public Matrix
{
private:
    static int _k(int);
    static double _2x2_det(double **);
    static double _3x3_det(double **);
    static double _nxn_det(double **, int);

public:
    SqMatrix();
    SqMatrix(int, double **);
    SqMatrix(const SqMatrix &);
    ~SqMatrix();

    friend const SqMatrix operator ~ (const SqMatrix &);
    friend const SqMatrix operator / (const SqMatrix &, const SqMatrix &);
    friend SqMatrix & operator /= (SqMatrix &, const SqMatrix &);

    double determinant();
    void inverse();
};

#endif // _SQMATRIX_H
