//  #include "s21_queue.h" //  for vscode

namespace s21 {

template <class T>
queue<T>::queue(std::initializer_list<T> const& dataArray) {
    for (const auto& data : dataArray) push(data);
}

template <class T>
void queue<T>::emptyQueue() {
    while (head) {
        tail = head->next;
        delete head;
        head = tail;
    }
}

template <class T>
queue<T>::queue(queue<T>&& other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
}

template <class T>
queue<T>& queue<T>::operator=(queue<T>&& other) {
    if (this == &other) return *this;
    emptyQueue();
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    return *this;
}

template <class T>
void queue<T>::push(const_reference pushingData) {
    Node* newNode = new Node;
    newNode->data = pushingData;
    newNode->next = nullptr;
    if (tail)
        tail->next = newNode;
    tail = newNode;
    if (!head)
        head = tail;
}

template <class T>
void queue<T>::pop() {
    if (!head) return;
    Node* newHead = head->next;
    delete(head);
    head = newHead;
}

template <class T>
typename queue<T>::value_type queue<T>::pop_back() {
    if (!head) return 0;
    Node* newHead = head->next;
    T headData = head->data;
    delete(head);
    head = newHead;
    return headData;
}

template <class T>
queue<T>& queue<T>::operator=(const queue<T>& other) {
    if (head) emptyQueue();
    Node* pointer = other.head;
    while (pointer != nullptr) {
        push(pointer->data);
        pointer = pointer->next;
    }
    return *this;
}

template <class T>
typename queue<T>::size_type queue<T>::size() const {
    Node* tmp = head;
    size_type count = 0;
    while (tmp) {
        tmp = tmp->next;
        count++;
    }
    return count;
}

template <class T>
void queue<T>::swap(queue<T>& other) {
    std::swap(this->head, other.head);
    std::swap(this->tail, other.tail);
}

template <class T>
template <class Type, class... Args>
void queue<T>::emplace_back(Type value, Args... args) {
    push(value);
    emplace_back(args...);
}

}   // namespace s21
