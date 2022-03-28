#include "../s21_list.h"

TEST(list_constructor_suit, default_constructor) {
    s21::list<int> s21list;
    std::list<int> stdlist;
    ASSERT_EQ(s21list.empty(), stdlist.empty());
    ASSERT_EQ(stdlist.max_size() - s21list.max_size(), 42);
}

TEST(list_constructor_suit, size_constructor) {
    s21::list<int> s21list(5);
    ASSERT_EQ(s21list.size(), 5);
}

TEST(list_constructor_suit, init_constructor) {
    s21::list<int> s21list{1, 2, 3};
    ASSERT_FALSE(s21list.empty());
    ASSERT_EQ(s21list.front(), 1);
    s21list.clear();
    ASSERT_TRUE(s21list.empty());
}

TEST(list_constructor_suit, init_string_constructor) {
    s21::list<std::string> s21list{"hello", "world"};
    ASSERT_EQ(s21list.front(), "hello");
    ASSERT_EQ(s21list.back(), "world");
}

TEST(list_constructor_suit, copy_constructor) {
    s21::list<int> s21list{3, 2, 1};
    s21::list<int> s21listCopied(s21list);
    ASSERT_EQ(s21list.front(), s21listCopied.front());
}

TEST(list_constructor_suit, move_constructor) {
    s21::list<int> s21list{1, 2, 3};
    s21::list<int> s21listMoved(std::move(s21list));
    ASSERT_TRUE(s21list.empty());
    ASSERT_FALSE(s21listMoved.empty());
}

TEST(list_constructor_suit, move_operator_constructor) {
    s21::list<int> s21list{1, 2, 3};
    s21::list<int> s21listMoved;
    s21listMoved = std::move(s21list);
    ASSERT_TRUE(s21list.empty());
    ASSERT_FALSE(s21listMoved.empty());
}

TEST(list_push_suit, push_int) {
    s21::list<int> s21list;
    s21list.push_front(99);
    s21list.push_back(123);
    std::list<int> stdlist;
    stdlist.push_front(99);
    stdlist.push_back(123);
    ASSERT_EQ(s21list.front(), stdlist.front());
    ASSERT_EQ(s21list.back(), stdlist.back());
}

TEST(list_pop_suit, pop_int) {
    s21::list<int> s21list{566, 123};
    std::list<int> stdlist;
    stdlist.push_back(566);
    stdlist.push_back(123);
    ASSERT_EQ(s21list.front(), stdlist.front());
    ASSERT_EQ(s21list.back(), stdlist.back());
    s21list.pop_back();
    stdlist.pop_back();
    ASSERT_EQ(s21list.front(), stdlist.front());
    ASSERT_EQ(s21list.back(), stdlist.back());
    s21list.pop_front();
    stdlist.pop_front();
    ASSERT_EQ(s21list.empty(), stdlist.empty());
}

TEST(list_pop_suit, pop_string) {
    s21::list<std::string> s21list{"hello", "world"};
    std::list<std::string> stdlist;
    stdlist.push_back("hello");
    stdlist.push_back("world");
    ASSERT_EQ(s21list.front(), stdlist.front());
    ASSERT_EQ(s21list.back(), stdlist.back());
    s21list.pop_back();
    stdlist.pop_back();
    ASSERT_EQ(s21list.front(), stdlist.front());
    ASSERT_EQ(s21list.back(), stdlist.back());
}

TEST(list_size_suit, size_swap) {
    s21::list<int> s21list{566, 123, 3, 3, 2, 1};
    s21::list<int> s21list2{566, 123};
    ASSERT_EQ(s21list.size(), 6);
    ASSERT_EQ(s21list2.size(), 2);
    s21list.swap(s21list2);
    ASSERT_EQ(s21list.size(), 2);
    ASSERT_EQ(s21list2.size(), 6);
}

TEST(list_insert_suit, insert_int) {
    s21::list<int> s21list{566, 123};
    std::list<int> stdlist{44, 55};
    s21::list<int>::ListIterator s21it;
    s21it = s21list.begin();
    std::list<int>::iterator stdit = stdlist.begin();
    s21list.insert(s21it, 77);
    stdlist.insert(stdit, 77);
    ASSERT_EQ(s21list.front(), stdlist.front());
    ++s21it;
    s21list.insert(s21it, 99);
    s21list.erase(s21it);
    ASSERT_EQ(s21list.size(), 3);
}

