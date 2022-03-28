#pragma once

namespace s21 {
template <class T>
class list {
    struct Node {
        T _data;
        Node* prev;
        Node* next;
    };

 public:
    // using definitions
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;

    // internal class iterator
    class ListIterator {
     public:
        Node* head;
        Node* tail;
        Node* iter;
        // constructors & destructor
        ListIterator();
        explicit ListIterator(const list<T>& other);
        // overload operators
        value_type operator*();
        void operator++();
        void operator--();
        bool operator==(const ListIterator& other);
        bool operator!=(const ListIterator& other);
    };

    typedef typename list<T>::ListIterator iterator;

    // iterator functions
    iterator begin();
    iterator end();

    class ListConstIterator {
     public:
        Node* head;
        Node* tail;
        Node* iter;
        // constructors & destructor
        ListConstIterator();
        explicit ListConstIterator(const list<T>& other);
        // overload operators
        value_type operator*();
        void operator++();
        void operator--();
        bool operator==(const ListConstIterator& other);
        bool operator!=(const ListConstIterator& other);
    };

    typedef typename list<T>::ListConstIterator const_iterator;

    // iterator functions
    const_iterator cbegin();
    const_iterator cend();

 private:
    Node* firstNode;
    Node* topNode;
    size_type _size;

    void push(const_reference data);
    void swap_list(list&& l);

 public:
    // constructors & destructor
    list<T>();
    list<T>(size_type n);
    list<T>(std::initializer_list<T> const& items);
    list<T>(const list& other);
    list<T>(list&& other);
    ~list<T>();
    // operators
    list<T>& operator=(list&& l);
    // Element access
    const_reference front();
    const_reference back();
    // Capacity
    bool empty();
    size_type size();
    size_type max_size();
    // Modifiers
    void clear();
    iterator insert(iterator pos, const_reference value);
    void erase(iterator pos);
    void push_pos(iterator pos, T value);
    void push_back(const_reference value);
    void pop_back();
    void push_front(const_reference value);
    void pop_front();
    void swap(list& other);
    void merge(list& other);
    void splice(const_iterator pos, list& other);
    void left_splice(const_iterator pos, const list& other);
    void reverse();
    void unique();
    void sort();
    // My functions
    void shift_right(Node* shift, Node* target);
    void shift_left(Node* shift, Node* target);
    // Bonus functions
    iterator emplace(iterator pos);
    template <class Type, class... Args>
    iterator emplace(iterator pos, Type n, Args... args);

    void emplace_back();
    template <class Type, class... Args>
    void emplace_back(Type n, Args... args);

    void emplace_front();
    template <class Type, class... Args>
    void emplace_front(Type n, Args... args);
};
}  // namespace s21

#include "s21_list.inl"
