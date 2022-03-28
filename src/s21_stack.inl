//  #include "s21_stack.h"  // for vscode

namespace s21 {

template <class T>
stack<T>::stack(std::initializer_list<T> const& items) {
    for (const auto& element : items) push(element);
}

template <class T>
void stack<T>::emptyStack() {
    Node* buf1 = topNode;
    while (buf1 != nullptr) {
        Node* buf2 = buf1;
        buf1 = buf1->next;
        delete buf2;
    }
    topNode = nullptr;
}

template <class T>
stack<T>::stack(stack<T>&& other) {
    std::swap(topNode, other.topNode);
}

template <class T>
stack<T>& stack<T>::operator=(stack<T>&& other) {
    if (this == &other) return *this;
    if (topNode) emptyStack();
    std::swap(topNode, other.topNode);
    return *this;
}

template <class T>
void stack<T>::push(const_reference pushingData) {
    Node* new_node = new Node;
    new_node->next = topNode;
    new_node->data = pushingData;
    topNode = new_node;
}

template <class T>
void stack<T>::pop() {
    if (topNode == nullptr) return;
    Node* last = topNode;
    topNode = topNode->next;
    delete last;
}

template <class T>
T stack<T>::pop_back() {
    if (topNode == nullptr) return 0;
    Node* last = topNode;
    T value = topNode->data;
    topNode = topNode->next;
    delete last;
    return value;
}

template <class T>
stack<T>::stack(const stack<T>& other) {
    *this = other;
}

template <class T>
stack<T>& stack<T>::operator=(const stack<T>& other) {
    if (topNode) emptyStack();
    Node* pointer = other.topNode;
    stack<T> reverse;
    while (pointer != nullptr) {
        reverse.push(pointer->data);
        pointer = pointer->next;
    }
    while (reverse.topNode != nullptr) {
        T data = reverse.pop_back();
        push(data);
    }
    return *this;
}

template <class T>
typename s21::stack<int>::size_type stack<T>::size() const {
    if (!topNode) return 0;
    Node* tmp = topNode;
    size_t count = 0;
    while (tmp) {
        tmp = tmp->next;
        count++;
    }
    return count;
}

template <class T>
void stack<T>::swap(stack<T>& other) {
    std::swap(this->topNode, other.topNode);
}

template <class T>
template <class Type, class... Args>
void stack<T>::emplace_front(Type value, Args... args) {
    push(value);
    emplace_front(args...);
}

}  // namespace s21
