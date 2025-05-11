#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;
public:
    Vector(size_t init_capacity);
    ~Vector();
    operator= (const Vector& other);
    T& at(size_t index);
    T& operator[](size_t index);
    T& front();
    T& back();
    T* begin(T value);
    T* end(T value);
    T* rbegin(T value);
    T* rend(T value);
    bool empty() const;
    size_t size() const;
    size_t max_size() const;
    void reserve(size_t new_capacity);
    size_t capacity() const;
    void shrink_to_fit();
    void clear();
    void insert(size_t index, const T& value);
    void erase(size_t index);
    void emplace(size_t index, const T& value);
    void push_back(const T& value);
    void emplace_back(const T& value);
    void pop_back();
    void resize(size_t new_size);
    void swap(Vector& other);
    operator== (const Vector& other) const;
    operator!= (const Vector& other) const;
    operator< (const Vector& other) const;
    operator<= (const Vector& other) const;
    operator> (const Vector& other) const;
    operator>= (const Vector& other) const;
};

#endif