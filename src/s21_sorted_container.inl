//  #include "s21_sorted_container.h"

namespace s21 {

template <class Key, class Value>
sorted_container<Key, Value>::sorted_container() {}

template <class Key, class Value>
sorted_container<Key, Value>::sorted_container(const sorted_container& other) {
    _tree.prefix_insert(other._tree.root, other._tree.NIL, Same);
}

template <class Key, class Value>
sorted_container<Key, Value>::sorted_container(sorted_container&& other) : _tree(other._tree) {
    other._tree.root = nullptr;
    other._tree.NIL = nullptr;
}

template <class Key, class Value>
sorted_container<Key, Value>::~sorted_container() {}

template <class Key, class Value>
sorted_container<Key, Value>& sorted_container<Key, Value>::operator=(sorted_container&& other) {
    clear();
    merge(other.begin(), other.end(), Same);
    other.clear();
    other._tree.root = nullptr;
    other._tree.NIL = nullptr;
    return *this;
}

template <class Key, class Value>
sorted_container<Key, Value>::sorted_container(std::initializer_list<value_type> const& items) {
    for (auto& i : items) {
        _tree.insert_value(i, Same);
    }
}

template <class Key, class Value>
typename sorted_container<Key, Value>::iterator sorted_container<Key, Value>::begin() {
    RBTNode<Key, Value>* nodeTemp = minimum_value(_tree.root, _tree.NIL);
    return iterator(nodeTemp, _tree.NIL);
}

template <class Key, class Value>
typename sorted_container<Key, Value>::iterator sorted_container<Key, Value>::end() {
    return iterator(_tree.NIL, _tree.NIL);
}

template <class Key, class Value>
std::pair<typename sorted_container<Key, Value>::iterator, bool> sorted_container<Key, Value>::insert_value(
    const value_type& value, TYPE type) {
    std::pair<Node, bool> pairTemp = _tree.insert_value(value, type);
    iterator it(pairTemp.first, _tree.NIL);
    return std::make_pair(it, pairTemp.second);
}

template <class Key, class Value>
typename sorted_container<Key, Value>::iterator sorted_container<Key, Value>::insert_value_iterator(
    const value_type& value, TYPE type) {
    std::pair<Node, bool> pairTemp = _tree.insert_value(value, type);
    return iterator(pairTemp.first, _tree.NIL);
}

template <class Key, class Value>
void sorted_container<Key, Value>::erase(iterator it) {
    _tree.delete_value(it._node);
}

template <class Key, class Value>
void sorted_container<Key, Value>::swap(sorted_container& other) {
    sorted_container tempFirst = *this;
    sorted_container tempSecond = other;
    clear();
    other.clear();
    std::swap(_tree, tempSecond._tree);
    std::swap(other._tree, tempFirst._tree);
}

template <class Key, class Value>
typename sorted_container<Key, Value>::iterator sorted_container<Key, Value>::find(const Key& key) {
    if (_tree.search(key).second) {
        return iterator(_tree.search(key).first, _tree.NIL);
    }
    return iterator(_tree.NIL, _tree.NIL);
}

template <class Key, class Value>
bool sorted_container<Key, Value>::contains(const Key& key) {
    return _tree.search(key).second;
}

template <class Key, class Value>
bool sorted_container<Key, Value>::empty() {
    return _tree.size() < 1;
}

template <class Key, class Value>
typename sorted_container<Key, Value>::size_type sorted_container<Key, Value>::size() {
    return _tree.size();
}

template <class Key, class Value>
typename sorted_container<Key, Value>::size_type sorted_container<Key, Value>::max_size() {
    return static_cast<size_type>(pow(2.0, 64.0) / 2.0) / 2 - 1;
}

template <class Key, class Value>
void sorted_container<Key, Value>::clear() {
    if (size() > 1) {
        _tree.clear();
        _tree.set_size(0);
    }
}

template <class Key, class Value>
void sorted_container<Key, Value>::merge(iterator begin, iterator end, TYPE type) {
    while (begin != end) {
        _tree.insert_value({(*begin).first, (*begin).second}, type);
        ++begin;
    }
}

template <class Key, class Value>
void sorted_container<Key, Value>::merge_value(sorted_container& other, TYPE type) {
    merge(other.begin(), other.end(), type);
    other.clear();
}

template <class Key, class Value>
typename sorted_container<Key, Value>::iterator sorted_container<Key, Value>::lower_bound(const Key& key) {
    iterator loverIterator = begin();
    iterator endIterator = end();
    while (loverIterator != endIterator) {
        if ((*loverIterator).first >= key) {
            return iterator(loverIterator._node, loverIterator._NIL);
        }
        ++loverIterator;
    }
    return iterator(loverIterator._node, loverIterator._NIL);
}

template <class Key, class Value>
typename sorted_container<Key, Value>::iterator sorted_container<Key, Value>::upper_bound(const Key& key) {
    iterator upperIterator = begin();
    iterator endIterator = end();
    while (upperIterator != endIterator) {
        if ((*upperIterator).first > key) {
            return iterator(upperIterator._node, upperIterator._NIL);
        }
        ++upperIterator;
    }
    return iterator(upperIterator._node, upperIterator._NIL);
}

template <class Key, class Value>
std::pair<typename sorted_container<Key, Value>::iterator, typename sorted_container<Key, Value>::iterator>
sorted_container<Key, Value>::equal_range(const Key& key) {
    return std::make_pair(lower_bound(key), upper_bound(key));
}

template <class Key, class Value>
sorted_container<Key, Value>::iterator::iterator() : _node(nullptr), _NIL(nullptr) {}

template <class Key, class Value>
sorted_container<Key, Value>::iterator::iterator(Node node, Node NIL) : _node(node), _NIL(NIL) {}

template <class Key, class Value>
sorted_container<Key, Value>::iterator::iterator(const iterator& it) : _node(it._node), _NIL(it._NIL) {}

template <class Key, class Value>
sorted_container<Key, Value>::iterator::~iterator() {
    _node = nullptr;
    _NIL = nullptr;
}

template <class Key, class Value>
typename sorted_container<Key, Value>::iterator& sorted_container<Key, Value>::iterator::operator++() {
    if (_node != _NIL) {
        _node = successor(_node, _NIL);
    }
    return *this;
}

template <class Key, class Value>
typename sorted_container<Key, Value>::iterator& sorted_container<Key, Value>::iterator::operator--() {
    if (_node != _NIL) {
        _node = predecessor(_node, _NIL);
    } else {
        _node = _NIL->parent;
    }
    return *this;
}

template <class Key, class Value>
bool sorted_container<Key, Value>::iterator::operator==(const iterator& other) {
    return _node == other._node;
}

template <class Key, class Value>
bool sorted_container<Key, Value>::iterator::operator!=(const iterator& other) {
    return _node != other._node;
}

template <class Key, class Value>
typename sorted_container<Key, Value>::value_type sorted_container<Key, Value>::iterator::operator*() {
    return _node->data;
}

}  // namespace s21
