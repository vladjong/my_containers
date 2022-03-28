#include "../s21_vector.h"

TEST(VectorElementAccess, ReferenceAt) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    int& my = myVector.at(3);
    int& original = originalVector.at(3);
    EXPECT_EQ(my, original);

    my = myVector.at(0);
    original = originalVector.at(0);
    EXPECT_EQ(my, original);

    my = myVector.at(6);
    original = originalVector.at(6);
    EXPECT_EQ(my, original);

    EXPECT_THROW(myVector.at(7), std::exception);
}

TEST(VectorElementAccess, ReferenceOperatorBrakets) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    int& my = myVector[4];
    int& original = originalVector[4];
    EXPECT_EQ(my, original);

    my = myVector[0];
    original = originalVector[0];
    EXPECT_EQ(my, original);

    my = myVector[6];
    original = originalVector[6];
    EXPECT_EQ(my, original);

    EXPECT_THROW(myVector[7], std::exception);
}

TEST(VectorElementAccess, ReferenceFront) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    EXPECT_EQ(myVector.front(), originalVector.front());
}

TEST(VectorElementAccess, ReferenceBack) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    EXPECT_EQ(myVector.back(), originalVector.back());
}

TEST(VectorElementAccess, IteratorData) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    int* myIt = myVector.data();
    int* originalIt = originalVector.data();
    EXPECT_EQ(*myIt, *originalIt);
}

TEST(VectorIterator, IteratorBegin) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    s21::vector<int>::iterator myIt = myVector.begin();
    std::vector<int>::iterator originalIt = originalVector.begin();
    EXPECT_EQ(*myIt, *originalIt);
}

TEST(VectorIterator, IteratorEnd) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    s21::vector<int>::iterator myIt = myVector.end();
    std::vector<int>::iterator originalIt = originalVector.end();
    EXPECT_EQ(*--myIt, *--originalIt);
}

TEST(VectorIterator, IteratorPlus) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    s21::vector<int>::iterator myIt = myVector.begin();
    std::vector<int>::iterator originalIt = originalVector.begin();
    EXPECT_EQ(*++myIt, *++originalIt);
}

TEST(VectorIterator, IteratorMinus) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    s21::vector<int>::iterator myIt = myVector.end();
    std::vector<int>::iterator originalIt = originalVector.end();
    EXPECT_EQ(*--myIt, *--originalIt);
}

TEST(VectorIterator, IteratorEqual) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    s21::vector<int>::iterator myIt = myVector.begin();
    std::vector<int>::iterator originalIt = originalVector.begin();
    EXPECT_TRUE(*myIt == *originalIt);
}

TEST(VectorIterator, IteratorNotEqual) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    s21::vector<int>::iterator myIt = myVector.begin();
    std::vector<int>::iterator originalIt = originalVector.begin();
    EXPECT_TRUE(*myIt != ++*originalIt);
}

TEST(VectorCapacity, Empty) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    EXPECT_EQ(myVector.empty(), myVector.empty());
}

TEST(VectorCapacity, Size) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    EXPECT_EQ(myVector.size(), myVector.size());

    s21::vector<int> myVectorTemp;
    std::vector<int> originalVectorTemp;
    EXPECT_EQ(myVectorTemp.size(), originalVectorTemp.size());
}

TEST(VectorCapacity, MaxSize) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    EXPECT_EQ(myVector.max_size(), originalVector.max_size());

    s21::vector<int> myVectorTemp{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVectorTemp{1, 4, 5, 2, 7, 12, 14};
    EXPECT_EQ(myVectorTemp.max_size(), originalVectorTemp.max_size());
}

TEST(VectorCapacity, Reserve) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    myVector.reserve(14);
    originalVector.reserve(14);
    EXPECT_EQ(myVector.capacity(), originalVector.capacity());

    EXPECT_THROW(myVector.reserve(2), std::exception);
}

