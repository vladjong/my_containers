#include "../s21_multiset.h"

TEST(MultisetCapacity, Empty) {
    s21::multiset<int> mySet{1, 2, 3, 3};
    std::multiset<int> originalSet{1, 2, 3, 3};
    EXPECT_EQ(mySet.empty(), originalSet.empty());

    s21::multiset<int> mySetTemp;
    std::multiset<int> originalSetTemp;
    EXPECT_EQ(mySetTemp.empty(), originalSetTemp.empty());
}

TEST(MultisettCapacity, Size) {
    s21::multiset<char> mySetTemp{'a', 'b', 'x', 'z'};
    std::multiset<char> originalSetTemp{'a', 'b', 'x', 'z'};
    EXPECT_EQ(mySetTemp.size(), originalSetTemp.size());
}

TEST(MultisetCapacity, MaxSize) {
    s21::multiset<double> mySet;
    EXPECT_EQ(mySet.max_size(), 4611686018427387903);
}

TEST(MultisetModifiers, Clear) {
    s21::multiset<std::string> mySet{"21", "BRYAN", "PROGRAMMER", "TEST"};
    std::multiset<std::string> originalSet{"21", "BRYAN", "PROGRAMMER", "TEST"};
    mySet.clear();
    originalSet.clear();
    EXPECT_EQ(mySet.size(), originalSet.size());
}

TEST(MultisetModifiers, InsertFirstSituation) {
    s21::multiset<double> mySet;
    std::multiset<double> originalSet;
    s21::multiset<double>::iterator myIt = mySet.insert(13.21);
    std::multiset<double>::iterator originalIt = originalSet.insert(13.21);
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(MultisetModifiers, InsertSecondSituation) {
    s21::multiset<int> mySet{13};
    std::multiset<int> originalSet{13};
    mySet.insert(8);
    originalSet.insert(8);
    mySet.insert(17);
    originalSet.insert(17);
    s21::multiset<int>::iterator myIt = mySet.begin();
    std::multiset<int>::iterator originalIt = originalSet.begin();
    for (size_t i = 0; i < mySet.size(); i++) {
        EXPECT_EQ((*myIt).first, *originalIt);
        ++myIt;
        ++originalIt;
    }
}

TEST(MultisetModifiers, InsertThirdSituation) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11};
    std::multiset<int> originalSet{13, 8, 17, 1, 11};
    mySet.insert(15);
    originalSet.insert(15);
    s21::multiset<int>::iterator myIt = mySet.begin();
    std::multiset<int>::iterator originalIt = originalSet.begin();
    for (size_t i = 0; i < mySet.size(); i++) {
        EXPECT_EQ((*myIt).first, *originalIt);
        ++myIt;
        ++originalIt;
    }
}

TEST(MultisetModifiers, InsertFourthSituation) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11, 15, 25};
    std::multiset<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    mySet.insert(6);
    originalSet.insert(6);
    s21::multiset<int>::iterator myIt = mySet.end();
    std::multiset<int>::iterator originalIt = originalSet.end();
    --myIt;
    --originalIt;
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(MultisetModifiers, InsertFithSituation) {
    s21::multiset<char> mySet{'a', 'a', 'v'};
    std::multiset<char> originalSet{'a', 'a', 'v'};
    mySet.insert('a');
    originalSet.insert('a');
    s21::multiset<char>::iterator myIt = mySet.end();
    std::multiset<char>::iterator originalIt = originalSet.end();
    --myIt;
    --originalIt;
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(MultisetModifiers, EraseFirstElement) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11, 15, 25};
    std::multiset<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    s21::multiset<int>::iterator myIt = mySet.begin();
    std::multiset<int>::iterator originalIt = originalSet.begin();
    mySet.erase(myIt);
    originalSet.erase(originalIt);
    s21::multiset<int>::iterator myItTemp = mySet.begin();
    std::multiset<int>::iterator originalItTemp = originalSet.begin();
    while (myItTemp != mySet.end()) {
        EXPECT_EQ((*myItTemp).first, *originalItTemp);
        ++myItTemp;
        ++originalItTemp;
    }
}

TEST(MultisetModifiers, EraseLastElement) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11, 15, 25};
    std::multiset<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    mySet.erase(mySet.find(25));
    originalSet.erase(originalSet.find(25));
    s21::multiset<int>::iterator myItTemp = mySet.begin();
    std::multiset<int>::iterator originalItTemp = originalSet.begin();
    while (myItTemp != mySet.end()) {
        EXPECT_EQ((*myItTemp).first, *originalItTemp);
        ++myItTemp;
        ++originalItTemp;
    }
}

