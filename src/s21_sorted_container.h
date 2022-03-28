#pragma once

#include <cmath>

#include "s21_RBTree.h"

namespace s21 {

template <class Key, class Value>
class sorted_container {
 public:
    typedef Key key_type;
    typedef Value mapped_type;
    typedef std::pair<key_type, mapped_type> value_type;
    typedef RBTNode<key_type, mapped_type>* Node;
    typedef size_t size_type;

    class iterator {
     public:
        Node _node;
        Node _NIL;

        iterator();
        iterator(Node node, Node NIL);
        iterator(const iterator& it);
        ~iterator();
        iterator& operator=(const iterator& other);
        iterator& operator++();
        iterator& operator--();
        bool operator==(const iterator& other);
        bool operator!=(const iterator& other);
        value_type operator*();
    };

    sorted_container();
    sorted_container(std::initializer_list<value_type> const& items);
    sorted_container(const sorted_container<Key, Value>& other);
    sorted_container(sorted_container<Key, Value>&& other);
    ~sorted_container();
    sorted_container<Key, Value>& operator=(sorted_container<Key, Value>&& other);

    bool empty();
    size_type size();
    size_type max_size();

    iterator begin();
    iterator end();

    void erase(iterator it);
    void swap(sorted_container& other);

    void clear();
    bool contains(const Key& key);

 protected:
    RBTree<Key, Value> _tree;

    std::pair<iterator, bool> insert_value(const value_type& value, TYPE type);
    iterator insert_value_iterator(const value_type& value, TYPE type);
    void merge_value(sorted_container& other, TYPE type);
    iterator find(const Key& key);
    iterator lower_bound(const Key& key);
    iterator upper_bound(const Key& key);
    std::pair<iterator, iterator> equal_range(const Key& key);

 private:
    void merge(iterator begin, iterator end, TYPE type);
};

}  // namespace s21

#include "s21_sorted_container.inl"