TEST(VectorCapacity, Resize) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    myVector.resize(14);
    originalVector.resize(14);
    EXPECT_EQ(myVector.capacity(), originalVector.capacity());
    EXPECT_EQ(myVector.size(), originalVector.size());

    EXPECT_THROW(myVector.reserve(2), std::exception);
}

TEST(VectorCapacity, Capacity) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    EXPECT_EQ(myVector.capacity(), 8);
}

TEST(VectorCapacity, ShrinkToFit) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    myVector.reserve(14);
    originalVector.reserve(14);
    myVector.shrink_to_fit();
    originalVector.shrink_to_fit();
    EXPECT_EQ(myVector.capacity(), originalVector.capacity());
}

TEST(VectorModifiers, Clear) {
    s21::vector<int> myVector{1, 4, 5, 2, 7, 12, 14};
    std::vector<int> originalVector{1, 4, 5, 2, 7, 12, 14};
    myVector.clear();
    originalVector.clear();
    EXPECT_EQ(myVector.capacity(), 8);
    EXPECT_EQ(myVector.size(), originalVector.size());
}

TEST(VectorModifiers, InsertV1) {
    s21::vector<int> myVector;
    std::vector<int> originalVector;
    myVector.push_back(2);
    myVector.push_back(23);
    myVector.push_back(3);
    myVector.push_back(33);

    originalVector.push_back(2);
    originalVector.push_back(23);
    originalVector.push_back(3);
    originalVector.push_back(33);

    s21::vector<int>::iterator myIt = myVector.begin();
    std::vector<int>::iterator originalIt = originalVector.begin();

    myIt = myVector.insert(myIt, 1);
    originalIt = originalVector.insert(originalIt, 1);
    EXPECT_EQ(*myIt, *originalIt);
}

TEST(VectorModifiers, InsertV2) {
    s21::vector<int> myVector;
    std::vector<int> originalVector;
    myVector.push_back(2);
    myVector.push_back(23);
    myVector.push_back(3);
    myVector.push_back(33);

    originalVector.push_back(2);
    originalVector.push_back(23);
    originalVector.push_back(3);
    originalVector.push_back(33);

    s21::vector<int>::iterator myIt = myVector.begin();
    std::vector<int>::iterator originalIt = originalVector.begin();

    myIt = myVector.insert(myIt + 3, 1);
    originalIt = originalVector.insert(originalIt + 3, 1);
    EXPECT_EQ(*myIt, *originalIt);
}

TEST(VectorModifiers, EraseV1) {
    s21::vector<int> myVector;
    std::vector<int> originalVector;
    myVector.push_back(2);
    myVector.push_back(23);
    myVector.push_back(3);
    myVector.push_back(33);

    originalVector.push_back(2);
    originalVector.push_back(23);
    originalVector.push_back(3);
    originalVector.push_back(33);

    s21::vector<int>::iterator myIt = myVector.begin();
    std::vector<int>::iterator originalIt = originalVector.begin();

    myVector.erase(myIt);
    originalVector.erase(originalIt);
    EXPECT_EQ(myVector[0], originalVector[0]);
}

TEST(VectorModifiers, EraseV2) {
    s21::vector<int> myVector;
    std::vector<int> originalVector;
    myVector.push_back(2);
    myVector.push_back(23);
    myVector.push_back(3);
    myVector.push_back(33);

    originalVector.push_back(2);
    originalVector.push_back(23);
    originalVector.push_back(3);
    originalVector.push_back(33);

    s21::vector<int>::iterator myIt = myVector.begin();
    std::vector<int>::iterator originalIt = originalVector.begin();

    myVector.erase(myIt + 3);
    originalVector.erase(originalIt + 3);
    EXPECT_EQ(myVector[2], originalVector[2]);
}

TEST(VectorModifiers, PushBack) {
    s21::vector<int> myVector;
    std::vector<int> originalVector;
    myVector.push_back(2);
    myVector.push_back(23);
    myVector.push_back(3);
    myVector.push_back(33);

    originalVector.push_back(2);
    originalVector.push_back(23);
    originalVector.push_back(3);
    originalVector.push_back(33);

    for (size_t i = 0; i < myVector.size(); i++) {
        EXPECT_EQ(myVector[i], originalVector[i]);
    }
}

