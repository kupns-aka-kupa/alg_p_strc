#ifndef NODEKDLXX_HPP
#define NODEKDLXX_HPP

#include "_node_dlxx.hpp"

template<typename _K, typename _T>
struct NodeKDLXX : NodeDLXX<_T>
{
    _K *key;

    NodeKDLXX();
    NodeKDLXX(_K key = new _K(), _T data = new _T(), NodeKDLXX **_next_sub_node = nullptr);

    ~NodeKDLXX();
};

#include "_node_kdlxx.tpp"

#endif // NODEKDLXX_HPP
