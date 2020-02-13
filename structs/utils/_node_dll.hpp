#ifndef NODEDLL_H
#define NODEDLL_H

#include "_node_dlxx.hpp"

template<typename _T>
struct NodeDLL : public NodeDLXX<_T>
{
    NodeDLL<_T> *prev;
    NodeDLL<_T> *next;

    NodeDLL();
    NodeDLL(_T data = new _T(), NodeDLL<_T> *prev = nullptr, NodeDLL<_T> *next = nullptr);

    ~NodeDLL();

    void swap_direction();
};

template<typename _T>
NodeDLL<_T>::NodeDLL() :
    NodeDLXX<_T>(),
    prev(nullptr),
    next(nullptr) {}

template<typename _T>
NodeDLL<_T>::NodeDLL(_T data, NodeDLL<_T> *prev, NodeDLL<_T> *next) :
     NodeDLXX<_T>(data, new NodeDLXX<_T> *[2]{
         dynamic_cast< NodeDLXX<_T> *>(prev),
         dynamic_cast< NodeDLXX<_T> *>(next) }),
     prev(prev),
     next(next) {}

template<typename _T>
NodeDLL<_T>::~NodeDLL()
{
    prev = nullptr;
    next = nullptr;
}

template<typename _T>
void NodeDLL<_T>::swap_direction()
{
    auto tmp = prev;
    prev = next;
    next = tmp;
}
#endif // NODEDLL_H
