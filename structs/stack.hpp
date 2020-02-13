#ifndef STACK_H
#define STACK_H

#include "utils/_node_dl.hpp"

template<typename T>
class Stack
{
private:
    NodeDL<T> *_top;
    uint32_t _size;

public:

    Stack();
    ~Stack();

    T top();
    T pop();
    void push(T);
    bool empty();

};

template<typename T>
Stack<T>::Stack():_top(nullptr), _size(0){}

template<typename T>
Stack<T>::~Stack()
{
    while(_top)
    {
        pop();
    }
}

template<typename T>
void Stack<T>::push(T data)
{
    _size++;
    auto tmp = _top;
    _top = new NodeDL<T>(data, tmp);
}

template<typename T>
T Stack<T>::pop()
{
    if (!empty())
    {
        _size--;
        auto tmp = _top;
        _top = _top->next;
        T __r = T(**tmp);
        delete  tmp;
        return __r;
    }
    else
    {
        return T();
    }
}

template<typename T>
T Stack<T>::top()
{
    return T(**_top);
}

template<typename T>
bool Stack<T>::empty()
{
    return (_size != 0 ? false : true);
}


#endif // STACK_H
