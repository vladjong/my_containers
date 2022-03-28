#include "../s21_array.h"

#define INIT_TEN \
    { 6, 5, 3, 4, 77, 1, 18, 6, 1, 2 }
#define INIT_THREE \
    { 1, 2, 3 }

template <class T, size_t N>
bool isEqual(s21::array<T, N> s21Array, std::array<T, N> stdArray) {
    if (stdArray.size() != s21Array.size()) return false;
    bool result = true;
    for (size_t i = 0; i < s21Array.size() && result; i++)
        if (stdArray[i] != s21Array[i]) result = false;
    return result;
}

TEST(array_constructor_suit, default_constructor) {
    s21::array<int, 0> s21Array;
    std::array<int, 0> stdArray;
    ASSERT_TRUE(isEqual(s21Array, stdArray));
}

TEST(array_constructor_suit, init_constructor) {
    s21::array<double, 10> s21Array INIT_TEN;
    std::array<double, 10> stdArray INIT_TEN;
    ASSERT_TRUE(isEqual(s21Array, stdArray));
}

TEST(array_constructor_suit, init_constructor_string) {
    s21::array<std::string, 3> s21Array{"pupa", "lupa", "aboba"};
    std::array<std::string, 3> stdArray{"pupa", "lupa", "aboba"};
    ASSERT_TRUE(isEqual(s21Array, stdArray));
}

TEST(array_constructor_suit, copy_constructor) {
    s21::array<int, 10> s21Array INIT_TEN;
    s21::array<int, 10> s21Array_copied(s21Array);
    std::array<int, 10> stdArray INIT_TEN;
    std::array<int, 10> stdArray_copied(stdArray);
    ASSERT_TRUE(isEqual(s21Array, stdArray));
    ASSERT_TRUE(isEqual(s21Array_copied, stdArray_copied));
}

TEST(array_constructor_suit, move_constructor) {
    s21::array<int, 10> s21Array INIT_TEN;
    s21::array<int, 10> s21Array_moved(std::move(s21Array));
    std::array<int, 10> stdArray INIT_TEN;
    std::array<int, 10> stdArray_moved(std::move(stdArray));
    ASSERT_TRUE(isEqual(s21Array, stdArray));
    ASSERT_TRUE(isEqual(s21Array_moved, stdArray_moved));
}

TEST(array_constructor_suit, operator_move_constructor) {
    s21::array<int, 10> s21Array INIT_TEN;
    s21::array<int, 10> s21Array_moved;
    s21Array_moved = std::move(s21Array);
    std::array<int, 10> stdArray INIT_TEN;
    std::array<int, 10> stdArray_moved;
    stdArray_moved = std::move(stdArray);
    ASSERT_TRUE(isEqual(s21Array, stdArray));
    ASSERT_TRUE(isEqual(s21Array_moved, stdArray_moved));
}

TEST(array_element_access_suit, at) {
    s21::array<int, 3> s21Array INIT_THREE;
    std::array<int, 3> stdArray INIT_THREE;
    ASSERT_EQ(s21Array.at(1), stdArray.at(1));
    ASSERT_EQ(s21Array.at(0), stdArray.at(0));
}

TEST(array_element_access_suit, square_brackets) {
    s21::array<int, 10> s21Array INIT_TEN;
    std::array<int, 10> stdArray INIT_TEN;
    ASSERT_EQ(s21Array[5], stdArray[5]);
    ASSERT_EQ(s21Array[9], stdArray[9]);
}

TEST(array_element_access_suit, front) {
    s21::array<int, 3> s21Array INIT_THREE;
    std::array<int, 3> stdArray INIT_THREE;
    ASSERT_EQ(s21Array.front(), stdArray.front());
    s21Array[0] = 8;
    stdArray[0] = 8;
    ASSERT_EQ(s21Array.front(), stdArray.front());
}

TEST(array_element_access_suit, back) {
    s21::array<int, 3> s21Array INIT_THREE;
    std::array<int, 3> stdArray INIT_THREE;
    ASSERT_EQ(s21Array.back(), stdArray.back());
    s21Array[2] = 8;
    stdArray[2] = 8;
    ASSERT_EQ(s21Array.back(), stdArray.back());
}