TEST(MultisetModifiers, EraseMidleElement) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11, 15, 25};
    std::multiset<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    mySet.erase(mySet.find(13));
    originalSet.erase(originalSet.find(13));
    s21::multiset<int>::iterator myItTemp = mySet.begin();
    std::multiset<int>::iterator originalItTemp = originalSet.begin();
    while (myItTemp != mySet.end()) {
        EXPECT_EQ((*myItTemp).first, *originalItTemp);
        ++myItTemp;
        ++originalItTemp;
    }
}

TEST(MultisetModifiers, swap) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11, 15, 25};
    s21::multiset<int> mySetTemp{1, 2, 3};
    mySet.swap(mySetTemp);
    s21::multiset<int> mySetEq{1, 2, 3};
    s21::multiset<int>::iterator myIt = mySet.begin();
    s21::multiset<int>::iterator eqIt = mySetEq.begin();
    for (size_t i = 0; i < mySet.size(); i++) {
        EXPECT_EQ((*myIt).first, (*eqIt).first);
        ++myIt;
        ++eqIt;
    }
}

TEST(MultisetModifiers, Merge) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11, 15, 25};
    s21::multiset<int> mySetTemp{12, 3, 2};
    std::multiset<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    std::multiset<int> originalSetTemp{12, 3, 2};
    mySet.merge(mySetTemp);
    originalSet.merge(originalSetTemp);
    s21::multiset<int>::iterator myIt = mySet.begin();
    std::multiset<int>::iterator originalIt = originalSet.begin();
    for (size_t i = 0; i < mySet.size(); i++) {
        EXPECT_EQ((*myIt).first, *originalIt);
        ++myIt;
        ++originalIt;
    }
}

TEST(MultisetLookup, Find) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11, 15, 25};
    std::multiset<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    auto myFind = mySet.find(11);
    auto originalFind = originalSet.find(11);
    EXPECT_EQ((*myFind).first, *originalFind);
}

TEST(MultisetLookup, Contains) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11, 15, 25};
    auto myContains = mySet.contains(11);
    EXPECT_TRUE(myContains);
    myContains = mySet.contains(123);
    EXPECT_FALSE(myContains);
}

TEST(MultisetLookup, LowerBoundFirst) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11, 15, 25};
    std::multiset<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    s21::multiset<int>::iterator myIt = mySet.lower_bound(1);
    std::multiset<int>::iterator originalIt = originalSet.lower_bound(1);
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(MultisetLookup, LowerBoundSecond) {
    s21::multiset<char> mySet{'a', 'b', 'b', 'd'};
    std::multiset<char> originalSet{'a', 'b', 'b', 'd'};
    s21::multiset<char>::iterator myIt = mySet.lower_bound('a');
    std::multiset<char>::iterator originalIt = originalSet.lower_bound('a');
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(MultisetLookup, LowerBoundThird) {
    s21::multiset<char> mySet{'a', 'b', 'b', 'd'};
    std::multiset<char> originalSet{'a', 'b', 'b', 'd'};
    s21::multiset<char>::iterator myIt = mySet.lower_bound('b');
    std::multiset<char>::iterator originalIt = originalSet.lower_bound('b');
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(MultisetLookup, UpperBoundFirst) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11, 15, 25};
    std::multiset<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    s21::multiset<int>::iterator myIt = mySet.upper_bound(1);
    std::multiset<int>::iterator originalIt = originalSet.upper_bound(1);
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(MultisetLookup, UpperBoundSecond) {
    s21::multiset<char> mySet{'a', 'b', 'b', 'd'};
    std::multiset<char> originalSet{'a', 'b', 'b', 'd'};
    s21::multiset<char>::iterator myIt = mySet.upper_bound('a');
    std::multiset<char>::iterator originalIt = originalSet.upper_bound('a');
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(MultisetLookup, UpperBoundThird) {
    s21::multiset<char> mySet{'a', 'b', 'b', 'd'};
    std::multiset<char> originalSet{'a', 'b', 'b', 'd'};
    s21::multiset<char>::iterator myIt = mySet.upper_bound('b');
    std::multiset<char>::iterator originalIt = originalSet.upper_bound('b');
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(MultisetLookup, EqualRangeFirst) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11, 15, 25};
    std::multiset<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    auto myPair = mySet.equal_range(1);
    auto originalPair = originalSet.equal_range(1);
    EXPECT_EQ((*(myPair.first)).first, *originalPair.first);
    EXPECT_EQ((*(myPair.second)).first, *originalPair.second);
}

TEST(MultisetLookup, EqualRangeSecond) {
    s21::multiset<char> mySet{'a', 'b', 'b', 'd'};
    std::multiset<char> originalSet{'a', 'b', 'b', 'd'};
    auto myPair = mySet.equal_range('a');
    auto originalPair = originalSet.equal_range('a');
    EXPECT_EQ((*(myPair.first)).first, *originalPair.first);
    EXPECT_EQ((*(myPair.second)).first, *originalPair.second);
}

TEST(MultisetLookup, EqualRangeThird) {
    s21::multiset<char> mySet{'a', 'b', 'b', 'd'};
    std::multiset<char> originalSet{'a', 'b', 'b', 'd'};
    auto myPair = mySet.equal_range('b');
    auto originalPair = originalSet.equal_range('b');
    EXPECT_EQ((*(myPair.first)).first, *originalPair.first);
    EXPECT_EQ((*(myPair.second)).first, *originalPair.second);
}

TEST(MultisetConstructor, CopyConstructor) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11, 15, 25};
    s21::multiset<int> copySet(mySet);
    s21::multiset<int>::iterator myIt = mySet.begin();
    s21::multiset<int>::iterator copyIt = copySet.begin();
    for (size_t i = 0; i < mySet.size(); i++) {
        EXPECT_EQ((*myIt).first, (*copyIt).first);
        ++myIt;
        ++copyIt;
    }
}

