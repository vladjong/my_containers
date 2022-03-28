// #include "s21_map.h"

namespace s21 {

template <class Key, class Value>
map<Key, Value>::map() : sorted_container<Key, Value>::sorted_container() {}

template <class Key, class Value>
map<Key, Value>::map(const map<Key, Value>& other) : sorted_container<Key, Value>::sorted_container(other) {}

template <class Key, class Value>
map<Key, Value>::map(map<Key, Value>&& other) : sorted_container<Key, Value>::sorted_container(other) {}

template <class Key, class Value>
map<Key, Value>::map(std::initializer_list<value_type> const& items)
    : sorted_container<Key, Value>::sorted_container(items) {}

template <class Key, class Value>
map<Key, Value>::~map() {}

template <class Key, class Value>
map<Key, Value>& map<Key, Value>::operator=(map&& other) {
    sorted_container<Key, Value>::operator=(std::move(other));
    return *this;
}

template <class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert(const value_type& value) {
    return this->insert_value(value, Same);
}

template <class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert(const Key& key,
                                                                            const Value& value) {
    return insert({key, value});
}

template <class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert_or_assign(const Key& key,
                                                                                      const Value& value) {
    if (this->contains(key)) {
        typename map<Key, Value>::iterator tmp = this->find(key);
        tmp.set_value(value);
        return std::make_pair(tmp, true);
    } else {
        return insert({key, value});
    }
}

template <class Key, class Value>
Value& map<Key, Value>::at(const Key& key) {
    if (this->contains(key) == false) {
        throw std::invalid_argument("Error");
    }
    auto tmp = this->find(key);
    return tmp._node->data.second;
}

template <class Key, class Value>
Value& map<Key, Value>::operator[](const Key& key) {
    return at(key);
}

template <class Key, class Value>
void map<Key, Value>::merge(map& other) {
    this->merge_value(other, Same);
}

template <class Key, class Value>
template <class... Args>
std::vector<std::pair<typename sorted_container<Key, Value>::iterator, bool>> map<Key, Value>::emplace(
    Args&&... args) {
    std::vector<std::pair<typename sorted_container<Key, Value>::iterator, bool>> resultVector;
    std::vector<value_type> tempVector = {args...};
    for (auto& element : tempVector) {
        resultVector.push_back(insert(element));
    }
    return resultVector;
}

}  // namespace s21
