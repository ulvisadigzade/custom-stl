#pragma once

//TODO: invariants enforcing
class Vector {
public:
    Vector() = default;
    Vector(int size);
    Vector(int size, int value);
    Vector(const Vector& other);
    ~Vector();
    Vector& operator=(const Vector& other);
    int& operator[](int index);
    void push_back(int value);
    void pop_back();
    int size() const;
    int capacity() const;
    int back() const;
    bool empty() const;
    void reserve(int capacity);
    void shrink_to_fit();
    int* begin() const;
    int* end() const;
private:
    int size_{0};
    int capacity_{0};
    int* data_{nullptr};//what is this
};