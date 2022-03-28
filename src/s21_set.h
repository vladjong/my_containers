#pragma once

#include <vector>
#include "s21_sorted_container.h"

namespace s21 {

template <class Key, class Value = char>
class set : public sorted_container<Key, Value> {
 public:
    typedef Key value_type;
    typedef RBTNode<Key, Value>* Node;
    typedef typename sorted_container<Key, Value>::iterator iterator;
    typedef size_t size_type;

 public:
    set();
    set(std::initializer_list<value_type> const& items);
    set(const set& other);
    set(set&& other);
    ~set();
    set<Key, Value>& operator=(set&& other);

    std::pair<iterator, bool> insert(const value_type& value);
    void merge(set& other);

    template <class... Args>
    std::vector<std::pair<iterator, bool>> emplace(Args&&... args);

    using sorted_container<Key, Value>::find;
};

}  // namespace s21

#include "s21_set.inl"
