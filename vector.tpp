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

template <typename T>
T* Vector<T>::begin() {
    return data;
}

template <typename T>
T* Vector<T>::end() {
    return data+size;
}

template <typename T>
T* Vector<T>::rbegin() {
    return data+size-1;
}

template <typename T>
T* Vector<T>::rend() {
    return data-1;
}

template <typename T>
bool Vector<T>::empty() const {
    return size==0;
}

template <typename T>
size_t Vector<T>::getSize() const {
    return size;
}

template <typename T>
size_t Vector<T>::max_size() const {
    return std::numeric_limits<size_t>::max() / sizeof(T);;
}

template <typename T>
void Vector<T>::reserve(size_t new_capacity) {
    if (new_capacity>capacity){
        T* temp_data=new T[new_capacity];
        for (size_t i=0; i<size; i++){
            temp_data[i]=data[i];
        }
        delete[] data;
        capacity=new_capacity;
        data=temp_data;
    }
}

template <typename T>
size_t Vector<T>::getCapacity() const {
    return capacity;
}

template <typename T>
void Vector<T>::shrink_to_fit() {
    if (capacity>size){
        resize(size);
    }
}

template <typename T>
void Vector<T>::clear() {
    for (size_t i=0; i<size; i++){
        data[i].~T();
    }
    size=0;
}