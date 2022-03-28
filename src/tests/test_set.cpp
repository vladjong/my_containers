#include "../s21_set.h"

TEST(SetCapacity, Empty) {
    s21::set<int> mySet{1, 2, 3};
    std::set<int> originalSet{1, 2, 3};
    EXPECT_EQ(mySet.empty(), originalSet.empty());

    s21::set<int> mySetTemp;
    std::set<int> originalSetTemp;
    EXPECT_EQ(mySetTemp.empty(), originalSetTemp.empty());
}

TEST(SetCapacity, Size) {
    s21::set<char> mySetTemp{'a', 'b', 'x', 'z'};
    std::set<char> originalSetTemp{'a', 'b', 'x', 'z'};
    EXPECT_EQ(mySetTemp.size(), originalSetTemp.size());
}

TEST(SetCapacity, MaxSize) {
    s21::set<double> mySet;
    EXPECT_EQ(mySet.max_size(), 4611686018427387903);
}

TEST(SetModifiers, Clear) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
    std::set<int> originalSet{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
    mySet.clear();
    originalSet.clear();
    EXPECT_EQ(mySet.size(), originalSet.size());
}

TEST(SetModifiers, InsertFalse) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
    std::set<int> originalSet{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
    auto myPair = mySet.insert(8);
    auto originalPair = originalSet.insert(8);
    EXPECT_EQ(myPair.second, originalPair.second);
}

TEST(SetModifiers, InsertTrue) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25, 6, 22};
    std::set<int> originalSet{13, 8, 17, 1, 11, 15, 25, 6, 22};
    auto myPair = mySet.insert(27);
    auto originalPair = originalSet.insert(27);
    EXPECT_EQ(myPair.second, originalPair.second);
}

TEST(SetModifiers, InsertFirstSituation) {
    s21::set<int> mySet;
    std::set<int> originalSet;
    auto myPair = mySet.insert(13);
    auto originalPair = originalSet.insert(13);
    EXPECT_EQ((*myPair.first).first, *originalPair.first);
}

TEST(SetModifiers, InsertSecondSituation) {
    s21::set<int> mySet{13};
    std::set<int> originalSet{13};
    mySet.insert(8);
    originalSet.insert(8);
    mySet.insert(17);
    originalSet.insert(17);
    s21::set<int>::iterator myIt = mySet.begin();
    std::set<int>::iterator originalIt = originalSet.begin();
    for (size_t i = 0; i < mySet.size(); i++) {
        EXPECT_EQ((*myIt).first, *originalIt);
        ++myIt;
        ++originalIt;
    }
}

TEST(SetModifiers, InsertThirdSituation) {
    s21::set<int> mySet{13, 8, 17, 1, 11};
    std::set<int> originalSet{13, 8, 17, 1, 11};
    mySet.insert(15);
    originalSet.insert(15);
    s21::set<int>::iterator myIt = mySet.begin();
    std::set<int>::iterator originalIt = originalSet.begin();
    for (size_t i = 0; i < mySet.size(); i++) {
        EXPECT_EQ((*myIt).first, *originalIt);
        ++myIt;
        ++originalIt;
    }
}

TEST(SetModifiers, InsertFourthSituation) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25};
    std::set<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    mySet.insert(6);
    originalSet.insert(6);
    s21::set<int>::iterator myIt = mySet.end();
    std::set<int>::iterator originalIt = originalSet.end();
    --myIt;
    --originalIt;
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(SetModifiers, InsertFirthSituation) {
    s21::set<int> mySet{13};
    std::set<int> originalSet{13};
    mySet.insert(13);
    originalSet.insert(13);
    s21::set<int>::iterator myItTemp = mySet.begin();
    std::set<int>::iterator originalItTemp = originalSet.begin();
    while (myItTemp != mySet.end()) {
        EXPECT_EQ((*myItTemp).first, *originalItTemp);
        ++myItTemp;
        ++originalItTemp;
    }
}

