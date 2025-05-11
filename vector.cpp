#include "vector.h"

template <typename T>
Vector<T>::Vector(size_t init_capacity=10) : size(0), capacity(init_capacity) {
    data = new T[capacity];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