TEST(VectorModifiers, PopBack) {
    s21::vector<int> myVector;
    std::vector<int> originalVector;
    myVector.push_back(2);
    myVector.push_back(23);
    myVector.push_back(3);
    myVector.push_back(33);
    myVector.pop_back();
    myVector.pop_back();

    originalVector.push_back(2);
    originalVector.push_back(23);
    originalVector.push_back(3);
    originalVector.push_back(33);
    originalVector.pop_back();
    originalVector.pop_back();

    for (size_t i = 0; i < myVector.size(); i++) {
        EXPECT_EQ(myVector[i], originalVector[i]);
    }
}

TEST(VectorModifiers, Swap) {
    s21::vector<int> myVector{4, 4, 4};
    s21::vector<int> myVectorTemp{1, 2, 3};
    std::vector<int> originalVector{4, 4, 4};
    std::vector<int> originalVectorTemp{1, 2, 3};
    myVector.swap(myVectorTemp);
    originalVector.swap(originalVectorTemp);
    for (size_t i = 0; i < myVector.size(); i++) {
        EXPECT_EQ(myVector[i], originalVector[i]);
        EXPECT_EQ(myVectorTemp[i], originalVectorTemp[i]);
    }
}

TEST(VectorConstructor, SizeN) {
    s21::vector<int> myVector(5);
    EXPECT_EQ(myVector.capacity(), 5);

    EXPECT_THROW(s21::vector<int> myVector(-2), std::exception);
}

TEST(VectorConstructor, CopyConstruction) {
    s21::vector<int> myVector{4, 4, 4};
    s21::vector<int> myVectorTemp(myVector);
    for (size_t i = 0; i < myVector.size(); i++) {
        EXPECT_EQ(myVector[i], myVectorTemp[i]);
    }
}

TEST(VectorConstructor, OperatorEqual) {
    s21::vector<int> myVector{4, 4, 4};
    s21::vector<int> myVectorTemp = myVector;
    for (size_t i = 0; i < myVector.size(); i++) {
        EXPECT_EQ(myVector[i], 4);
    }
}

TEST(VectorConstructor, MoveConstructor) {
    s21::vector<int> myVector{4, 4, 4};
    s21::vector<int> myVectorTemp(std::move(myVector));
    for (size_t i = 0; i < myVectorTemp.size(); i++) {
        EXPECT_EQ(myVectorTemp[i], 4);
    }
}

TEST(VectorConstructor, MoveEqualConstructor) {
    s21::vector<int> myVector{4, 4, 4};
    s21::vector<int> myVectorTemp;
    myVectorTemp = std::move(myVector);
    for (size_t i = 0; i < myVectorTemp.size(); i++) {
        EXPECT_EQ(myVectorTemp[i], 4);
    }
}

TEST(VectorEmplace, EmplaceBackFirst) {
    s21::vector<int> myVector;
    myVector.emplace_back(4, 4, 4);
    for (size_t i = 0; i < myVector.size(); i++) {
        EXPECT_EQ(myVector[i], 4);
    }
}

TEST(VectorEmplace, EmplaceBackSecond) {
    s21::vector<int> myVector{4, 4};
    myVector.emplace_back(4);
    for (size_t i = 0; i < myVector.size(); i++) {
        EXPECT_EQ(myVector[i], 4);
    }
}

TEST(VectorEmplace, EmplaceFirst) {
    s21::vector<int> myVector;
    myVector.emplace(myVector.begin(), 4, 4, 4);
    for (size_t i = 0; i < myVector.size(); i++) {
        EXPECT_EQ(myVector[i], 4);
    }
}

TEST(VectorEmplace, EmplaceSecond) {
    s21::vector<int> myVector{4, 4};
    myVector.emplace(myVector.begin(), 4, 4, 4);
    for (size_t i = 0; i < myVector.size(); i++) {
        EXPECT_EQ(myVector[i], 4);
    }
}