TEST(array_capacity_suit, empty) {
    s21::array<int, 3> s21Array INIT_THREE;
    std::array<int, 3> stdArray INIT_THREE;
    ASSERT_EQ(s21Array.empty(), stdArray.empty());
}

TEST(array_capacity_suit, empty2) {
    s21::array<int, 0> s21Array;
    std::array<int, 0> stdArray;
    ASSERT_EQ(s21Array.empty(), stdArray.empty());
}

TEST(array_capacity_suit, size) {
    s21::array<int, 3> s21Array INIT_THREE;
    std::array<int, 3> stdArray INIT_THREE;
    ASSERT_EQ(s21Array.size(), stdArray.size());
}

TEST(array_capacity_suit, max_size) {
    s21::array<int, 3> s21Array INIT_THREE;
    std::array<int, 3> stdArray INIT_THREE;
    ASSERT_EQ(s21Array.max_size(), stdArray.max_size());
}

TEST(array_iterator_suit, begin_end_plus_minus) {
    s21::array<int, 10> s21Array INIT_TEN;
    s21::array<int, 10>::iterator s21Iter = s21Array.begin();
    s21::array<int, 10> stdArray INIT_TEN;
    std::array<int, 10>::iterator stdIter = s21Array.begin();
    while (s21Iter != s21Array.end()) ASSERT_EQ(*s21Iter++, *stdIter++);
    ASSERT_EQ(*--s21Iter, *--stdIter);
}

TEST(array_iterator_suit, begin_end) {
    s21::array<int, 0> s21Array;
    s21::array<int, 0>::iterator s21Iter = s21Array.begin();
    ASSERT_EQ(s21Iter, s21Array.end());
}

TEST(array_iterator_suit, data) {
    s21::array<int, 1> s21Array{6};
    s21::array<int, 1>::iterator s21Iter = s21Array.data();
    ASSERT_EQ(*s21Iter, 6);
    ASSERT_EQ(s21Iter, s21Array.begin());
}

TEST(array_const_iterator_suit, begin_end) {
    s21::array<int, 0> s21Array;
    s21::array<int, 0>::const_iterator s21Iter = s21Array.cbegin();
    ASSERT_EQ(s21Iter, s21Array.cend());
}

TEST(array_iterator_suit, change) {
    s21::array<int, 10> s21Array INIT_TEN;
    s21::array<int, 10>::iterator s21Iter = s21Array.begin();
    while (s21Iter != s21Array.end()) *++s21Iter = 11;
    s21::array<int, 10> stdArray;
    stdArray.fill(11);
    std::array<int, 10>::iterator stdIter = stdArray.begin();
    while (s21Iter != s21Array.end()) ASSERT_EQ(*s21Iter++, *stdIter++);
}

TEST(array_const_iterator_suit, begin_end_plus_minus) {
    s21::array<int, 10> s21Array INIT_TEN;
    s21::array<int, 10>::const_iterator s21Iter = s21Array.cbegin();
    s21::array<int, 10> stdArray INIT_TEN;
    std::array<int, 10>::const_iterator stdIter = stdArray.cbegin();
    while (s21Iter != s21Array.cend()) ASSERT_EQ(*s21Iter++, *stdIter++);
    --s21Iter;
    --stdIter;
    while (stdIter != stdArray.cbegin()) ASSERT_EQ(*s21Iter--, *stdIter--);
}

TEST(array_change_suit, fill) {
    s21::array<int, 10> s21Array;
    s21Array.fill(99);
    std::array<int, 10> stdArray;
    stdArray.fill(99);
    ASSERT_TRUE(isEqual(s21Array, stdArray));
}

TEST(array_change_suit, swap) {
    s21::array<int, 10> s21Array;
    s21::array<int, 10> s21Array2 INIT_TEN;
    s21Array.fill(99);
    s21Array2.swap(s21Array);
    std::array<int, 10> stdArray;
    std::array<int, 10> stdArray2 INIT_TEN;
    stdArray.fill(99);
    stdArray2.swap(stdArray);
    ASSERT_TRUE(isEqual(s21Array, stdArray));
    ASSERT_TRUE(isEqual(s21Array, stdArray));
}