TEST(SetModifiers, InsertSixSituation) {
    s21::set<int> mySet{13, 17, 11};
    std::set<int> originalSet{13, 17, 11};
    mySet.insert(1);
    originalSet.insert(1);
    mySet.insert(8);
    originalSet.insert(8);
    s21::set<int>::iterator myItTemp = mySet.begin();
    std::set<int>::iterator originalItTemp = originalSet.begin();
    while (myItTemp != mySet.end()) {
        EXPECT_EQ((*myItTemp).first, *originalItTemp);
        ++myItTemp;
        ++originalItTemp;
    }
}

TEST(SetModifiers, EraseFirstElement) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25};
    std::set<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    s21::set<int>::iterator myIt = mySet.begin();
    std::set<int>::iterator originalIt = originalSet.begin();
    mySet.erase(myIt);
    originalSet.erase(originalIt);
    s21::set<int>::iterator myItTemp = mySet.begin();
    std::set<int>::iterator originalItTemp = originalSet.begin();
    while (myItTemp != mySet.end()) {
        EXPECT_EQ((*myItTemp).first, *originalItTemp);
        ++myItTemp;
        ++originalItTemp;
    }
}

TEST(SetModifiers, EraseLastElement) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25};
    std::set<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    mySet.erase(mySet.find(25));
    originalSet.erase(originalSet.find(25));
    s21::set<int>::iterator myItTemp = mySet.begin();
    std::set<int>::iterator originalItTemp = originalSet.begin();
    while (myItTemp != mySet.end()) {
        EXPECT_EQ((*myItTemp).first, *originalItTemp);
        ++myItTemp;
        ++originalItTemp;
    }
}

TEST(SetModifiers, EraseMidleElement) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25};
    std::set<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    mySet.erase(mySet.find(13));
    originalSet.erase(originalSet.find(13));
    s21::set<int>::iterator myItTemp = mySet.begin();
    std::set<int>::iterator originalItTemp = originalSet.begin();
    while (myItTemp != mySet.end()) {
        EXPECT_EQ((*myItTemp).first, *originalItTemp);
        ++myItTemp;
        ++originalItTemp;
    }
}

TEST(SetModifiers, EraseCaseOne) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
    std::set<int> originalSet{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
    mySet.erase(mySet.find(6));
    mySet.erase(mySet.find(13));
    originalSet.erase(originalSet.find(6));
    originalSet.erase(originalSet.find(13));
    s21::set<int>::iterator myItTemp = mySet.begin();
    std::set<int>::iterator originalItTemp = originalSet.begin();
    while (myItTemp != mySet.end()) {
        EXPECT_EQ((*myItTemp).first, *originalItTemp);
        ++myItTemp;
        ++originalItTemp;
    }
}

TEST(SetModifiers, EraseCaseTwo) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
    std::set<int> originalSet{13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
    mySet.erase(mySet.find(13));
    mySet.erase(mySet.find(25));
    originalSet.erase(originalSet.find(13));
    originalSet.erase(originalSet.find(25));
    s21::set<int>::iterator myItTemp = mySet.begin();
    std::set<int>::iterator originalItTemp = originalSet.begin();
    while (myItTemp != mySet.end()) {
        EXPECT_EQ((*myItTemp).first, *originalItTemp);
        ++myItTemp;
        ++originalItTemp;
    }
}

TEST(SetModifiers, EraseCaseThird) {
    s21::set<int> mySet{13, 8, 1, 11, 15, 25, 2, 13, 123, 23, 26, 14, 16};
    std::set<int> originalSet{13, 8, 1, 11, 15, 25, 2, 13, 123, 23, 26, 14, 16};
    mySet.erase(mySet.find(15));
    mySet.erase(mySet.find(1));
    mySet.erase(mySet.find(11));
    originalSet.erase(originalSet.find(15));
    originalSet.erase(originalSet.find(1));
    originalSet.erase(originalSet.find(11));
    s21::set<int>::iterator myItTemp = mySet.begin();
    std::set<int>::iterator originalItTemp = originalSet.begin();
    while (myItTemp != mySet.end()) {
        EXPECT_EQ((*myItTemp).first, *originalItTemp);
        ++myItTemp;
        ++originalItTemp;
    }
}

