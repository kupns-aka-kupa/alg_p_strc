
template<typename _K, typename _T>
NodeKDLXX<_K, _T>::NodeKDLXX():
    NodeDLXX<_T>(),
    key(nullptr)
{}

template<typename _K, typename _T>
NodeKDLXX<_K, _T>::NodeKDLXX(_K key, _T data, NodeKDLXX **_next_sub_node) :
    NodeDLXX<_T>(data, dynamic_cast<NodeDLXX<_T> **>(_next_sub_node)),
    key(key)
{}

template<typename _K, typename _T>
NodeKDLXX<_K, _T>::~NodeKDLXX()
{
    delete key;
    key = nullptr;
}
