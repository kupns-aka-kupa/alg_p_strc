#ifndef NODEKDL_HPP
#define NODEKDL_HPP

#include "_node_kdlxx.hpp"

template<typename _K, typename _T>
struct NodeKDLL : NodeKDLXX<_K, _T>
{
    NodeKDLL<_K, _T> *_left;
    NodeKDLL<_K, _T> *_right;

    NodeKDLL();
    NodeKDLL(_T data = new _T(), NodeKDLL<_K, _T> *left = nullptr, NodeKDLL<_K, _T> *right = nullptr);

    ~NodeKDLL();
};

#include "_node_kdll.tpp"

#endif // NODEKDL_HPP
