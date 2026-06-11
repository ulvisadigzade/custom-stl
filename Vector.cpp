#include "Vector.hpp"

#include <stdlib.h>

Vector::Vector(const int size) :
    size_(size),
    capacity_(size),
    data_(new int[size]())
{}

Vector::Vector(const int size, const int value) :
    size_(size),
    capacity_(size),
    data_(new int[size])
{
    for (int i = 0; i < size; i++)
        data_[i] = value;
}

Vector::~Vector() {
    delete[] data_;
}

int& Vector::operator[](int index)
{
    return data_[index];
}

void Vector::push_back(int value) {
    if (capacity_ == 0) {
        capacity_ = 1;
        data_ = new int[capacity_];
    }else if (size_ == capacity_) {
        extendArray();
    }

    data_[size_++] = value;
}

void Vector::pop_back() {
    if (size_ == 0) {
        //TODO: throw
        return;
    }
    size_--;
}

int Vector::back() const {
    if (size_ == 0) {
        //TODO: throw
        return NULL;
    }
    return data_[size_ - 1];
}

void Vector::extendArray() {
    capacity_ *= 2;
    int* newPtr = new int[capacity_];
    for (int i = 0; i < size_; i++) {
        newPtr[i] = data_[i];
    }
    delete[] data_;
    data_ = newPtr;
}

int Vector::size() const {
    return size_;
}