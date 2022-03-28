// #include "s21_list.h"

namespace s21 {

template <class T>
list<T>::list() : firstNode(nullptr), topNode(nullptr), _size(0) {}

template <class T>
list<T>::list(size_t n) : firstNode(nullptr), topNode(nullptr), _size(n) {}

template <class T>
list<T>::list(std::initializer_list<T> const &items) : firstNode(nullptr), topNode(nullptr) {
    _size = 0;
    for (const auto &element : items) push(element);
}

template <class T>
list<T>::list(const list &other) : firstNode(nullptr), topNode(nullptr), _size(0) {
    s21::list<int>::ListIterator it(other);
    while (it.iter) {
        push(it.iter->_data);
        ++it;
    }
}

template <class T>
list<T>::list(list &&other) : firstNode(nullptr), topNode(nullptr), _size(0) {
    swap_list(std::move(other));
}

template <class T>
list<T>::~list() {
    if (topNode != nullptr) {
        Node *buf;
        buf = topNode;
        while (buf != nullptr) {
            topNode->next = nullptr;
            buf = topNode->prev;
            topNode->prev = nullptr;
            delete topNode;
            topNode = buf;
        }
        firstNode = nullptr;
    }
}

template <class T>
list<T> &list<T>::operator=(list &&l) {
    swap_list(std::move(l));
    return *this;
}

template <class T>
const T &list<T>::front() {
    return firstNode->_data;
}

template <class T>
const T &list<T>::back() {
    return topNode->_data;
}

template <class T>
bool list<T>::empty() {
    bool check = false;
    if (firstNode == nullptr) check = true;
    return check;
}

template <class T>
size_t list<T>::size() {
    return _size;
}

template <class T>
size_t list<T>::max_size() {
    return static_cast<size_type>(pow(2, sizeof(void *) * 8) / sizeof(list) - 1);
}

template <class T>
void list<T>::clear() {
    while (firstNode) {
        topNode = firstNode->next;
        delete firstNode;
        firstNode = topNode;
    }
}

template <class T>
typename list<T>::ListIterator list<T>::insert(ListIterator pos, const T &value) {
    list<T>::ListIterator new_pos(begin());
    if (pos.iter == firstNode) {
        push_front(value);
        new_pos.iter = firstNode;
    } else if (pos.iter == nullptr && topNode) {
        push_back(value);
        new_pos.iter = topNode;
    } else {
        _size++;
        while (new_pos.iter != pos.iter && new_pos.iter != nullptr) ++new_pos;
        Node *buf = new Node;
        Node *it = pos.iter;
        buf->_data = value;
        buf->prev = it->prev;
        buf->next = it;
        if (it->prev) it->prev->next = buf;
        it->prev = buf;
        --new_pos;
    }
    return new_pos;
}

template <class T>
void list<T>::erase(ListIterator pos) {
    if (pos.iter == nullptr) {
        throw std::out_of_range("Iterator points to nullptr");
    } else {
        _size--;
        if (pos.iter == firstNode) firstNode = pos.iter->next;
        if (pos.iter == topNode) topNode = pos.iter->prev;
        if (pos.iter->prev) pos.iter->prev->next = pos.iter->next;
        if (pos.iter->next) pos.iter->next->prev = pos.iter->prev;
        delete pos.iter;
        pos.iter = nullptr;
    }
}

template <class T>
void list<T>::push_back(const T &value) {
    _size++;
    Node *buf = new Node;
    buf->_data = value;
    buf->prev = topNode;
    buf->next = nullptr;
    if (topNode != nullptr) {
        topNode->next = buf;
    }
    topNode = buf;
    if (firstNode == nullptr) {
        firstNode = buf;
    }
}

template <class T>
void list<T>::pop_back() {
    if (topNode != nullptr) {
        Node *buf = topNode->prev;
        delete topNode;
        topNode = buf;
        if (topNode != nullptr) {
            topNode->next = nullptr;
        }
        _size--;
    }
}

template <class T>
void list<T>::push_front(const T &value) {
    _size++;
    Node *buf = new Node;
    buf->_data = value;
    buf->next = firstNode;
    buf->prev = nullptr;
    if (firstNode != nullptr) {
        firstNode->prev = buf;
    }
    firstNode = buf;
    if (topNode == nullptr) {
        topNode = buf;
    }
}

template <class T>
void list<T>::pop_front() {
    if (firstNode != nullptr) {
        firstNode = firstNode->next;
        if (firstNode != nullptr) {
            firstNode->prev = nullptr;
        }
        _size--;
    }
}

template <class T>
void list<T>::swap(list &other) {
    swap_list(std::move(other));
}

template <class T>
void list<T>::merge(list &other) {
    list<int>::ListIterator this_it(*this);
    list<int>::ListConstIterator other_it(other);
    while (other_it.iter != nullptr) {
        if (this_it.iter == nullptr) {
            splice(other_it, other);
            break;
        }
        if (this_it.iter->_data >= other_it.iter->_data) {
            insert(this_it, other_it.iter->_data);
            ++other_it;
        } else {
            ++this_it;
        }
    }
}

template <class T>
void list<T>::splice(ListConstIterator pos, list &other) {
    Node *buf = other.firstNode;
    while (buf != pos.iter && buf != nullptr) buf = buf->next;
    while (buf != nullptr) {
        push(buf->_data);
        buf = buf->next;
    }
}

template <class T>
void list<T>::left_splice(ListConstIterator pos, const list &other) {
    ListConstIterator it(other);
    while (it.iter != pos.iter) {
        push(it.iter->_data);
        it.iter = it.iter->next;
    }
}

template <class T>
void list<T>::reverse() {
    Node *buf_ptr = firstNode;
    while (buf_ptr != nullptr) {
        std::swap(buf_ptr->next, buf_ptr->prev);
        buf_ptr = buf_ptr->prev;
    }
    std::swap(firstNode, topNode);
}

template <class T>
void list<T>::unique() {
    list<int>::ListIterator it(*this);
    it = begin();
    ++it;
    for (; it != end(); ++it) {
        if (it.iter && it.iter->_data == it.iter->prev->_data) {
            erase(it);
            it = begin();
        }
    }
}

template <class T>
void list<T>::shift_right(Node *shift, Node *target) {
    if (firstNode == shift) firstNode = shift->next;
    if (shift->prev != nullptr) shift->prev->next = shift->next;
    if (shift->next != nullptr) shift->next->prev = shift->prev;
    shift->prev = target;
    shift->next = target->next;
    if (target->next != nullptr) target->next->prev = shift;
    target->next = shift;
    if (topNode == target) topNode = shift;
}

template <class T>
void list<T>::shift_left(Node *shift, Node *target) {
    if (topNode == shift) topNode = shift->prev;
    if (shift->prev != nullptr) shift->prev->next = shift->next;
    if (shift->next != nullptr) shift->next->prev = shift->prev;
    shift->next = target;
    shift->prev = target->prev;
    if (target->prev != nullptr) target->prev->next = shift;
    target->prev = shift;
    if (firstNode == target) firstNode = shift;
}

template <class T>
void list<T>::sort() {
    if (_size < 2) return;
    ListConstIterator it(*this);
    Node *pivot = firstNode;
    Node *head = firstNode, *tail = topNode;
    for (size_t i = 0; i < _size / 2; i++) {
        it.iter = it.iter->next;
        pivot = pivot->next;
    }
    while (head != pivot) {
        if (head->_data >= pivot->_data) {
            shift_right(head, pivot);
            head = firstNode;
        } else {
            head = head->next;
        }
    }
    while (tail != pivot) {
        if (tail->_data < pivot->_data) {
            shift_left(tail, pivot);
            tail = topNode;
        } else {
            tail = tail->prev;
        }
    }
    list left, right;
    left.left_splice(it, *this);
    right.splice(it, *this);

    left.sort();
    right.sort();
    left.merge(right);
    *this = std::move(left);
}

template <class T>
void list<T>::push(const T &data) {
    Node *current = new Node;
    current->_data = data;
    current->prev = topNode;
    current->next = nullptr;
    if (topNode != nullptr) {
        topNode->next = current;
    }
    topNode = current;
    if (firstNode == nullptr) {
        firstNode = current;
    }
    _size++;
}

template <class T>
void list<T>::swap_list(list &&l) {
    std::swap(firstNode, l.firstNode);
    std::swap(topNode, l.topNode);
    std::swap(_size, l._size);
}

template <class T>
list<T>::ListIterator::ListIterator() : head(nullptr), tail(nullptr), iter(nullptr) {}

template <class T>
list<T>::ListIterator::ListIterator(const list<T> &other)
    : head(other.firstNode), tail(other.topNode), iter(other.firstNode) {}

template <class T>
T list<T>::ListIterator::operator*() {
    return iter ? iter->_data : 0;
}

template <class T>
void list<T>::ListIterator::operator++() {
    if (iter) iter = iter->next;
}

template <class T>
void list<T>::ListIterator::operator--() {
    if (iter == head) {
        throw std::out_of_range("Out of list size");
    } else {
        if (iter) {
            iter = iter->prev;
        } else {
            iter = tail;
        }
    }
}

template <class T>
bool list<T>::ListIterator::operator==(const ListIterator &other) {
    return iter == other.iter;
}

template <class T>
bool list<T>::ListIterator::operator!=(const ListIterator &other) {
    return iter != other.iter;
}

template <class T>
typename list<T>::iterator list<T>::begin() {
    return ListIterator(*this);
}

template <class T>
typename list<T>::iterator list<T>::end() {
    iterator buf(*this);
    while (buf.iter != nullptr) buf.iter = buf.iter->next;
    return buf;
}

template <class T>
typename list<T>::const_iterator list<T>::cbegin() {
    return const_iterator(*this);
}

template <class T>
typename list<T>::const_iterator list<T>::cend() {
    const_iterator buf(*this);
    while (buf.iter != nullptr) buf.iter = buf.iter->next;
    return buf;
}

template <class T>
list<T>::ListConstIterator::ListConstIterator() : head(nullptr), tail(nullptr), iter(nullptr) {}

template <class T>
list<T>::ListConstIterator::ListConstIterator(const list<T> &other)
    : head(other.firstNode), tail(other.topNode), iter(other.firstNode) {}

template <class T>
T list<T>::ListConstIterator::operator*() {
    return iter ? iter->_data : 0;
}

template <class T>
void list<T>::ListConstIterator::operator++() {
    if (iter) iter = iter->next;
}

template <class T>
void list<T>::ListConstIterator::operator--() {
    if (iter == head) {
        throw std::out_of_range("Out of list size");
    } else {
        if (iter) {
            iter = iter->prev;
        } else {
            iter = tail;
        }
    }
}

template <class T>
bool list<T>::ListConstIterator::operator==(const ListConstIterator &other) {
    return iter == other.iter;
}

template <class T>
bool list<T>::ListConstIterator::operator!=(const ListConstIterator &other) {
    return iter != other.iter;
}

template <class T>
typename list<T>::ListIterator list<T>::emplace(iterator pos) {
    return pos;
}

template <class T>
template <class Type, class... Args>
typename list<T>::ListIterator list<T>::emplace(iterator pos, Type n, Args... args) {
    pos = insert(pos, n);
    emplace(pos, args...);
    return pos;
}

template <class T>
void list<T>::emplace_back() {}

template <class T>
template <class Type, class... Args>
void list<T>::emplace_back(Type n, Args... args) {
    push_back(n);
    emplace_back(args...);
}

template <class T>
void list<T>::emplace_front() {}

template <class T>
template <class Type, class... Args>
void list<T>::emplace_front(Type n, Args... args) {
    push_front(n);
    emplace_front(args...);
}
}  // namespace s21
