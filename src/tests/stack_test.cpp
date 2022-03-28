#include "../s21_stack.h"

TEST(stack_constructor_suit, default_constructor) {
    s21::stack<int> s21Stack;
    std::stack<int> stdStack;
    ASSERT_EQ(s21Stack.empty(), stdStack.empty());
}

TEST(stack_constructor_suit, init_constructor) {
    s21::stack<int> s21Stack{1, 2, 3};
    ASSERT_FALSE(s21Stack.empty());
}

TEST(stack_constructor_suit, init_string_constructor) {
    s21::stack<std::string> s21Stack{"hello", "world"};
    ASSERT_EQ(s21Stack.top(), "world");
}

TEST(stack_constructor_suit, copy_constructor) {
    s21::stack<int> s21Stack{1};
    s21::stack<int> s21QueueCopied(s21Stack);
    ASSERT_EQ(s21Stack.top(), s21QueueCopied.top());
}

TEST(stack_constructor_suit, move_constructor) {
    s21::stack<int> s21Stack{1, 2, 3};
    s21::stack<int> s21QueueMoved(std::move(s21Stack));
    ASSERT_TRUE(s21Stack.empty());
    ASSERT_FALSE(s21QueueMoved.empty());
}

TEST(stack_constructor_suit, move_operator_constructor) {
    s21::stack<int> s21Stack{1, 2, 3};
    s21::stack<int> s21QueueMoved;
    s21QueueMoved = std::move(s21Stack);
    ASSERT_TRUE(s21Stack.empty());
    ASSERT_FALSE(s21QueueMoved.empty());
}

TEST(stack_push_suit, push_int) {
    s21::stack<int> s21Stack;
    s21Stack.push(566);
    std::stack<int> stdStack;
    stdStack.push(566);
    ASSERT_EQ(s21Stack.top(), stdStack.top());
}

TEST(stack_push_suit, push_int2) {
    s21::stack<int> s21Stack;
    s21Stack.push(3);
    s21Stack.push(4);
    s21Stack.pop();
    std::stack<int> stdStack;
    stdStack.push(3);
    ASSERT_EQ(s21Stack.top(), stdStack.top());
}


TEST(stack_pop_suit, pop_int) {
    s21::stack<int> s21Stack{566, 123};
    std::stack<int> stdStack;
    stdStack.push(566);
    stdStack.push(123);
    ASSERT_EQ(s21Stack.top(), stdStack.top());
    s21Stack.pop();
    stdStack.pop();
    ASSERT_EQ(s21Stack.top(), stdStack.top());
}

TEST(stack_pop_suit, pop_string) {
    s21::stack<std::string> s21Stack{"hello", "world"};
    std::stack<std::string> stdStack;
    stdStack.push("hello");
    stdStack.push("world");
    s21Stack.pop();
    stdStack.pop();
    ASSERT_EQ(s21Stack.top(), stdStack.top());
}

TEST(stack_size_suit, size) {
    s21::stack<int> s21Stack{566, 123, 3, 3, 2, 1};
    s21::stack<int> s21Stack2{566, 123};
    ASSERT_EQ(s21Stack.size(), 6);
    ASSERT_EQ(s21Stack2.size(), 2);
}

TEST(stack_swap_suit, swap) {
    s21::stack<int> s21Stack{566, 123, 3, 3, 2, 1};
    s21::stack<int> s21Stack2{566, 123};
    s21Stack.swap(s21Stack2);
    ASSERT_EQ(s21Stack.size(), 2);
    ASSERT_EQ(s21Stack2.size(), 6);
}

TEST(stack_emplace_suit, emplace_front) {
    s21::stack<int> s21Stack{5, 5, 5};
    s21Stack.emplace_front(3, 3);
    ASSERT_EQ(s21Stack.size(), 5);
    ASSERT_EQ(s21Stack.top(), 3);
    s21Stack.pop();
    ASSERT_EQ(s21Stack.top(), 3);
    s21Stack.pop();
    ASSERT_EQ(s21Stack.top(), 5);
}
