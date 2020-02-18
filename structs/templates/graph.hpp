#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "list.hpp"
#include <map>

template<typename T>
class Graph
{
private:
    std::map<std::string, ListLL<Node<T>*>> matrix;

public:
    Graph();
};

template<typename T>
Graph<T>::Graph()
{

}

template<typename T>
class OrientedGraph : Graph<T>
{
public:
    OrientedGraph();
};


template<typename T>
class NonOrientedGraph : Graph<T>
{
public:
    NonOrientedGraph();
};


#endif // GRAPH_HPP
