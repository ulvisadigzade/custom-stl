#include "Vector.hpp"

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
    if (size_ == capacity_) {
        reserve(capacity_ == 0 ? 1 : capacity_ * 2);
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
        return 0; //temporary invalid fallback
    }
    return data_[size_ - 1];
}

int Vector::size() const {
    return size_;
}

int Vector::capacity() const {
    return capacity_;
}

bool Vector::empty() const {
    return size_ == 0;
}

void Vector::reserve(int capacity) {
    if (capacity <= capacity_)
        return;

    int* newData = new int[capacity];

    for (int i=0;i<size_;i++) {
        newData[i] = data_[i];
    }
    delete[] data_;
    data_ = newData;
    capacity_ = capacity;
}

void Vector::shrink_to_fit() {
    if (capacity_ == size_)
        return;

    if (size_ == 0) {
        delete[] data_;
        data_ = nullptr;
        capacity_ = 0;
        return;
    }

    int* newData = new int[size_];
    for (int i=0;i<size_;i++) {
        newData[i] = data_[i];
    }
    delete[] data_;
    data_ = newData;
    capacity_ = size_;
}