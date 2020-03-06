#ifndef VECTOR_H
#define VECTOR_H

#include "../tensor/_tensor.h"

template <typename T>
class Vector : Tensor<>
{
private:
    uint32_t size;
    T *array;
    Vector(const Vector<T> &);

public:
    Vector();
    Vector(uint32_t size, T *);
    Vector(T, ...);
    ~Vector();

//    uint32_t get_size();
//    T *get_array();
//
//    T *pop(uint32_t index = -1, ...);
//    void push(const T &, uint32_t index = -1, ...);
//    void push(T, uint32_t index = -1, ...);
//    void push(uint32_t index, T, ...);
//    void push(uint32_t index, const T &, ...);
//
//    Vector &operator = (const Vector &);
//
//    /* Unary */
//    friend const Vector<T> &operator + (const Vector<T> &);
//    friend Vector<T> operator - (const Vector<T> &);
//
//    /* Binary */
//    friend const Vector<T> operator + (const Vector<T> &, const Vector<T> &);
//    friend Vector<T> &operator += (Vector<T> &, const Vector<T> &);
//
//    friend const Vector<T> operator - (const Vector<T> , const Vector<T> &);
//    friend Vector<T> &operator -= (Vector<T> &, const Vector<T> &);
//
//    friend const Vector<T> operator * (const Vector<T> &, const Vector<T> &);
//    friend Vector<T> &operator *= (Vector<T> &, const Vector<T> &);
//
//    template <typename K>
//    friend const Vector<K> operator * (Vector &, K);
//
//    template <typename K>
//    friend const Vector<K> operator * (K, Vector &);
//
//    template <typename K>
//    friend Vector<K> &operator *= (Vector<K> &, K);
//
//    template <typename K>
//    friend const Vector<double> operator / (Vector &, K);
//
//    template <typename K>
//    friend Vector<double> &operator /= (Vector<double> &, K);
//
//    friend bool operator == (const Vector &, const Vector &);
//    friend bool operator != (const Vector &, const Vector &);
//
//    friend Vector<T> &operator <<= (Vector<T> &, T);
//    friend const Vector<T> operator << (const Vector &, T);
//
//    friend Vector<T> &operator >>= (Vector<T> &, T *);
//    friend const Vector<T> operator >> (const Vector<T> &, T *);
//
//    friend T *operator <<= (T *, Vector<T> &);
//    friend T *operator << (T *, const Vector<T> &);
//
//    friend Vector<T> &operator >>= (T *, Vector<T> &);
//    friend const Vector<T> operator >> (T *, const Vector<T>);
};

#endif // VECTOR_H