TEST(list_sort_suit, sort) {
    s21::list<int> s21list{3, 5, 1, 4, 6, 2};
    std::list<int> stdlist{3, 5, 1, 4, 6, 2};
    std::list<int> sortedlist{1, 2, 3, 4, 5, 6};
    s21list.sort();
    stdlist.sort();
    s21::list<int>::ListIterator s21it = s21list.begin();
    std::list<int>::iterator stdit = stdlist.begin();
    std::list<int>::iterator sortit = sortedlist.begin();
    while (s21it.iter) {
        ASSERT_EQ(*s21it, *stdit);
        ASSERT_EQ(*s21it, *sortit);
        ++s21it;
        ++stdit;
        ++sortit;
    }
}

TEST(list_iter_suit, iter_end) {
    s21::list<int> s21list{3, 5, 1, 4, 6, 2};
    std::list<int> stdlist{3, 5, 1, 4, 6, 2};
    s21::list<int>::ListIterator s21it = s21list.end();
    std::list<int>::iterator stdit = stdlist.end();
    s21::list<int>::ListConstIterator const21 = s21list.cend();
    std::list<int>::const_iterator conststd = stdlist.cend();

    while (s21it.iter != s21it.head) {
        --s21it;
        --stdit;
        --const21;
        --conststd;
        ASSERT_EQ(*s21it, *stdit);
        ASSERT_EQ(*const21, *conststd);
    }
}

TEST(list_iter_suit, iter_eq) {
    s21::list<int> s21list{3, 5, 1, 4, 6, 2};
    s21::list<int>::ListIterator begin = s21list.begin();
    s21::list<int>::ListIterator begin1 = begin;
    s21::list<int>::ListConstIterator cbegin = s21list.cbegin();
    s21::list<int>::ListConstIterator cbegin1 = cbegin;
    ASSERT_TRUE(begin == begin1);
    ASSERT_FALSE(begin != begin1);
    ASSERT_TRUE(cbegin == cbegin1);
    ASSERT_FALSE(cbegin != cbegin1);
}

TEST(list_change_suit, reverse) {
    s21::list<int> s21list{6, 5, 4, 3, 2, 1};
    std::list<int> stdlist{1, 2, 3, 4, 5, 6};
    s21list.reverse();
    s21::list<int>::ListConstIterator s21it;
    s21it = s21list.cbegin();
    std::list<int>::const_iterator stdit = stdlist.cbegin();
    while (s21it.iter) {
        ASSERT_EQ(*s21it, *stdit);
        ++s21it;
        ++stdit;
    }
}

TEST(list_change_suit, unique) {
    s21::list<int> s21list{1, 1, 1, 1, 2, 2, 3, 3};
    std::list<int> stdlist{1, 2, 3};
    s21list.unique();
    s21::list<int>::ListIterator s21it = s21list.begin();
    std::list<int>::iterator stdit = stdlist.begin();
    while (s21it.iter) {
        ASSERT_EQ(*s21it, *stdit);
        ++s21it;
        ++stdit;
    }
}

TEST(bonus_suit, emplace) {
    s21::list<int> s21list{1, 2, 3};
    s21::list<int> check{1, 55, 44, 33, 2, 3};
    s21::list<int>::ListIterator s21it = s21list.begin();
    ++s21it;
    s21list.emplace(s21it, 33, 44, 55);
    s21::list<int>::ListIterator ch1 = s21list.begin();
    s21::list<int>::ListIterator ch2 = check.begin();
    while (ch1.iter) {
        ASSERT_EQ(*ch1, *ch2);
        ++ch1;
        ++ch2;
    }
}

TEST(bonus_suit, emplace_back) {
    s21::list<int> s21list{1, 2, 3};
    s21::list<int> check{1, 2, 3, 33, 44, 55};
    s21list.emplace_back(33, 44, 55);
    s21::list<int>::ListIterator ch1 = s21list.begin();
    s21::list<int>::ListIterator ch2 = check.begin();
    while (ch1.iter) {
        ASSERT_EQ(*ch1, *ch2);
        ++ch1;
        ++ch2;
    }
}

TEST(bonus_suit, emplace_front) {
    s21::list<int> s21list{1, 2, 3};
    s21::list<int> check{5, 5, 5, 1, 2, 3};
    s21list.emplace_front(5, 5, 5);
    s21::list<int>::ListIterator ch1 = s21list.begin();
    s21::list<int>::ListIterator ch2 = check.begin();
    while (ch1.iter) {
        ASSERT_EQ(*ch1, *ch2);
        ++ch1;
        ++ch2;
    }
}
