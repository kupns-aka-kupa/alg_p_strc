#ifndef Node_HPP
#define Node_HPP

#include <stdint.h>
#include <iostream>

template<typename _T>
struct Node
{
    _T *data;

    Node();
    Node(_T data = new _T());

    virtual ~Node();

    _T const &operator *() const;
};

template<typename _T>
Node<_T>::Node() : data(_T()){}

template<typename _T>
Node<_T>::Node(_T data) : data(new _T(data)){}


template<typename _T>
_T const &Node<_T>::operator *() const { return *this->data; }

template<typename _T>
Node<_T>::~Node()
{
    delete data;
    data = nullptr;
}

#endif // Node_HPP
