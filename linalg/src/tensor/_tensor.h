#ifndef TENSOR_H
#define TENSOR_H

#include <stdint.h>

#define DEFUALT_TYPE int32_t

template<typename T = DEFUALT_TYPE>
class Tensor
{
protected:
    T *data;
    uint32_t dim;

public:
    Tensor() = default;
    Tensor(uint32_t d) = delete;
    Tensor(const Tensor<T> &) = delete;
    virtual ~Tensor() = default;
};

#endif // TENSOR_H
