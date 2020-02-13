#ifndef LIST_H
#define LIST_H

#include "utils/_node_dll.hpp"

template<typename T>
class List
{
private:
    NodeDLL<T> *_front;
    NodeDLL<T> *_back;
    uint32_t _len;

public:
    class Iterator
    {
    private:
        friend class List;
        NodeDLL<T> *_cur_node;

    public:
        Iterator(NodeDLL<T> *);
        void insert(NodeDLL<T>*);
        void remove();

        Iterator & operator = (const Iterator& r);

        T operator * () const;

        void operator ++ ();
        void operator -- ();

        const Iterator operator ++ (int);
        const Iterator operator -- (int);

        bool operator == (const Iterator &) const;
        bool operator != (const Iterator &) const;
    };
    List();
    ~List();

    Iterator begin() const;
    Iterator end() const;

    T get_item(uint32_t) const;
    T get_front() const;
    T get_back() const;

    T pop_item(uint32_t i = 0);
    T pop_front();
    T pop_back();

    void push_item(T, uint32_t);
    void push_front(T);
    void push_back(T);

    void reverse();
    uint32_t length();
    bool empty();

};

template<typename T>
typename List<T>::Iterator & List<T>::Iterator::operator = (const List<T>::Iterator& r) 
{
    return Iterator(r._cur_node);
}

template<typename T>
const typename List<T>::Iterator List<T>::Iterator::operator ++ (int) 
{
    if(_cur_node)
    {
        typename List<T>::Iterator tmp = this;
        _cur_node = _cur_node->next;
        return tmp;
    }
}

template<typename T>
const typename List<T>::Iterator List<T>::Iterator::operator -- (int) 
{
    if(_cur_node)
    {
        typename List<T>::Iterator tmp = this;
        _cur_node = _cur_node->back;
        return tmp;
    }
}

template<typename T>
typename List<T>::Iterator List<T>::begin() const 
{
    return Iterator(_front);
}
template<typename T>
typename List<T>::Iterator List<T>::end() const 
{
    return Iterator(_back);
}

template<typename T>
List<T>::List():
    _front(nullptr),
    _back(nullptr),
    _len(0) {}

template<typename T>
List<T>::Iterator::Iterator(NodeDLL<T> *node):
    _cur_node(node) {}

template<typename T>
bool List<T>::Iterator::operator == (const Iterator &other) const 
{
    if(this == &other)
    {
        return true;
    }
    return (operator * () == *other);
}

template<typename T>
bool List<T>::Iterator::operator != (const Iterator &other) const 
{
    return !(operator == (other));
}

template<typename T>
T List<T>::Iterator::operator * () const 
{
    if(_cur_node) { return **_cur_node; }
    return T();
}

template<typename T>
void List<T>::Iterator::operator ++ () 
{
    if(_cur_node)
    {
        _cur_node = _cur_node->next;
    }
}

template<typename T>
void List<T>::Iterator::operator -- () 
{
    if(_cur_node)
    {
        _cur_node = _cur_node->prev;
    }
}

template<typename T>
void List<T>::Iterator::insert(NodeDLL<T> *_node) 
{
    _cur_node->prev->next = _node;
    _node->next = _cur_node;
    _node->prev = _cur_node->prev;
    _cur_node->prev = _node;
}

template<typename T>
void List<T>::Iterator::remove() 
{
    _cur_node->prev->next = _cur_node->next;
    _cur_node->next->prev = _cur_node->prev;
    delete _cur_node;
}

template<typename T>
List<T>::~List()
{
    while(_front) { pop_front(); }
}

template<typename T>
T List<T>::get_front() const { return **_front; }

template<typename T>
T List<T>::get_back() const { return **_back; }

template<typename T>
T List<T>::get_item(uint32_t i) const
{
    if (i < _len + 1)
    {
        if (i == 0) { return get_front(); }
        if (i == _len) { return get_back(); }

        uint32_t _index = 0;
        for(Iterator it = begin(); it != nullptr; ++it)
        {
            if (_index == i) { return *it; }
            _index++;
        }
    }
}

template<typename T>
T List<T>::pop_back()
{
    if (!empty())
    {
        auto tmp = _back;
        _back = tmp->prev;
        if (_back) _back->next = nullptr;
        T __r = T(**tmp);
        delete tmp;
        _len--;
        return __r;
    }
    else { return T(); }
}

template<typename T>
T List<T>::pop_front()
{
    if (!empty())
    {
        auto tmp = _front;
        _front = tmp->next;
        if (_front) _front->prev = nullptr;
        T __r = T(**tmp);
        delete tmp;
        _len--;
        return __r;
    }
    else { return T(); }
}

template<typename T>
T List<T>::pop_item(uint32_t i)
{
    if (i < _len)
    {
        if (i == 0) { return pop_front(); }

        uint32_t _index = 0;
        for(Iterator it = begin(); it != nullptr; ++it)
        {
            if (_index == i)
            {
                auto tmp = *it;
                it.remove();
                return tmp;
            }
            _index++;
        }
        _len--;
    }
    else { return pop_back(); }
}

template<typename T>
void List<T>::push_front(T data)
{
    if (empty())
    {
        _front = new NodeDLL<T>(data);
        _back = _front;
    }
    else
    {
        auto tmp = _front;
        _front = new NodeDLL<T>(data, nullptr, tmp);
        tmp->prev = _front;
    }
    _len++;
}

template<typename T>
void List<T>::push_back(T data)
{
    if (empty())
    {
        _back = new NodeDLL<T>(data);
        _front = _back;
    }
    else
    {
        auto tmp = _back;
        _back = new NodeDLL<T>(data, tmp);
        tmp->next = _back;
    }
    _len++;
}

template<typename T>
void List<T>::push_item(T data, uint32_t i)
{
    if (i < _len + 1)
    {
        if (i == 0)
        {
            push_front(data);
            return;
        }
        if (i == _len)
        {
            push_back(data);
            return;
        }
        auto tmp = new NodeDLL<T>(data);
        uint32_t _index = 0;
        for(Iterator it = begin(); it != nullptr; ++it)
        {
            if (_index == i)
            {
                it.insert(tmp);
                break;
            }
            _index++;
        }
        _len++;
    }
}

template<typename T>
void List<T>::reverse() {
    for(Iterator it = begin(); it != nullptr; --it)
    {
        it._cur_node->swap_direction();
    }
    auto tmp = _front;
    _front = _back;
    _back = tmp;
}

template<typename T>
bool List<T>::empty() { return (_len != 0 ? false : true); }

template<typename T>
uint32_t List<T>::length() { return _len; }

#include "list.tpp"

#endif // LIST_H
