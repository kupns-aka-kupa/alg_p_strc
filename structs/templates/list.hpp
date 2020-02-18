#ifndef LISTLL_H
#define LISTLL_H

#include <sstream>
#include "../node/_node_dll.hpp"

template<typename T>
class ListL
{
protected:

};

template<typename T>
class ListLL : public ListL<T>
{
private:
    NodeDLL<T> *front;
    NodeDLL<T> *back;

public:
    class Iterator
    {
    private:
        friend class ListLL;
        NodeDLL<T> *current;

    public:
        Iterator(NodeDLL<T> *);
        void insert(NodeDLL<T>*);
        void remove();

        Iterator &operator = (const Iterator& r);

        T operator * () const;

        void operator ++ ();
        void operator -- ();

        const Iterator operator ++ (int);
        const Iterator operator -- (int);

        bool operator == (const Iterator &) const;
        bool operator != (const Iterator &) const;
    };

    ListLL();

    template<typename... Args>
    ListLL(Args... args) : ListLL()
    {
        uint32_t l = sizeof... (Args);
        T items [l] { static_cast<T>(args)... };
        for(uint32_t i = 0; i < l; i++)
        {
            push_back(items[i]);
        }
    }

    ~ListLL();

    Iterator begin();
    Iterator end();

    std::string to_str();
    void print();

    T get_item(uint32_t);
    T get_front();
    T get_back();

    T pop_item(uint32_t i = -1);
    T pop_front();
    T pop_back();

    void push_item(T, uint32_t);
    void push_front(T);
    void push_back(T);

    void reverse();
    uint32_t len();
    bool empty();

};

template<typename T>
ListLL<T>::Iterator::Iterator(NodeDLL<T> *node):
    current(node) {}


template<typename T>
void ListLL<T>::Iterator::insert(NodeDLL<T> *_node)
{
    current->prev->next = _node;
    _node->next = current;
    _node->prev = current->prev;
    current->prev = _node;
}

template<typename T>
void ListLL<T>::Iterator::remove()
{
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
}

template<typename T>
bool ListLL<T>::Iterator::operator == (const Iterator &other) const
{
    if(this == &other)
    {
        return true;
    }
    return (operator * () == *other);
}

template<typename T>
bool ListLL<T>::Iterator::operator != (const Iterator &other) const
{
    return !(operator == (other));
}

template<typename T>
T ListLL<T>::Iterator::operator * () const
{
    if(current) { return **current; }
    return T();
}

template<typename T>
void ListLL<T>::Iterator::operator ++ ()
{
    if(current)
    {
        current = current->next;
    }
}

template<typename T>
void ListLL<T>::Iterator::operator -- ()
{
    if(current)
    {
        current = current->prev;
    }
}

template<typename T>
typename ListLL<T>::Iterator & ListLL<T>::Iterator::operator = (const ListLL<T>::Iterator& r)
{
    return Iterator(r.current);
}

template<typename T>
const typename ListLL<T>::Iterator ListLL<T>::Iterator::operator ++ (int)
{
    if(current)
    {
        typename ListLL<T>::Iterator tmp = this;
        current = current->next;
        return tmp;
    }
}

template<typename T>
const typename ListLL<T>::Iterator ListLL<T>::Iterator::operator -- (int)
{
    if(current)
    {
        typename ListLL<T>::Iterator tmp = this;
        current = current->back;
        return tmp;
    }
}

template<typename T>
typename ListLL<T>::Iterator ListLL<T>::begin()
{
    return Iterator(front);
}
template<typename T>
typename ListLL<T>::Iterator ListLL<T>::end()
{
    return nullptr;
}

template<typename T>
ListLL<T>::ListLL():
    front(nullptr),
    back(nullptr){}

template<typename T>
std::string ListLL<T>::to_str()
{
    std::ostringstream strs;
    strs  << "[";
    for(Iterator it = begin(); it != end(); ++it)
    {
        if(it != begin() && it != end()) strs << ", ";
        strs << *it;
    }
    strs << "]";
    return strs.str();
}

template<typename T>
void ListLL<T>::print() { std::cout << to_str(); }

template<typename T>
ListLL<T>::~ListLL()
{
    while(front) { pop_front(); }
}

template<typename T>
T ListLL<T>::get_front() { return **front; }

template<typename T>
T ListLL<T>::get_back() { return **back; }

template<typename T>
T ListLL<T>::get_item(uint32_t i)
{
    uint32_t _len = len();
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
T ListLL<T>::pop_back()
{
    if (!empty())
    {
        auto tmp = back;
        back = tmp->prev;
        if (back) back->next = nullptr;
        T __r = T(**tmp);
        delete tmp;
        return __r;
    }
    else { return T(); }
}

template<typename T>
T ListLL<T>::pop_front()
{
    if (!empty())
    {
        auto tmp = front;
        front = tmp->next;
        if (front) front->prev = nullptr;
        T __r = T(**tmp);
        delete tmp;
        return __r;
    }
    else { return T(); }
}

template<typename T>
T ListLL<T>::pop_item(uint32_t i)
{
    uint32_t _len = len();
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
    }
    else { return pop_back(); }
}

template<typename T>
void ListLL<T>::push_front(T data)
{
    if (empty())
    {
        front = new NodeDLL<T>(data);
        back = front;
    }
    else
    {
        auto tmp = front;
        front = new NodeDLL<T>(data, nullptr, tmp);
        tmp->prev = front;
    }
}

template<typename T>
void ListLL<T>::push_back(T data)
{
    if (empty())
    {
        back = new NodeDLL<T>(data);
        front = back;
    }
    else
    {
        auto tmp = back;
        back = new NodeDLL<T>(data, tmp);
        tmp->next = back;
    }
}

template<typename T>
void ListLL<T>::push_item(T data, uint32_t i)
{
    if (i < len() + 1)
    {
        if (i == 0)
        {
            push_front(data);
            return;
        }
        if (i == len())
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
    }
}

template<typename T>
void ListLL<T>::reverse()
{
    if (!empty())
    {
        for(Iterator it = begin(); it != nullptr; --it)
        {
            it.current->swap_direction();
        }
        auto tmp = front;
        front = back;
        back = tmp;
    }
}

template<typename T>
bool ListLL<T>::empty() { return (len() != 0 ? false : true); }

template<typename T>
uint32_t ListLL<T>::len()
{
    uint32_t len = 0;
    for(Iterator it = begin(); it != end(); ++it)
    {
        len++;
    }
    return len;
}


#endif // LISTLL_H
