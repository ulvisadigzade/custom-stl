#include "Vector.hpp"

Vector::Vector(const int size) :
    size_(size),
    capacity(size),
    ptr(new int[size]())
{}

Vector::Vector(const int size, const int value) :
    size_(size),
    capacity(size),
    ptr(new int[size])
{
    for (int i = 0; i < size; i++)
        ptr[i] = value;
}

Vector::~Vector() {
    delete[] ptr;
}

int& Vector::operator[](int index)
{
    return ptr[index];
}

void Vector::push_back(int value) {
    if (capacity == 0) {
        capacity = 1;
        ptr = new int[capacity];
    }else if (size_ == capacity) {
        extendArray();
    }

    ptr[size_++] = value;
}

void Vector::extendArray() {
    capacity *= 2;
    int* newPtr = new int[capacity];
    for (int i = 0; i < size_; i++) {
        newPtr[i] = ptr[i];
    }
    delete[] ptr;
    ptr = newPtr;
}

int Vector::size() const {
    return size_;
}