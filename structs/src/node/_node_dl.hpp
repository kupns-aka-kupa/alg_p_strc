#ifndef NODEDL_H
#define NODEDL_H

#include "_node.hpp"

template<typename _T>
struct NodeDL : public Node<_T>
{
    NodeDL<_T> *next;

    NodeDL();
    NodeDL(_T data = new _T(), NodeDL<_T> *next = nullptr);

    ~NodeDL();
};

template<typename _T>
NodeDL<_T>::NodeDL() : Node<_T>() {}

template<typename _T>
NodeDL<_T>::NodeDL(_T data, NodeDL<_T> *next) :
    Node<_T>(data),
    next(next) {}

template<typename _T>
NodeDL<_T>::~NodeDL() { next = nullptr; }

#endif // NODEDL_H
