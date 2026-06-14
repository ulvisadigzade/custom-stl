#pragma once
#include <cstddef>

//TODO: invariants enforcing
class Vector {
public:
    Vector() = default;
    Vector(size_t size);
    Vector(size_t size, int value);
    Vector(const Vector& other);
    ~Vector();
    Vector& operator=(const Vector& other);
    int& operator[](std::size_t index);
    const int& operator[](std::size_t index) const;
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;
    void push_back(int value);
    void pop_back();
    std::size_t size() const;
    std::size_t capacity() const;
    const int& back() const;
    const int& front() const;
    int& back();
    int& front();
    bool empty() const;
    void reserve(std::size_t capacity);
    void shrink_to_fit();
    const int* begin() const;
    const int* end() const;
    int* begin();
    int* end();
    void clear();
    void resize(std::size_t newSize);
    void insert(int* pos, int value);
    void erase(int* pos);
    void assign(std::size_t count, int value);
    void swap(Vector& other);
private:
    std::size_t size_{0};
    std::size_t capacity_{0};
    int* data_{nullptr};//what is this
};