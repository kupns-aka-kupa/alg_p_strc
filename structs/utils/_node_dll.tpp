
template<typename _T>
NodeDLL<_T>::NodeDLL():
    NodeDLXX<_T>(),
    prev(nullptr),
    next(nullptr)
{}

template<typename _T>
NodeDLL<_T>::NodeDLL(_T data, NodeDLL<_T> *prev, NodeDLL<_T> *next) :
     NodeDLXX<_T>(data, new NodeDLXX<_T> *[2]{
         dynamic_cast< NodeDLXX<_T> *>(prev),
         dynamic_cast< NodeDLXX<_T> *>(next) }),
     prev(prev),
     next(next)
{}

template<typename _T>
NodeDLL<_T>::~NodeDLL()
{
    prev = nullptr;
    next = nullptr;
}
