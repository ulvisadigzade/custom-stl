#pragma once


class Vector {
public:
    Vector() = default;
    Vector(int size);
    Vector(int size, int value);
    ~Vector();
    int& operator[](int index);
    void push_back(int value);
    int size() const;
private:
    int size_{0};
    int capacity{0};
    int* ptr{nullptr};//what is this
    void extendArray();
};