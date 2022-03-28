#include "../s21_map.h"

#define MAP_STRING                                                                         \
    {std::pair<int, std::string>(1, "set"),    std::pair<int, std::string>(2, "map"),      \
     std::pair<int, std::string>(3, "vector"), std::pair<int, std::string>(4, "multimap"), \
     std::pair<int, std::string>(5, "list"),   std::pair<int, std::string>(6, "array"),    \
     std::pair<int, std::string>(6, "stack"),  std::pair<int, std::string>(6, "queue")};

#define MAP_DOUBLE                                                                                          \
    {std::pair<int, double>(1, 12.21), std::pair<int, double>(2, 4.3),   std::pair<int, double>(3, 12.222), \
     std::pair<int, double>(4, 1.022), std::pair<int, double>(5, 1.212), std::pair<int, double>(8, 3.1),    \
     std::pair<int, double>(6, 23.2),  std::pair<int, double>(7, 34.43)};

TEST(MapElementAccess, At) {
    s21::map<int, std::string> myMap = MAP_STRING;
    std::map<int, std::string> originalMap = MAP_STRING;
    EXPECT_EQ(myMap.at(1), originalMap.at(1));
    EXPECT_EQ(myMap.at(4), originalMap.at(4));
    EXPECT_THROW(myMap.at(-12), std::exception);
}

TEST(MapElementAccess, OperatorSquare) {
    s21::map<int, std::string> myMap = MAP_STRING;
    std::map<int, std::string> originalMap = MAP_STRING;
    EXPECT_EQ(myMap[1], originalMap[1]);
    EXPECT_EQ(myMap[4], originalMap[4]);
    EXPECT_THROW(myMap[-12], std::exception);
}

TEST(MapCapacity, Empty) {
    s21::map<int, std::string> myMap = MAP_STRING;
    std::map<int, std::string> originalMap = MAP_STRING;
    EXPECT_EQ(myMap.empty(), originalMap.empty());

    s21::map<int, std::string> myMapTemp;
    std::map<int, std::string> originalMapTemp;
    EXPECT_EQ(myMapTemp.empty(), originalMapTemp.empty());
}

TEST(MapCapacity, Size) {
    s21::map<int, std::string> myMap = MAP_STRING;
    std::map<int, std::string> originalMap = MAP_STRING;
    EXPECT_EQ(myMap.size(), originalMap.size());
}

TEST(MapCapacity, MaxSize) {
    s21::map<int, std::string> myMap;
    EXPECT_EQ(myMap.max_size(), 4611686018427387903);
}

TEST(MapModifiers, Clear) {
    s21::map<int, std::string> myMap = MAP_STRING;
    std::map<int, std::string> originalMap = MAP_STRING;
    myMap.clear();
    originalMap.clear();
    EXPECT_EQ(myMap.size(), originalMap.size());
}

TEST(MapModifiers, InsertFirstSituation) {
    s21::map<int, std::string> myMap;
    std::map<int, std::string> originalMap;
    std::pair<int, std::string> p1 = {1, "set"};
    auto myPair = myMap.insert(p1);
    auto originalPair = originalMap.insert(p1);
    EXPECT_EQ((*(myPair.first)).first, (*(originalPair.first)).first);
    EXPECT_EQ((*(myPair.first)).second, (*(originalPair.first)).second);
    s21::map<int, std::string>::iterator myIt = myMap.begin();
    std::map<int, std::string>::iterator originalIt = originalMap.begin();
    for (size_t i = 0; i < myMap.size(); i++) {
        EXPECT_EQ((*myIt).first, (*originalIt).first);
        EXPECT_EQ((*myIt).second, (*originalIt).second);
        ++myIt;
        ++originalIt;
    }
}

