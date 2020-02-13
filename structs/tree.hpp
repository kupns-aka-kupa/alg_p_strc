#ifndef TREE_HPP
#define TREE_HPP

#include "utils/_node_kdll.hpp"

template<typename K, typename T>
class Tree
{
private:
    NodeKDLL<K, T> *_root;

    union
    {
        NodeKDLL<K, T> *_l_leaf;
        NodeKDLL<K, T> *_r_leaf;
        uint32_t _depth;
        uint32_t _width;
    };

public:
    Tree();
    ~Tree();

    void add(K, T);
    T get_item(K);
    T pop_item(K);
    T min();
    T max();
    void clear_all();

};

template<typename K, typename T>
Tree<K, T>::Tree():
    _root(nullptr),
    _l_leaf(nullptr)
{}

template<typename K, typename T>
Tree<K, T>::~Tree()
{}

#include "tree.hpp"

#endif // TREE_HPP
