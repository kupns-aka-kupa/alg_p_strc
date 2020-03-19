#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>
#include <bits/stdc++.h>
#include "../tensor/_tensor.h"
#include "../vector/_vector.h"

class Matrix : public Tensor<>
{
protected:
    uint32_t m, n;
//    union
//    {
        Vector<double> *v;
        double **array;
//    };

    void _row_swap(uint32_t i, uint32_t k);
    void _row_sum(uint32_t i, uint32_t k);
    void _row_mul(uint32_t i, double k);

    static double ** _minor_alloc(double **m, uint32_t i, uint32_t n);
    static void _minor_dealloc(double **m, uint32_t n);

public:
    Matrix();
    Matrix(uint32_t m, uint32_t n);
    Matrix(uint32_t m, uint32_t n, double **array);
    Matrix(const Matrix &m);
    ~Matrix();

    uint32_t *get_size();
    std::string to_str();
    void print();
    double **get_array();

    Matrix &operator = (const Matrix &right);

    /* Unary */
    friend const Matrix &operator + (const Matrix &m);
    friend Matrix operator - (const Matrix &m);

    friend const Matrix &operator ++ (Matrix &m);
    friend const Matrix operator ++ (Matrix &m, int);

    friend const Matrix &operator -- (Matrix &m);
    friend const Matrix operator -- (Matrix &m, int);

    /* Binary */
    friend const Matrix operator + (const Matrix &ml, const Matrix &mr);
    friend Matrix &operator += (Matrix &ml, const Matrix &mr);

    friend const Matrix operator - (const Matrix &ml, const Matrix &mr);
    friend Matrix &operator -= (Matrix &ml, const Matrix &mr);

    friend const Matrix operator * (const Matrix &ml, const Matrix &mr);
    friend Matrix &operator *= (Matrix &ml, const Matrix &mr);

    friend const Matrix operator * (Matrix &m, const double k);
    friend const Matrix operator * (const double k, Matrix &m);
    friend Matrix &operator *= (Matrix &m, const double k);

    friend const Matrix operator / (Matrix &m, const double k);
    friend Matrix &operator /= (Matrix &m, const double k);

    friend bool operator == (const Matrix &ml, const Matrix &mr);
    friend bool operator != (const Matrix &ml, const Matrix &mr);

    friend Matrix &operator <<= (Matrix &m, double *rowin);
    friend const Matrix operator << (const Matrix &m, double *rowin);

    friend Matrix &operator >>= (Matrix &m, double *rowout);
    friend const Matrix operator >> (const Matrix &m, double *rowout);

    friend double *operator <<= (double *rowout, Matrix &m);
    friend double *operator << (double *rowout, const Matrix &m);

    friend Matrix &operator >>= (double *rowin, Matrix &m);
    friend const Matrix operator >> (double *rowin, const Matrix &m);


    /* Class */
    void transpose();
    void push_row(const double *const rowin, const uint32_t n, ...);
    double *pop_row(const double n, ...);
    void push_col(const double *const colin, const uint32_t n, ...);
    double *pop_col(const double n, ...);
};

#endif // MATRIX_H