TEST(MapModifiers, InsertSecondSituation) {
    s21::map<int, std::string> myMap = MAP_STRING;
    std::map<int, std::string> originalMap = MAP_STRING;
    std::pair<int, std::string> p1 = {11, "qwwq"};
    auto myPair = myMap.insert(p1);
    auto originalPair = originalMap.insert(p1);
    EXPECT_EQ((*(myPair.first)).first, (*(originalPair.first)).first);
    EXPECT_EQ((*(myPair.first)).second, (*(originalPair.first)).second);
    s21::map<int, std::string>::iterator myIt = myMap.begin();
    std::map<int, std::string>::iterator originalIt = originalMap.begin();
    for (size_t i = 0; i < myMap.size(); i++) {
        EXPECT_EQ((*myIt).first, (*originalIt).first);
        EXPECT_EQ((*myIt).second, (*originalIt).second);
        ++myIt;
        ++originalIt;
    }
}

TEST(MapModifiers, InsertThirdSituation) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    std::map<int, double> originalMap = MAP_DOUBLE;
    std::pair<int, double> p1 = {11, 21.21};
    auto myPair = myMap.insert(p1);
    auto originalPair = originalMap.insert(p1);
    EXPECT_EQ((*(myPair.first)).first, (*(originalPair.first)).first);
    EXPECT_EQ((*(myPair.first)).second, (*(originalPair.first)).second);
    s21::map<int, double>::iterator myIt = myMap.begin();
    std::map<int, double>::iterator originalIt = originalMap.begin();
    for (size_t i = 0; i < myMap.size(); i++) {
        EXPECT_EQ((*myIt).first, (*originalIt).first);
        EXPECT_EQ((*myIt).second, (*originalIt).second);
        ++myIt;
        ++originalIt;
    }
}

TEST(MapModifiers, InsertFirstSituationKey) {
    s21::map<int, std::string> myMap;
    std::map<int, std::string> originalMap;
    auto myPair = myMap.insert(1, "set");
    auto originalPair = originalMap.insert(std::pair<int, std::string>(1, "set"));
    EXPECT_EQ((*(myPair.first)).first, (*(originalPair.first)).first);
    EXPECT_EQ((*(myPair.first)).second, (*(originalPair.first)).second);
    s21::map<int, std::string>::iterator myIt = myMap.begin();
    std::map<int, std::string>::iterator originalIt = originalMap.begin();
    for (size_t i = 0; i < myMap.size(); i++) {
        EXPECT_EQ((*myIt).first, (*originalIt).first);
        EXPECT_EQ((*myIt).second, (*originalIt).second);
        ++myIt;
        ++originalIt;
    }
}

TEST(MapModifiers, InsertSecondSituationKey) {
    s21::map<int, std::string> myMap = MAP_STRING;
    std::map<int, std::string> originalMap = MAP_STRING;
    auto myPair = myMap.insert(11, "qwwq");
    auto originalPair = originalMap.insert(std::pair<int, std::string>(11, "qwwq"));
    EXPECT_EQ((*(myPair.first)).first, (*(originalPair.first)).first);
    EXPECT_EQ((*(myPair.first)).second, (*(originalPair.first)).second);
    s21::map<int, std::string>::iterator myIt = myMap.begin();
    std::map<int, std::string>::iterator originalIt = originalMap.begin();
    for (size_t i = 0; i < myMap.size(); i++) {
        EXPECT_EQ((*myIt).first, (*originalIt).first);
        EXPECT_EQ((*myIt).second, (*originalIt).second);
        ++myIt;
        ++originalIt;
    }
}

TEST(MapModifiers, InsertThirdSituationKey) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    std::map<int, double> originalMap = MAP_DOUBLE;
    auto myPair = myMap.insert(11, 21.21);
    auto originalPair = originalMap.insert(std::pair<int, double>(11, 21.21));
    EXPECT_EQ((*(myPair.first)).first, (*(originalPair.first)).first);
    EXPECT_EQ((*(myPair.first)).second, (*(originalPair.first)).second);
    s21::map<int, double>::iterator myIt = myMap.begin();
    std::map<int, double>::iterator originalIt = originalMap.begin();
    for (size_t i = 0; i < myMap.size(); i++) {
        EXPECT_EQ((*myIt).first, (*originalIt).first);
        EXPECT_EQ((*myIt).second, (*originalIt).second);
        ++myIt;
        ++originalIt;
    }
}

