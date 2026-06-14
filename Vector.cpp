#include <stdexcept>

#include "Vector.hpp"

Vector::Vector(const std::size_t size) :
    size_(size),
    capacity_(size),
    data_(size == 0 ? nullptr : new int[size]())
{}

Vector::Vector(const std::size_t size, const int value) :
    size_(size),
    capacity_(size),
    data_(size == 0 ? nullptr : new int[size])
{
    for (std::size_t i = 0; i < size; i++)
        data_[i] = value;
}

Vector::Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
    if (other.data_ == nullptr) {
        data_ = nullptr;
    }
    else {
        data_ = new int[capacity_];

        for (std::size_t i = 0; i < size_; i++) {
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

        for (std::size_t i = 0; i < other.size_; i++)
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

int& Vector::operator[](std::size_t index)
{
    return data_[index];
}

const int& Vector::operator[](std::size_t index) const {
    return data_[index];
}

bool Vector::operator==(const Vector& other) const {
    if (size_ != other.size_) return false;

    if (this == &other) return true;

    for (std::size_t i = 0; i < size_; i++) {
        if (data_[i] != other.data_[i]) return false;
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
        throw std::out_of_range("pop_back() called on empty vector");
    }
    size_--;
}

const int& Vector::back() const {
    if (size_ == 0) {
        throw std::out_of_range("back() called on empty vector");
    }
    return data_[size_ - 1];
}

const int& Vector::front() const {
    if (size_ == 0) {
        throw std::out_of_range("front() called on empty vector");
    }
    return data_[0];
}

int& Vector::back() {
    if (size_ == 0) {
        throw std::out_of_range("back() called on empty vector");
    }
    return data_[size_ - 1];
}

int& Vector::front() {
    if (size_ == 0) {
        throw std::out_of_range("front() called on empty vector");
    }
    return data_[0];
}

std::size_t Vector::size() const {
    return size_;
}

std::size_t Vector::capacity() const {
    return capacity_;
}

bool Vector::empty() const {
    return size_ == 0;
}

void Vector::reserve(std::size_t capacity) {
    if (capacity <= capacity_)
        return;

    int* newData = new int[capacity];

    for (std::size_t i = 0; i < size_; i++) {
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
    for (std::size_t i = 0; i < size_; i++) {
        newData[i] = data_[i];
    }
    delete[] data_;
    data_ = newData;
    capacity_ = size_;
}

const int* Vector::begin() const {
    return data_;
}

const int* Vector::end() const {
    return data_ + size_;
}

int* Vector::begin() {
    return data_;
}

int* Vector::end() {
    return data_ + size_;
}

void Vector::clear() {
    size_ = 0;
}

void Vector::resize(std::size_t newSize) {
    if (newSize <= size_) {
        size_ = newSize;
        return;
    }

    if (newSize > capacity_)
        reserve(newSize);

    for (std::size_t i = size_; i < newSize; ++i)
        data_[i] = 0;

    size_ = newSize;
}

void Vector::insert(int* pos, int value) {
    if (pos < data_ || pos > data_ + size_) {
        throw std::out_of_range("Position is out of range of vector");
    }

    std::size_t index = pos - data_;

    if (size_ == capacity_) {
        reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }

    pos = data_ + index;

    for (int* i = data_ + size_; i != pos; --i) {
        *i = *(i - 1);
    }

    *pos = value;
    ++size_;
}

void Vector::erase(int* pos) {
    if (pos < data_ || pos >= data_ + size_) {
        throw std::out_of_range("Position is out of range of vector");
    }

    for (auto i = pos; i < data_ + size_ - 1; i++) {
        *i = *(i + 1);
    }
    --size_;
}

void Vector::assign(std::size_t count, int value) {
    if (count <= capacity_) {
        size_ = count;
        for (std::size_t i = 0; i < size_; i++)
            data_[i] = value;
        return;
    }

    reserve(count);
    for (std::size_t i = 0; i < count; ++i)
        data_[i] = value;
    size_ = count;
}

void Vector::swap(Vector &other) {
    int* tmpData = data_;
    data_ = other.data_;
    other.data_ = tmpData;

    std::size_t tmpSize = size_;
    size_ = other.size_;
    other.size_ = tmpSize;

    std::size_t tmpCap = capacity_;
    capacity_ = other.capacity_;
    other.capacity_ = tmpCap;
}