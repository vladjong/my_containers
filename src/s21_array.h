#pragma once

namespace s21 {
template <class T, size_t N>
class array {
 private:
    T _data[N]{};

 public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using size_type = size_t;
    using iterator = T *;
    using const_iterator = const T *;

    array() {}
    array(std::initializer_list<value_type> const &items);
    array(const array &other);
    array(array &&other);
    array &operator=(array &&other);
    ~array() {}

    reference at(size_type pos);
    reference operator[](size_type pos) { return _data[pos]; }
    const_reference front() const { return _data[0]; }
    const_reference back() const { return _data[N - 1]; }
    bool empty() const { return N == 0; }
    size_type size() const { return N; }
    size_type max_size() const { return N; }
    iterator data() { return _data; }
    iterator begin() { return _data; }
    iterator end() { return _data + N; }
    const_iterator cbegin() const { return _data; }
    const_iterator cend() const { return _data + N; }

    void swap(array &other);
    void fill(const_reference value);
};

}  // namespace s21

#include "s21_array.inl"
