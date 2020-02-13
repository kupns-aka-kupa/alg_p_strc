#ifndef NODEDL_H
#define NODEDL_H

#include "_node_dlxx.hpp"

template<typename _T>
struct NodeDL : public NodeDLXX<_T>
{
    NodeDL<_T> *next;

    NodeDL();
    NodeDL(_T data = new _T(), NodeDL<_T> *next = nullptr);

    ~NodeDL();
};

template<typename _T>
NodeDL<_T>::NodeDL() : NodeDLXX<_T>() {}

template<typename _T>
NodeDL<_T>::NodeDL(_T data, NodeDL<_T> *next) :
    NodeDLXX<_T>(data, new NodeDLXX<_T> *{ dynamic_cast<NodeDLXX<_T> *>(next) }),
    next(next) {}

template<typename _T>
NodeDL<_T>::~NodeDL() { next = nullptr; }

#endif // NODEDL_H
