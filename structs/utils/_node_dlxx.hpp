#ifndef NODEDLXX_HPP
#define NODEDLXX_HPP

#include <stdint.h>

#include <iostream>
template<typename _T>
struct NodeDLXX
{
    _T *data;
    NodeDLXX **_child_nodes;

    NodeDLXX();
    NodeDLXX(_T data = new _T(), NodeDLXX **_child_nodes = nullptr);

    virtual ~NodeDLXX();

    _T const &operator *() const;

    NodeDLXX &operator ++ ();
    NodeDLXX &operator -- ();

    NodeDLXX &operator [] (uint8_t);
    const NodeDLXX operator ++ (int);
    const NodeDLXX operator -- (int);

private:
    class Iterator
    {
    private:
        NodeDLXX<_T> *_cur_node;

    public:
        Iterator(NodeDLXX<_T> *);
        void insert(NodeDLXX<_T>*);
        void remove();

        Iterator & operator = (const Iterator &);

        _T operator * () const;

        void operator ++ ();
        void operator -- ();

        const Iterator operator ++ (int);
        const Iterator operator -- (int);

        bool operator == (const Iterator &) const;
        bool operator != (const Iterator &) const;
    };

    Iterator _iter;
};

template<typename _T>
NodeDLXX<_T>::NodeDLXX():
    data(_T()),
    _child_nodes(nullptr),
    _iter(nullptr) {}

template<typename _T>
NodeDLXX<_T>::NodeDLXX(_T data, NodeDLXX<_T> **_child_node) :
    data(new _T(data)),
    _child_nodes(_child_node),
    _iter(*_child_node) {}

template<typename _T>
NodeDLXX<_T>::Iterator::Iterator(NodeDLXX<_T> *node):
    _cur_node(node) {}

template<typename _T>
_T const &NodeDLXX<_T>::operator *() const { return *this->data; }

template<typename _T>
NodeDLXX<_T> &NodeDLXX<_T>::operator ++() { return ++_iter; }

template<typename _T>
NodeDLXX<_T> &NodeDLXX<_T>::operator --() { return --_iter; }

template<typename _T>
NodeDLXX<_T> &NodeDLXX<_T>::operator [](uint8_t) {}

template<typename _T>
const NodeDLXX<_T> NodeDLXX<_T>::operator ++(int) {}

template<typename _T>
const NodeDLXX<_T> NodeDLXX<_T>::operator --(int) {}

template<typename _T>
bool NodeDLXX<_T>::Iterator::operator == (const Iterator &other) const
{
    if(this == &other){ return true; }
    return (operator * () == *other);
}

template<typename _T>
bool NodeDLXX<_T>::Iterator::operator != (const Iterator &other) const
{
    return !(operator == (other));
}

template<typename _T>
_T NodeDLXX<_T>::Iterator::operator * () const
{
    if(_cur_node)
    {
        return **_cur_node;
    }
    return _T();
}

template<typename _T>
void NodeDLXX<_T>::Iterator::operator ++ ()
{
    if(_cur_node)
    {
        _cur_node = ++_cur_node;
    }
}

template<typename _T>
void NodeDLXX<_T>::Iterator::operator -- ()
{
    if(_cur_node)
    {
        _cur_node = --_cur_node;
    }
}

template<typename _T>
const typename NodeDLXX<_T>::Iterator NodeDLXX<_T>::Iterator::operator ++ (int)
{
    if(_cur_node)
    {
        typename NodeDLXX<_T>::Iterator tmp = this;
        _cur_node = --_cur_node;
        return tmp;
    }
}

template<typename _T>
const typename NodeDLXX<_T>::Iterator NodeDLXX<_T>::Iterator::operator -- (int)
{
    if(_cur_node)
    {
        typename NodeDLXX<_T>::Iterator tmp = this;
        _cur_node = --_cur_node;
        return tmp;
    }
}

template<typename _T>
NodeDLXX<_T>::~NodeDLXX()
{
    delete data;
    delete []_child_nodes;
    data = nullptr;
    _child_nodes = nullptr;
}

#include "_node_dlxx.tpp"

#endif // NodeDLXX_HPP
