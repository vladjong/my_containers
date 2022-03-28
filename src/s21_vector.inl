//  #include "s21_vector.h"

namespace s21 {

template <class T>
vector<T>::vector() : _cappacity(4), _length(0) {
    _data = new value_type[4];
}

template <class T>
vector<T>::vector(size_type cappacity) : _cappacity(cappacity), _length(0) {
    if (cappacity < 1) {
        throw std::invalid_argument("Error");
    }
    _data = new value_type[cappacity];
}

template <class T>
vector<T>::vector(std::initializer_list<value_type> const& items) : _cappacity(4), _length(0) {
    while (items.size() > _cappacity) {
        _cappacity *= 2;
    }
    _data = new value_type[_cappacity];
    for (auto& i : items) {
        _data[_length] = i;
        _length++;
    }
}

template <class T>
vector<T>::vector(const vector<T>& other) : _cappacity(other._cappacity), _length(other._length) {
    _data = new value_type[_cappacity];
    for (size_t i = 0; i < _length; i++) {
        _data[i] = other._data[i];
    }
}

template <class T>
vector<T>::vector(vector&& other) : _cappacity(other._cappacity), _length(other._length), _data(nullptr) {
    std::swap(_data, other._data);
}

template <class T>
vector<T>::~vector() {
    if (_data) {
        delete[] _data;
    }
    _data = nullptr;
}

template <class T>
vector<T>& vector<T>::operator=(vector&& other) {
    _cappacity = other._cappacity;
    _length = other._length;
    delete[] _data;
    _data = nullptr;
    std::swap(_data, other._data);
    return *this;
}

template <class T>
void vector<T>::reserve(size_type newSize) {
    if (newSize < _cappacity) {
        throw std::invalid_argument("Error");
    }
    _cappacity = newSize;
    reallocType();
}

template <class T>
void vector<T>::resize(size_type newSize) {
    reserve(newSize);
    _length = newSize;
}

template <class T>
void vector<T>::push_back(const_reference value) {
    if (_length == _cappacity) {
        reserve(_cappacity * 2);
    }
    _data[_length] = value;
    _length += 1;
}

template <class T>
void vector<T>::pop_back() {
    if (_length) {
        _data[_length - 1] = 0;
        _length -= 1;
    }
}

template <class T>
typename vector<T>::reference vector<T>::operator[](size_type position) {
    return at(position);
}

template <class T>
typename vector<T>::reference vector<T>::at(size_type position) {
    if (position > _length - 1) {
        throw std::out_of_range("Error");
    }
    return _data[position];
}

template <class T>
typename vector<T>::const_reference vector<T>::front() {
    return _data[0];
}

template <class T>
typename vector<T>::const_reference vector<T>::back() {
    return _data[_length - 1];
}

template <class T>
typename vector<T>::iterator vector<T>::data() {
    return _data;
}

template <class T>
void vector<T>::clear() {
    _length = 0;
    if (_data) {
        delete[] _data;
    }
    _data = new T[_cappacity]();
}

template <class T>
typename vector<T>::size_type vector<T>::capacity() {
    return _cappacity;
}

template <class T>
typename vector<T>::size_type vector<T>::size() {
    return _length;
}

template <class T>
typename vector<T>::size_type vector<T>::max_size() {
    return static_cast<size_type>(pow(2.0, 64.0) / static_cast<T>(sizeof(value_type))) / 2 - 1;
}

template <class T>
bool vector<T>::empty() {
    return _length < 1;
}

template <class T>
void vector<T>::shrink_to_fit() {
    _cappacity = _length;
    reallocType();
}

template <class T>
typename vector<T>::iterator vector<T>::begin() {
    return _data;
}

template <class T>
typename vector<T>::iterator vector<T>::end() {
    return _data + _length;
}

template <class T>
typename vector<T>::iterator vector<T>::insert(iterator it, const_reference value) {
    size_t positionIterator = it - _data;
    if (_length == _cappacity) {
        reserve(_cappacity * 2);
    }
    for (size_t i = _length, j = _length - 1; i > 0; i--, j--) {
        _data[i] = _data[j];
        if (i == positionIterator) {
            _data[i] = value;
            j++;
        }
    }
    _length++;
    _data[positionIterator] = value;
    it = _data + positionIterator;
    return it;
}

template <class T>
void vector<T>::erase(iterator it) {
    if (_length != 0) {
        std::move(it + 1, _data + _length, it);
        _length -= 1;
    }
}

template <class T>
void vector<T>::swap(vector<T>& other) {
    std::swap(_cappacity, other._cappacity);
    std::swap(_length, other._length);
    std::swap(_data, other._data);
}

template <class T>
void vector<T>::reallocType() {
    iterator newData = new value_type[_cappacity]();
    for (size_t i = 0; i < _length; i++) {
        newData[i] = _data[i];
    }
    std::swap(_data, newData);
    delete[] newData;
}

template <class T>
void vector<T>::emplace_back() {}

template <class T>
template <class Type, class... Args>
void vector<T>::emplace_back(Type number, Args... args) {
    push_back(number);
    emplace_back(args...);
}

template <class T>
typename vector<T>::iterator vector<T>::emplace(iterator it) {
    return it;
}

template <class T>
template <class Type, class... Args>
typename vector<T>::iterator vector<T>::emplace(iterator it, Type number, Args... args) {
    it = insert(it, number);
    emplace(it, args...);
    return it;
}

}  // namespace s21
