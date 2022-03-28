//  #include "s21_multiset.h"

namespace s21 {

template <class Key, class Value>
multiset<Key, Value>::multiset() : sorted_container<Key, Value>::sorted_container() {}

template <class Key, class Value>
multiset<Key, Value>::multiset(const multiset<Key, Value>& other)
    : sorted_container<Key, Value>::sorted_container() {
    this->_tree.prefix_insert(other._tree.root, other._tree.NIL, Different);
}

template <class Key, class Value>
multiset<Key, Value>::multiset(multiset<Key, Value>&& other)
    : sorted_container<Key, Value>::sorted_container(other) {}

template <class Key, class Value>
multiset<Key, Value>::multiset(std::initializer_list<value_type> const& items) {
    for (auto& i : items) {
        insert(i);
    }
}

template <class Key, class Value>
multiset<Key, Value>::~multiset() {}

template <class Key, class Value>
multiset<Key, Value>& multiset<Key, Value>::operator=(multiset&& other) {
    sorted_container<Key, Value>::operator=(std::move(other));
    return *this;
}

template <class Key, class Value>
typename sorted_container<Key, Value>::iterator multiset<Key, Value>::insert(const value_type& value) {
    return this->insert_value_iterator({value, 0}, Different);
}

template <class Key, class Value>
void multiset<Key, Value>::merge(multiset& other) {
    this->merge_value(other, Different);
}

}  // namespace s21
