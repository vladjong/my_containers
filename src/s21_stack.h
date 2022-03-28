#pragma once

namespace s21 {
template <class T>
class stack {
    struct Node {
        T data;
        Node* next;
    };
    Node* topNode = nullptr;

 public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;

 private:
    value_type pop_back();
    void emptyStack();

 public:
    stack<value_type>() {}
    stack<value_type>(stack<value_type>&& other);
    stack<value_type>(const stack<value_type>& other);
    stack<value_type>(std::initializer_list<value_type> const& items);
    ~stack<value_type>() { emptyStack(); }
    void push(const_reference value);
    void pop();
    const_reference top() const { return topNode->data; }
    void swap(stack& other);
    size_type size() const;
    bool empty() const { return !topNode; }
    stack<value_type>& operator=(stack<value_type>&& other);
    stack<value_type>& operator=(const stack<value_type>& other);
    void emplace_front() {}
    template <class Type, class... Args>
    void emplace_front(Type value, Args... args);
};

}  // namespace s21

#include "s21_stack.inl"
