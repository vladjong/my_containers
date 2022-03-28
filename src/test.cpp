#include <gtest/gtest.h>
#include <queue>
#include <string>
#include <array>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <list>

#include "tests/array_test.cpp"
#include "tests/queue_test.cpp"
#include "tests/stack_test.cpp"
#include "tests/test_map.cpp"
#include "tests/test_multiset.cpp"
#include "tests/test_set.cpp"
#include "tests/test_vector.cpp"
#include "tests/list_test.cpp"

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
