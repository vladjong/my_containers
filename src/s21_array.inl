//   #include "s21_array.h"  // for vscode

namespace s21 {
template <class T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const& items) {
    if (items.size() > N) throw std::out_of_range("The size of initializer_list is too big");
    size_type i = 0;
    for (const auto& item : items) _data[i++] = item;
}

template <class T, size_t N>
array<T, N>::array(const array& other) {
    std::copy(other._data, other._data + N, _data);
}

template <class T, size_t N>
array<T, N>::array(array&& other) {
    std::move(other._data, other._data + N, _data);
}

template <class T, size_t N>
array<T, N>& array<T, N>::operator=(array&& other) {
    if (this != &other) std::move(other._data, other._data + N, _data);
    return *this;
}

template <class T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
    if (pos >= N) throw std::out_of_range("Out of array");
    return _data[pos];
}

template <class T, size_t N>
void array<T, N>::swap(array& other) {
    if (N != other.size()) throw std::out_of_range("Sizes must be equal!");
    for (size_type i = 0; i < N; i++) std::swap(_data[i], other._data[i]);
}

template <class T, size_t N>
void array<T, N>::fill(const_reference value) {
    for (size_type i = 0; i < N; i++) _data[i] = value;
}

}  // namespace s21
