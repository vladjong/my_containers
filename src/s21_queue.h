#pragma once

namespace s21 {
template <class T>
class queue {
    struct Node {
        T data;
        Node* next;
    };

    Node* head = nullptr;
    Node* tail = nullptr;

    void emptyQueue();

 public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;

    queue<value_type>() {}
    queue<value_type>(queue<T>&& other);
    queue<value_type>(const queue<value_type>& other) { *this = other; }
    queue<value_type>(std::initializer_list<T> const& items);
    ~queue<value_type>() { emptyQueue(); }
    void push(const_reference value);
    void pop();
    const_reference front() const { return head->data; }
    const_reference back() const { return tail->data; }
    bool empty() const { return !head; }
    void swap(queue& other);
    size_type size() const;
    value_type pop_back();
    queue<value_type>& operator=(queue<value_type>&& other);
    queue<value_type>& operator=(const queue<value_type>& other);
    void emplace_back() {}
    template <class Type, class... Args>
    void emplace_back(Type value, Args... args);
};

}  // namespace s21

#include "s21_queue.inl"
