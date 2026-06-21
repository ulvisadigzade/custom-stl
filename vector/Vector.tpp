#pragma once
#include <stdexcept>

template <typename T>
Vector<T>::Vector(const std::size_t size) :
    size_(size),
    capacity_(size),
    data_(size == 0 ? nullptr : new T[size]())
{}

template <typename T>
Vector<T>::Vector(const std::size_t size, const T& value) :
    size_(size),
    capacity_(size),
    data_(size == 0 ? nullptr : new T[size])
{
    for (std::size_t i = 0; i < size; i++)
        data_[i] = value;
}

template <typename T>
Vector<T>::Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
    if (other.data_ == nullptr) {
        data_ = nullptr;
    }
    else {
        data_ = new T[capacity_];

        for (std::size_t i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }
}

template <typename T>
Vector<T>::Vector(Vector&& other) noexcept : size_(other.size_), capacity_(other.capacity_), data_(other.data_) {
    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector &other) {
    if (this == &other)
        return *this;

    T* newData = nullptr;

    if (other.data_ != nullptr) {
        newData = new T[other.capacity_];

        for (std::size_t i = 0; i < other.size_; i++)
            newData[i] = other.data_[i];
    }
    delete[] data_;

    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = newData;
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept{
    if (this == &other)
        return *this;

    delete[] data_;

    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = other.data_;

    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;
    return *this;
}


template <typename T>
Vector<T>::~Vector() {
    delete[] data_;
}

template <typename T>
T& Vector<T>::operator[](std::size_t index)
{
    return data_[index];
}

template <typename T>
const T& Vector<T>::operator[](std::size_t index) const {
    return data_[index];
}

template <typename T>
bool Vector<T>::operator==(const Vector& other) const {
    if (size_ != other.size_) return false;

    if (this == &other) return true;

    for (std::size_t i = 0; i < size_; i++) {
        if (data_[i] != other.data_[i]) return false;
    }
    return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector& other) const {
    return !(*this == other);
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size_ == capacity_) {
        reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    data_[size_++] = value;
}

template <typename T>
void Vector<T>::pop_back() {
    if (size_ == 0) {
        throw std::out_of_range("pop_back() called on empty vector");
    }
    size_--;
}

template <typename T>
const T& Vector<T>::back() const {
    if (size_ == 0) {
        throw std::out_of_range("back() called on empty vector");
    }
    return data_[size_ - 1];
}

template <typename T>
const T& Vector<T>::front() const {
    if (size_ == 0) {
        throw std::out_of_range("front() called on empty vector");
    }
    return data_[0];
}

template <typename T>
T& Vector<T>::back() {
    if (size_ == 0) {
        throw std::out_of_range("back() called on empty vector");
    }
    return data_[size_ - 1];
}

template <typename T>
T& Vector<T>::front() {
    if (size_ == 0) {
        throw std::out_of_range("front() called on empty vector");
    }
    return data_[0];
}

template <typename T>
std::size_t Vector<T>::size() const {
    return size_;
}

template <typename T>
std::size_t Vector<T>::capacity() const {
    return capacity_;
}

template <typename T>
bool Vector<T>::empty() const {
    return size_ == 0;
}

template <typename T>
void Vector<T>::reserve(std::size_t capacity) {
    if (capacity <= capacity_)
        return;

    T* newData = new T[capacity];

    for (std::size_t i = 0; i < size_; i++) {
        newData[i] = data_[i];
    }
    delete[] data_;
    data_ = newData;
    capacity_ = capacity;
}

template <typename T>
void Vector<T>::shrink_to_fit() {
    if (capacity_ == size_)
        return;

    if (size_ == 0) {
        delete[] data_;
        data_ = nullptr;
        capacity_ = 0;
        return;
    }

    T* newData = new T[size_];
    for (std::size_t i = 0; i < size_; i++) {
        newData[i] = data_[i];
    }
    delete[] data_;
    data_ = newData;
    capacity_ = size_;
}

template <typename T>
const T* Vector<T>::begin() const {
    return data_;
}

template <typename T>
const T* Vector<T>::end() const {
    return data_ + size_;
}

template <typename T>
T* Vector<T>::begin() {
    return data_;
}

template <typename T>
T* Vector<T>::end() {
    return data_ + size_;
}

template <typename T>
void Vector<T>::clear() {
    size_ = 0;
}

template <typename T>
void Vector<T>::resize(std::size_t newSize) {
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

template <typename T>
void Vector<T>::insert(T* pos, const T& value) {
    if (pos < data_ || pos > data_ + size_) {
        throw std::out_of_range("Position is out of range of vector");
    }

    std::size_t index = pos - data_;

    if (size_ == capacity_) {
        reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }

    pos = data_ + index;

    for (T* i = data_ + size_; i != pos; --i) {
        *i = *(i - 1);
    }

    *pos = value;
    ++size_;
}

template <typename T>
void Vector<T>::erase(T* pos) {
    if (pos < data_ || pos >= data_ + size_) {
        throw std::out_of_range("Position is out of range of vector");
    }

    for (T* i = pos; i < data_ + size_ - 1; ++i) {
        *i = *(i + 1);
    }
    --size_;
}

template <typename T>
void Vector<T>::assign(std::size_t count, const T& value) {
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

template <typename T>
void Vector<T>::swap(Vector &other) {
    T* tmpData = data_;
    data_ = other.data_;
    other.data_ = tmpData;

    std::size_t tmpSize = size_;
    size_ = other.size_;
    other.size_ = tmpSize;

    std::size_t tmpCap = capacity_;
    capacity_ = other.capacity_;
    other.capacity_ = tmpCap;
}