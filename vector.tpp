#include "vector.h"

template <typename T>
Vector<T>::Vector(size_t init_capacity) : size(0), capacity(init_capacity) {
    data = new T[capacity];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
T& Vector<T>::at(size_t index) {
    if (index>=size){
        throw std::out_of_range("Index out of range");
    }
    else {
        return data[index];
    }
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return data[index];
}

template <typename T>
T& Vector<T>::front() {
    return data[0];
}

template <typename T>
T& Vector<T>::back() {
    return data[size-1];
}