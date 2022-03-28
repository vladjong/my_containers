#pragma once

#include "s21_sorted_container.h"

namespace s21 {

template <class Key, class Value>
class map : public sorted_container<Key, Value> {
 public:
    typedef std::pair<Key, Value> value_type;
    typedef typename sorted_container<Key, Value>::iterator iterator;

 public:
    map();
    map(std::initializer_list<value_type> const& items);
    map(const map& m);
    map(map&& m);
    ~map();
    map<Key, Value>& operator=(map&& other);

    std::pair<iterator, bool> insert(const value_type& value);
    std::pair<iterator, bool> insert(const Key& key, const Value& value);
    std::pair<iterator, bool> insert_or_assign(const Key& key, const Value& obj);
    void merge(map& other);

    Value& at(const Key& key);
    Value& operator[](const Key& key);

    template <class... Args>
    std::vector<std::pair<iterator, bool>> emplace(Args&&... args);
};

}  // namespace s21

#include "s21_map.inl"
