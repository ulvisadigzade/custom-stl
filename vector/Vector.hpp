#pragma once
#include <cstddef>

template <typename T>
class Vector {
public:
    Vector() = default;
    Vector(size_t size);
    Vector(size_t size, const T& value);
    Vector(const Vector& other);
    ~Vector();
    Vector& operator=(const Vector& other);
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;
    void push_back(const T& value);
    void pop_back();
    std::size_t size() const;
    std::size_t capacity() const;
    const T& back() const;
    const T& front() const;
    T& back();
    T& front();
    bool empty() const;
    void reserve(std::size_t capacity);
    void shrink_to_fit();
    const T* begin() const;
    const T* end() const;
    T* begin();
    T* end();
    void clear();
    void resize(std::size_t newSize);
    void insert(T* pos, const T& value);
    void erase(T* pos);
    void assign(std::size_t count, const T& value);
    void swap(Vector& other);
private:
    std::size_t size_{0};
    std::size_t capacity_{0};
    T* data_{nullptr};//what is this
};

#include "Vector.tpp"
