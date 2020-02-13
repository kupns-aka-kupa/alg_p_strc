template<typename T>
Queue<T>::Queue():
    _head(nullptr),
    _tail(nullptr),
    _len(0)
{}

template<typename T>
Queue<T>::~Queue()
{
    while(_head)
    {
        pop();
    }
}

template<typename T>
void Queue<T>::push(T data)
{
    if (empty())
    {
        _head = new NodeDL<T>(data);
        _tail = _head;
    }
    else
    {
        auto tmp = _tail;
        _tail = new NodeDL<T>(data);
        tmp->next = _tail;
    }
    if (_len == 1)
    {
        _head->next = _tail;
    }
    _len++;
}

template<typename T>
T Queue<T>::pop()
{
    if (!empty())
    {
        _len--;
        auto tmp = _head;
        _head = _head->next;
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
T Queue<T>::head()
{
    return T(**_head);
}

template<typename T>
T Queue<T>::tail()
{
    return T(**_tail);
}

template<typename T>
bool Queue<T>::empty()
{
    return (_len != 0 ? false : true);
}
