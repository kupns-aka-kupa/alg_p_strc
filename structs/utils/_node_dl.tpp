
template<typename _T>
NodeDL<_T>::NodeDL():
    NodeDLXX<_T>()
{}

template<typename _T>
NodeDL<_T>::NodeDL(_T data, NodeDL<_T> *next) :
    NodeDLXX<_T>(data, new NodeDLXX<_T> *{ dynamic_cast<NodeDLXX<_T> *>(next) }),
    next(next)
{}

template<typename _T>
NodeDL<_T>::~NodeDL()
{
    next = nullptr;
}
