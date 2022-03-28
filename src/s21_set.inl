//  #include "s21_set.h"

namespace s21 {

template <class Key, class Value>
set<Key, Value>::set() : sorted_container<Key, Value>() {}

template <class Key, class Value>
set<Key, Value>::set(const set<Key, Value>& other) : sorted_container<Key, Value>(other) {}

template <class Key, class Value>
set<Key, Value>::set(set<Key, Value>&& other) : sorted_container<Key, Value>(std::move(other)) {}

template <class Key, class Value>
set<Key, Value>::set(std::initializer_list<value_type> const& items) {
    for (auto& i : items) {
        insert(i);
    }
}

template <class Key, class Value>
set<Key, Value>::~set() {}

template <class Key, class Value>
set<Key, Value>& set<Key, Value>::operator=(set&& other) {
    sorted_container<Key, Value>::operator=(std::move(other));
    return *this;
}

template <class Key, class Value>
std::pair<typename sorted_container<Key, Value>::iterator, bool> set<Key, Value>::insert(
    const value_type& value) {
    std::pair<Key, Value> pr = std::make_pair(value, 0);
    return this->insert_value(pr, Same);
}

template <class Key, class Value>
void set<Key, Value>::merge(set& other) {
    this->merge_value(other, Same);
}

template <class Key, class Value>
template <class... Args>
std::vector<std::pair<typename sorted_container<Key, Value>::iterator, bool>> set<Key, Value>::emplace(
    Args&&... args) {
    std::vector<std::pair<typename sorted_container<Key, Value>::iterator, bool>> resultVector;
    std::vector<value_type> tempVector = {args...};
    for (auto& elememt : tempVector) {
        resultVector.push_back(insert(elememt));
    }
    return resultVector;
}

}  // namespace s21
