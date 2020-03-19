#include "_vector.h"

//template <typename T>
//Vector<T>::Vector() : size(0), array(nullptr) {}
//
//template <typename T>
//Vector<T>::Vector(uint32_t s, T *array) : size(s), array(array) {}
//
//template <typename T>
//Vector<T>::Vector(T n, ...)
//{
//    T *p = &n;
//    array = new T[sizeof(n) / sizeof(T)];
//    uint32_t i = 0;
//    while (*p)
//    {
//        array[i] = *p;
//        i++;
//        p++;
//    }
//}
//
//template <typename T>
//Vector<T>::~Vector() { delete []array; }
//
//template <typename T>
//uint32_t Vector<T>::get_size() { return size; }
//
//template <typename T>
//T *Vector<T>::get_array() { return array; }
//
//template <typename T>
//Vector<T> &Vector<T>::operator = (const Vector &r)
//{
//
//}
//
//template <typename T>
//const Vector<T> &operator + (const Vector<T> &v)
//{
//
//}
//
//template <typename T>
//Vector<T> operator - (const Vector<T> &v)
//{
//
//}
//
//template <typename T>
//const Vector<T> operator + (const Vector<T> &vl, const Vector<T> &vr)
//{
//
//}
//
//template <typename T>
//Vector<T> &operator += (Vector<T> &vl, const Vector<T> &vr)
//{
//
//}
//
//template <typename T>
//const Vector<T> operator - (const Vector<T> &vl, const Vector<T> &vr)
//{
//
//}
//
//template <typename T>
//Vector<T> &operator -= (Vector<T> &vl, const Vector<T> &vr)
//{
//
//}
//
//template <typename T>
//const Vector<T> operator * (const Vector<T> &vl, const Vector<T> &vr)
//{
//
//}
//
//template <typename T>
//Vector<T> &operator *= (Vector<T> &vl, const Vector<T> &vr)
//{
//
//}
//
//template <typename T, typename K>
//const Vector<K> operator * (Vector<T> &v, const K k)
//{
//
//}
//
//template <typename T, typename K>
//const Vector<K> operator * (const K k, Vector<T> &v)
//{
//
//}
//
//template <typename K>
//Vector<K> &operator *= (Vector<K> &v, const K k)
//{
//
//}
//
//template <typename T, typename K>
//const Vector<double> operator / (Vector<T> &v, const K k)
//{
//
//}
//
//template <typename T, typename K>
//Vector<double> &operator /= (Vector<T> &v, const K k)
//{
//
//}
//
//template <typename T>
//bool operator == (const Vector<T> &, const Vector<T> &)
//{
//
//}
//
//template <typename T>
//bool operator != (const Vector<T> &, const Vector<T> &)
//{
//
//}
//
//template <typename T>
//Vector<T> &operator <<= (Vector<T> &, T)
//{
//
//}
//
//template <typename T>
//const Vector<T> operator << (const Vector<T> &, T)
//{
//
//}
//
//template <typename T>
//Vector<T> &operator >>= (Vector<T> &, T *)
//{
//
//}
//
//template <typename T>
//const Vector<T> operator >> (const Vector<T> &, T *)
//{
//
//}
//
//template <typename T>
//T *operator <<= (T *, Vector<T> &)
//{
//
//}
//
//template <typename T>
//T *operator << (T *, const Vector<T> &)
//{
//
//}
//
//template <typename T>
//Vector<T> &operator >>= (T *, Vector<T> &)
//{
//
//}
//
//template <typename T>
//const Vector<T> operator >> (T *, const Vector<T>)
//{
//
//}
//
//template <typename T>
//T *pop(uint32_t index = -1, ...)
//{
//
//}
//
//template <typename T>
//void push(const T &, uint32_t index = -1, ...)
//{
//
//}
//
//template <typename T>
//void push(T, uint32_t index = -1, ...)
//{
//
//}
//
//template <typename T>
//void push(uint32_t index, T, ...)
//{
//
//}
//
//template <typename T>
//void push(uint32_t index, const T &, ...)
//{
//
//}
