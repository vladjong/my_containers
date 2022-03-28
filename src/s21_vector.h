#pragma once

namespace s21 {

template <class T>
class vector {
 public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = T*;
    using size_type = size_t;

    vector();
    explicit vector(size_type cappacity);
    vector(std::initializer_list<value_type> const& items);
    vector(const vector<T>& other);
    vector(vector<T>&& other);
    ~vector();
    vector<T>& operator=(vector&& other);

    reference at(size_type position);
    reference operator[](size_type position);
    const_reference front();
    const_reference back();
    iterator data();

    iterator begin();
    iterator end();

    bool empty();
    size_type size();
    size_type max_size();
    void reserve(size_type newSize);
    void resize(size_type newSize);
    size_type capacity();
    void shrink_to_fit();

    void clear();
    iterator insert(iterator it, const_reference value);
    void erase(iterator it);
    void push_back(const_reference value);
    void pop_back();
    void swap(vector<T>& other);

    void emplace_back();
    template <class Type, class... Args>
    void emplace_back(Type number, Args... args);

    iterator emplace(iterator it);
    template <class Type, class... Args>
    iterator emplace(iterator it, Type number, Args... args);

 private:
    size_type _cappacity;
    size_type _length;
    T* _data;

    void reallocType();
};

}  // namespace s21

#include "s21_vector.inl"

