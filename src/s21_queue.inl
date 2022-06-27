namespace s21 {

template <class T>
queue<T>::queue(std::initializer_list<T> const& dataArray) {
    for (const auto& data : dataArray) push(data);
}

template <class T>
queue<T>::queue(const queue<T>& other) {
    *this = other;
    return;
}

template <class T>
void queue<T>::emptyQueue() {
    while (head_) {
        tail_ = head_->next;
        delete head_;
        head_ = tail_;
    }
}

template <class T>
queue<T>::queue(queue<T>&& other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
}

template <class T>
queue<T>& queue<T>::operator=(queue<T>&& other) {
    if (this == &other) return *this;
    emptyQueue();
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    return *this;
}

template <class T>
void queue<T>::push(const_reference pushingData) {
    if (head_ == nullptr)
        head_ = tail_ = new Node(pushingData, nullptr);
    else
        tail_ = tail_->next = new Node(pushingData, nullptr);
}

template <class T>
void queue<T>::pop() {
    Node* tmp = head_;
    head_ = head_->next;
    if (head_ == nullptr) tail_ = nullptr;
    delete tmp;
}

template <class T>
queue<T>& queue<T>::operator=(const queue<T>& other) {
    if (head_) emptyQueue();
    Node* pointer = other.head_;
    while (pointer != nullptr) {
        push(pointer->data);
        pointer = pointer->next;
    }
    return *this;
}

template <class T>
typename queue<T>::size_type queue<T>::size() const {
    Node* tmp = head_;
    size_type count = 0;
    while (tmp) {
        tmp = tmp->next;
        count += 1;
    }
    return count;
}

template <class T>
void queue<T>::swap(queue<T>& other) {
    std::swap(this->head_, other.head_);
    std::swap(this->tail_, other.tail_);
}

template <class T>
template <class Type, class... Args>
void queue<T>::emplace_back(Type value, Args... args) {
    push(value);
    emplace_back(args...);
}

}  // namespace s21
