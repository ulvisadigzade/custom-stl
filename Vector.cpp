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

Vector::Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
    if (other.data_ == nullptr) {
        data_ = nullptr;
    }
    else {
        data_ = new int[capacity_];

        for (int i=0;i<size_;i++) {
            data_[i] = other.data_[i];
        }
    }
}

Vector& Vector::operator=(const Vector &other) {
    if (this == &other)
        return *this;

    int* newData = nullptr;

    if (other.data_ != nullptr) {
        newData = new int[other.capacity_];

        for (int i=0;i<other.size_;i++)
            newData[i] = other.data_[i];
    }
    delete[] data_;

    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = newData;
    return *this;
}

Vector::~Vector() {
    delete[] data_;
}

int& Vector::operator[](int index)
{
    return data_[index];
}

const int& Vector::operator[](int index) const {
    return data_[index];
}

bool Vector::operator==(const Vector& other) const {
    if (size_ != other.size_)return false;

    if (this == &other) return true;

    for (int i=0;i<size_;i++) {
        if (data_[i] != other.data_[i])return false;
    }
    return true;
}

bool Vector::operator!=(const Vector& other) const {
    return !(*this == other);
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

int Vector::front() const {
    return data_[0];
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

int* Vector::begin() const {
    return data_;
}

int* Vector::end() const {
    return data_ + size_;
}

void Vector::clear() {
    size_ = 0;
}

void Vector::resize(int newSize) {
    if (newSize <= size_) {
        size_ = newSize;
        return;
    }

    if (newSize > capacity_)
        reserve(newSize);

    for (int i = size_; i < newSize; ++i)
        data_[i] = 0;

    size_ = newSize;
}