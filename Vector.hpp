#pragma once


class Vector {
public:
    Vector() = default;
    Vector(int size);
    Vector(int size, int value);
    ~Vector();
    int& operator[](int index);
    void push_back(int value);
    void pop_back();
    int size() const;
    int back() const;
private:
    int size_{0};
    int capacity_{0};
    int* data_{nullptr};//what is this
    void extendArray();
};