TEST(MultisetConstructor, MoveConstructor) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11, 15, 25};
    s21::multiset<int> mySetTemp{13, 8, 17, 1, 11, 15, 25};
    s21::multiset<int> copySet(std::move(mySet));
    s21::multiset<int>::iterator myIt = mySetTemp.begin();
    s21::multiset<int>::iterator copyIt = copySet.begin();
    for (size_t i = 0; i < mySet.size(); i++) {
        EXPECT_EQ((*myIt).first, (*copyIt).first);
        ++myIt;
        ++copyIt;
    }
}

TEST(MultisetConstructor, OperatorEqual) {
    s21::multiset<int> mySet{13, 8, 17, 1, 11, 15, 25};
    s21::multiset<int> mySetTemp{13, 8, 17, 1, 11, 15, 25};
    s21::multiset<int> copySet = mySet;
    s21::multiset<int>::iterator myIt = mySetTemp.begin();
    s21::multiset<int>::iterator copyIt = copySet.begin();
    for (size_t i = 0; i < mySet.size(); i++) {
        EXPECT_EQ((*myIt).first, (*copyIt).first);
        ++myIt;
        ++copyIt;
    }
}

TEST(MultisetIterator, IteratorBegin) {
    s21::multiset<int> mySet({1, 4, 5, 2, 7, 12, 14});
    std::multiset<int> originalSet({1, 4, 5, 2, 7, 12, 14});
    s21::multiset<int>::iterator myIt = mySet.begin();
    std::multiset<int>::iterator originalIt = originalSet.begin();
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(MultisetIterator, IteratorEnd) {
    s21::multiset<int> mySet({1, 4, 5, 2, 7, 12, 14});
    std::multiset<int> originalSet({1, 4, 5, 2, 7, 12, 14});
    s21::multiset<int>::iterator myIt = mySet.end();
    std::multiset<int>::iterator originalIt = originalSet.end();
    --myIt;
    --originalIt;
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(MultisetIterator, IteratorPlus) {
    s21::multiset<int> mySet({1, 4, 5, 2, 7, 12, 14});
    std::multiset<int> originalSet({1, 4, 5, 2, 7, 12, 14});
    s21::multiset<int>::iterator myIt = mySet.begin();
    std::multiset<int>::iterator originalIt = originalSet.begin();
    ++myIt;
    ++myIt;
    ++originalIt;
    ++originalIt;
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(MultisetIterator, IteratorMinus) {
    s21::multiset<int> mySet({1, 4, 5, 2, 7, 12, 14});
    std::multiset<int> originalSet({1, 4, 5, 2, 7, 12, 14});
    s21::multiset<int>::iterator myIt = mySet.end();
    std::multiset<int>::iterator originalIt = originalSet.end();
    --myIt;
    --myIt;
    --originalIt;
    --originalIt;
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(MultisetIterator, IteratorEqual) {
    s21::multiset<int> mySet({1, 4, 5, 2, 7, 12, 14});
    std::multiset<int> originalSet({1, 4, 5, 2, 7, 12, 14});
    s21::multiset<int>::iterator myIt = mySet.begin();
    std::multiset<int>::iterator originalIt = originalSet.begin();
    EXPECT_TRUE((*myIt).first == *originalIt);
}

TEST(MultisetIterator, IteratorNotEqual) {
    s21::multiset<int> mySet({1, 4, 5, 2, 7, 12, 14});
    std::multiset<int> originalSet({1, 4, 5, 2, 7, 12, 14});
    s21::multiset<int>::iterator myIt = mySet.begin();
    std::multiset<int>::iterator originalIt = originalSet.begin();
    EXPECT_FALSE((*myIt).first != *originalIt);
}