TEST(SetModifiers, EraseCaseFourth) {
    s21::set<int> mySet{13, 8, 1, 11, 15, 25, 2, 13, 123, 23, 26, 14, 16};
    std::set<int> originalSet{13, 8, 1, 11, 15, 25, 2, 13, 123, 23, 26, 14, 16};
    mySet.erase(mySet.find(26));
    mySet.erase(mySet.find(23));
    originalSet.erase(originalSet.find(26));
    originalSet.erase(originalSet.find(23));
    s21::set<int>::iterator myItTemp = mySet.begin();
    std::set<int>::iterator originalItTemp = originalSet.begin();
    while (myItTemp != mySet.end()) {
        EXPECT_EQ((*myItTemp).first, *originalItTemp);
        ++myItTemp;
        ++originalItTemp;
    }
}

TEST(SetModifiers, swap) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25};
    s21::set<int> mySetTemp{1, 2, 3};
    mySet.swap(mySetTemp);
    s21::set<int> mySetEq{1, 2, 3};
    s21::set<int>::iterator myIt = mySet.begin();
    s21::set<int>::iterator eqIt = mySetEq.begin();
    for (size_t i = 0; i < mySet.size(); i++) {
        EXPECT_EQ((*myIt).first, (*eqIt).first);
        ++myIt;
        ++eqIt;
    }
}

TEST(SetModifiers, Merge) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25};
    s21::set<int> mySetTemp{12, 3, 2};
    std::set<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    std::set<int> originalSetTemp{12, 3, 2};
    mySet.merge(mySetTemp);
    originalSet.merge(originalSetTemp);
    s21::set<int>::iterator myIt = mySet.begin();
    std::set<int>::iterator originalIt = originalSet.begin();
    for (size_t i = 0; i < mySet.size(); i++) {
        EXPECT_EQ((*myIt).first, *originalIt);
        ++myIt;
        ++originalIt;
    }
}

TEST(SetLookup, Find) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25};
    std::set<int> originalSet{13, 8, 17, 1, 11, 15, 25};
    auto myFind = mySet.find(11);
    auto originalFind = originalSet.find(11);
    EXPECT_EQ((*myFind).first, *originalFind);
}

TEST(SetLookup, Contains) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25};
    auto myContains = mySet.contains(11);
    EXPECT_TRUE(myContains);
    myContains = mySet.contains(123);
    EXPECT_FALSE(myContains);
}

TEST(SetConstructor, CopyConstructor) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25};
    s21::set<int> copySet(mySet);
    s21::set<int>::iterator myIt = mySet.begin();
    s21::set<int>::iterator copyIt = copySet.begin();
    for (size_t i = 0; i < mySet.size(); i++) {
        EXPECT_EQ((*myIt).first, (*copyIt).first);
        ++myIt;
        ++copyIt;
    }
}

TEST(SetConstructor, MoveConstructor) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25};
    s21::set<int> mySetTemp{13, 8, 17, 1, 11, 15, 25};
    s21::set<int> copySet(std::move(mySet));
    s21::set<int>::iterator myIt = mySetTemp.begin();
    s21::set<int>::iterator copyIt = copySet.begin();
    for (size_t i = 0; i < mySet.size(); i++) {
        EXPECT_EQ((*myIt).first, (*copyIt).first);
        ++myIt;
        ++copyIt;
    }
}