TEST(MapModifiers, EraseFirstElement) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    s21::map<int, double>::iterator myIt = myMap.begin();
    myMap.erase(myIt);
    std::map<int, double> originalMap = MAP_DOUBLE;
    std::map<int, double>::iterator originalIt = originalMap.begin();
    originalMap.erase(originalIt);
    s21::map<int, double>::iterator myItTemp = myMap.begin();
    std::map<int, double>::iterator originalItTemp = originalMap.begin();
    for (size_t i = 0; i < myMap.size(); i++) {
        EXPECT_EQ((*myItTemp).first, (*originalItTemp).first);
        EXPECT_EQ((*myItTemp).second, (*originalItTemp).second);
        ++myItTemp;
        ++originalItTemp;
    }
}

TEST(MapModifiers, EraseLastElement) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    s21::map<int, double>::iterator myIt = myMap.end();
    --myIt;
    myMap.erase(myIt);
    std::map<int, double> originalMap = MAP_DOUBLE;
    std::map<int, double>::iterator originalIt = originalMap.end();
    --originalIt;
    originalMap.erase(originalIt);
    s21::map<int, double>::iterator myItTemp = myMap.begin();
    std::map<int, double>::iterator originalItTemp = originalMap.begin();
    for (size_t i = 0; i < myMap.size(); i++) {
        EXPECT_EQ((*myItTemp).first, (*originalItTemp).first);
        EXPECT_EQ((*myItTemp).second, (*originalItTemp).second);
        ++myItTemp;
        ++originalItTemp;
    }
}

TEST(MapModifiers, swap) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    s21::map<int, double> myMapTemp{{1, 23}, {43, 12.21}};
    myMap.swap(myMapTemp);
    s21::map<int, double> myEq{{1, 23}, {43, 12.21}};
    s21::map<int, double>::iterator myIt = myMap.begin();
    s21::map<int, double>::iterator eqlIt = myEq.begin();
    for (size_t i = 0; i < myMap.size(); i++) {
        EXPECT_EQ((*myIt).first, (*eqlIt).first);
        EXPECT_EQ((*myIt).second, (*eqlIt).second);
        ++myIt;
        ++eqlIt;
    }
}

TEST(MapModifiers, Merge) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    s21::map<int, double> myMapTemp{{1, 23}, {43, 12.21}};
    std::map<int, double> originalMap = MAP_DOUBLE;
    std::map<int, double> originalMapTemp{{1, 23}, {43, 12.21}};
    myMap.merge(myMapTemp);
    originalMap.merge(originalMapTemp);
    s21::map<int, double>::iterator myIt = myMap.begin();
    std::map<int, double>::iterator originalIt = originalMap.begin();
    for (size_t i = 0; i < myMap.size(); i++) {
        EXPECT_EQ((*myIt).first, (*originalIt).first);
        EXPECT_EQ((*myIt).second, (*originalIt).second);
        ++myIt;
        ++originalIt;
    }
}

TEST(MapModifiers, Contains) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    auto myContains = myMap.contains(2);
    EXPECT_TRUE(myContains);
    myContains = myMap.contains(123);
    EXPECT_FALSE(myContains);
}

TEST(MapConstructor, MoveConstructor) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    s21::map<int, double> myMapTemp = MAP_DOUBLE;
    s21::map<int, double> copyMap(std::move(myMap));
    s21::map<int, double>::iterator myIt = myMapTemp.begin();
    s21::map<int, double>::iterator copyIt = copyMap.begin();
    for (size_t i = 0; i < myMapTemp.size(); i++) {
        EXPECT_EQ((*myIt).first, (*copyIt).first);
        EXPECT_EQ((*myIt).second, (*copyIt).second);
        ++myIt;
        ++copyIt;
    }
}

