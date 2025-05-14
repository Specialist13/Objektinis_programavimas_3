#include "../include/vector.h"

template <typename T>
Vector<T>::Vector(size_t init_capacity) : size(0), capacity(init_capacity) {
    data = new T[capacity];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
Vector<T>::Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
    data = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
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
Vector<T>::Vector(Vector&& other) noexcept : data(other.data), size(other.size), capacity(other.capacity) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

template <typename T>
void Vector<T>::assign(size_t count, const T& value) {
    if (count > capacity) {
        delete[] data;
        capacity = count;
        data = new T[capacity];
    }
    size = count;
    for (size_t i = 0; i < size; ++i) {
        data[i] = value;
    }
}

template <typename T>
void Vector<T>::assign(const T* first, const T* last) {
    size_t count = last - first;
    if (count > capacity) {
        delete[] data;
        capacity = count;
        data = new T[capacity];
    }
    size = count;
    for (size_t i = 0; i < size; ++i) {
        data[i] = first[i];
    }
}

template <typename T>
void Vector<T>::assign(const Vector& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
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
T* Vector<T>::getData() {
    return data;
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
    return size ? data + size - 1 : data;
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
    if (new_capacity!=capacity){
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
        reserve(size);
    }
}

template <typename T>
void Vector<T>::clear() {
    size=0;
}

template <typename T>
void Vector<T>::insert(size_t index, const T& value){
    if (index>size) throw std::out_of_range("Insert position out of range");
    if (size==capacity) reserve(capacity==0 ? 1 : capacity*2);
    for (size_t i=size; i>index; i--){
        data[i]=data[i-1];
    }
    data[index]=value;
    size++;
}

template <typename T>
void Vector<T>::erase(size_t index) {
    if (index>=size) throw std::out_of_range("Erase position out of range");
    for (size_t i=index; i<size-1; i++){
        data[i]=data[i+1];
    }
    data[size-1].~T();
    size--;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size==capacity) reserve(capacity==0 ? 1 : capacity*2);
    data[size++]=value;
}

template <typename T>
template <typename Range>
void Vector<T>::append_range(const Range& other) {
    for (const auto& item : other) {
        if (size >= capacity)
            reserve(capacity == 0 ? 1 : capacity * 2);
        data[size++] = item;
    }
}

template <typename T>
void Vector<T>::pop_back() {
    if (size > 0) {
        data[size - 1].~T();
        size--;
    }
}

template <typename T>
void Vector<T>::resize(size_t new_size) {
    if (new_size > capacity) {
        reserve(new_size);
    }
    for (size_t i = size; i < new_size; i++) {
        data[i] = T();
    }
    for (size_t i = new_size; i < size; i++) {
        data[i].~T();
    }
    size = new_size;
}

template <typename T>
void Vector<T>::swap(Vector& other) {
    std::swap(data, other.data);
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);
}

template <typename T>
bool Vector<T>::operator==(const Vector& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; i++) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector& other) const {
    return !(*this == other);
}

template <typename T>
bool Vector<T>::operator<(const Vector& other) const {
    size_t min_size = std::min(size, other.size);
    for (size_t i = 0; i < min_size; i++) {
        if (data[i] < other.data[i]) return true;
        if (data[i] > other.data[i]) return false;
    }
    return size < other.size;
}

template <typename T>
bool Vector<T>::operator<=(const Vector& other) const {
    return *this < other || *this == other;
}

template <typename T>
bool Vector<T>::operator>(const Vector& other) const {
    return !(*this <= other);
}

template <typename T>
bool Vector<T>::operator>=(const Vector& other) const {
    return !(*this < other);
}