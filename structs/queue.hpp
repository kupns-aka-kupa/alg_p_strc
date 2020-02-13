#ifndef QUEUE_H
#define QUEUE_H

#include "utils/_node_dl.hpp"

template<typename T>
class Queue
{
private:
    NodeDL<T> *_head;
    NodeDL<T> *_tail;
    uint32_t _len;

public:
    Queue();
    ~Queue();

    T head();
    T tail();
    T pop();

    void push(T);
    bool empty();

};

#include "queue.tpp"

#endif // QUEUE_H