TEST(SetConstructor, OperatorEqual) {
    s21::set<int> mySet{13, 8, 17, 1, 11, 15, 25};
    s21::set<int> mySetTemp{13, 8, 17, 1, 11, 15, 25};
    s21::set<int> copySet = mySet;
    s21::set<int>::iterator myIt = mySetTemp.begin();
    s21::set<int>::iterator copyIt = copySet.begin();
    for (size_t i = 0; i < mySet.size(); i++) {
        EXPECT_EQ((*myIt).first, (*copyIt).first);
        ++myIt;
        ++copyIt;
    }
}

TEST(SetIterator, IteratorBegin) {
    s21::set<int> mySet{1, 4, 5, 2, 7, 12, 14};
    std::set<int> originalSet{1, 4, 5, 2, 7, 12, 14};
    s21::set<int>::iterator myIt = mySet.begin();
    std::set<int>::iterator originalIt = originalSet.begin();
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(SetIterator, IteratorEnd) {
    s21::set<int> mySet{1, 4, 5, 2, 7, 12, 14};
    std::set<int> originalSet{1, 4, 5, 2, 7, 12, 14};
    s21::set<int>::iterator myIt = mySet.end();
    std::set<int>::iterator originalIt = originalSet.end();
    --myIt;
    --originalIt;
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(SetIterator, IteratorPlus) {
    s21::set<int> mySet{1, 4, 5, 2, 7, 12, 14};
    std::set<int> originalSet{1, 4, 5, 2, 7, 12, 14};
    s21::set<int>::iterator myIt = mySet.begin();
    std::set<int>::iterator originalIt = originalSet.begin();
    ++myIt;
    ++myIt;
    ++originalIt;
    ++originalIt;
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(SetIterator, IteratorMinus) {
    s21::set<int> mySet{1, 4, 5, 2, 7, 12, 14};
    std::set<int> originalSet{1, 4, 5, 2, 7, 12, 14};
    s21::set<int>::iterator myIt = mySet.end();
    std::set<int>::iterator originalIt = originalSet.end();
    --myIt;
    --myIt;
    --originalIt;
    --originalIt;
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(SetIterator, IteratorBonus) {
    s21::set<int> mySet{1, 4, 5, 2, 7, 12, 14};
    std::set<int> originalSet{1, 4, 5, 2, 7, 12, 14};
    s21::set<int>::iterator myIt = mySet.begin();
    std::set<int>::iterator originalIt = originalSet.begin();
    ++myIt;
    ++myIt;
    ++originalIt;
    ++originalIt;
    --myIt;
    --myIt;
    --originalIt;
    --originalIt;
    EXPECT_EQ((*myIt).first, *originalIt);
}

TEST(SetIterator, IteratorEqual) {
    s21::set<int> mySet{1, 4, 5, 2, 7, 12, 14};
    std::set<int> originalSet{1, 4, 5, 2, 7, 12, 14};
    s21::set<int>::iterator myIt = mySet.begin();
    std::set<int>::iterator originalIt = originalSet.begin();
    EXPECT_TRUE((*myIt).first == *originalIt);
}

TEST(SetIterator, IteratorNotEqual) {
    s21::set<int> mySet{1, 4, 5, 2, 7, 12, 14};
    std::set<int> originalSet{1, 4, 5, 2, 7, 12, 14};
    s21::set<int>::iterator myIt = mySet.begin();
    std::set<int>::iterator originalIt = originalSet.begin();
    EXPECT_FALSE((*myIt).first != *originalIt);
}

TEST(SetEmplace, EmplaceFirst) {
    s21::set<int> mySet;
    auto myPair = mySet.emplace(21, 31);
    EXPECT_EQ((*myPair[0].first).first, 21);
    EXPECT_EQ((*myPair[1].first).first, 31);
}

TEST(SetEmplace, EmplaceSecond) {
    s21::set<int> mySet;
    auto myPair = mySet.emplace();
    EXPECT_EQ(myPair.size(), 0);
}

TEST(SetEmplace, EmplaceThird) {
    s21::set<int> mySet{21};
    auto myPair = mySet.emplace(21);
    EXPECT_FALSE((*myPair[0].first).second);
}