TEST(MapConstructor, OperatorEqual) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    s21::map<int, double> myMapTemp = MAP_DOUBLE;
    s21::map<int, double> copyMap = myMap;
    s21::map<int, double>::iterator myIt = myMapTemp.begin();
    s21::map<int, double>::iterator copyIt = copyMap.begin();
    for (size_t i = 0; i < copyMap.size(); i++) {
        EXPECT_EQ((*myIt).first, (*copyIt).first);
        EXPECT_EQ((*myIt).second, (*copyIt).second);
        ++myIt;
        ++copyIt;
    }
}

TEST(MapIterator, IteratorBegin) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    std::map<int, double> originalMap = MAP_DOUBLE;
    s21::map<int, double>::iterator myIt = myMap.begin();
    std::map<int, double>::iterator originalIt = originalMap.begin();
    EXPECT_EQ((*myIt).first, (*originalIt).first);
    EXPECT_EQ((*myIt).second, (*originalIt).second);
}

TEST(MapIterator, IteratorEnd) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    std::map<int, double> originalMap = MAP_DOUBLE;
    s21::map<int, double>::iterator myIt = myMap.end();
    std::map<int, double>::iterator originalIt = originalMap.end();
    --myIt;
    --originalIt;
    EXPECT_EQ((*myIt).first, (*originalIt).first);
    EXPECT_EQ((*myIt).second, (*originalIt).second);
}

TEST(MapIterator, IteratorPlus) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    std::map<int, double> originalMap = MAP_DOUBLE;
    s21::map<int, double>::iterator myIt = myMap.begin();
    std::map<int, double>::iterator originalIt = originalMap.begin();
    ++myIt;
    ++myIt;
    ++originalIt;
    ++originalIt;
    EXPECT_EQ((*myIt).first, (*originalIt).first);
    EXPECT_EQ((*myIt).second, (*originalIt).second);
}

TEST(MapIterator, IteratorMinus) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    std::map<int, double> originalMap = MAP_DOUBLE;
    s21::map<int, double>::iterator myIt = myMap.end();
    std::map<int, double>::iterator originalIt = originalMap.end();
    --myIt;
    --myIt;
    --originalIt;
    --originalIt;
    EXPECT_EQ((*myIt).first, (*originalIt).first);
    EXPECT_EQ((*myIt).second, (*originalIt).second);
}

TEST(MapIterator, IteratorEqual) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    std::map<int, double> originalMap = MAP_DOUBLE;
    s21::map<int, double>::iterator myIt = myMap.begin();
    std::map<int, double>::iterator originalIt = originalMap.begin();
    EXPECT_TRUE(myIt == myIt);
    EXPECT_TRUE((*myIt).first == (*originalIt).first);
    EXPECT_TRUE((*myIt).second == (*originalIt).second);
}

TEST(MapIterator, IteratorNotEqual) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    std::map<int, double> originalMap;
    originalMap.insert(std::pair<int, double>(11, 21.21));
    s21::map<int, double>::iterator myIt = myMap.begin();
    std::map<int, double>::iterator originalIt = originalMap.begin();
    EXPECT_FALSE((*myIt).first == (*originalIt).first);
    EXPECT_FALSE((*myIt).second == (*originalIt).second);
}

TEST(MapConstruction, MoveEqualConstructor) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    s21::map<int, double> myMapTemp;
    myMapTemp = std::move(myMap);
    EXPECT_FALSE(myMapTemp.empty());
}

TEST(MapEmplace, EmplaceFirst) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    auto myPair = myMap.emplace(std::pair<int, double>(123, 21), std::pair<int, double>(32, 221));
    EXPECT_EQ((*myPair[0].first).first, 123);
    EXPECT_EQ((*myPair[1].first).first, 32);
    EXPECT_EQ((*myPair[0].first).second, 21);
    EXPECT_EQ((*myPair[1].first).second, 221);
}

TEST(MapEmplace, EmplaceSecond) {
    s21::map<int, double> myMap;
    auto myPair = myMap.emplace();
    EXPECT_EQ(myPair.size(), 0);
}

TEST(MapEmplace, EmplaceThird) {
    s21::map<int, double> myMap = MAP_DOUBLE;
    auto myPair = myMap.emplace(std::pair<int, double>(1, 12.21));
    EXPECT_FALSE((*myPair[0].first).second);
}
