#pragma once

#include <vector>

#include "s21_sorted_container.h"

namespace s21 {

template <class Key, class Value = char>
class multiset : public sorted_container<Key, Value> {
 public:
    typedef Key value_type;
    typedef RBTNode<Key, Value>* Node;
    typedef typename sorted_container<Key, Value>::iterator iterator;

 public:
    multiset();
    multiset(std::initializer_list<value_type> const& items);
    multiset(const multiset& other);
    multiset(multiset&& other);
    ~multiset();
    multiset<Key, Value>& operator=(multiset&& other);

    iterator insert(const value_type& value);
    void merge(multiset& other);

    using sorted_container<Key, Value>::find;
    using sorted_container<Key, Value>::lower_bound;
    using sorted_container<Key, Value>::upper_bound;
    using sorted_container<Key, Value>::equal_range;
};

}  // namespace s21

#include "s21_multiset.inl"

