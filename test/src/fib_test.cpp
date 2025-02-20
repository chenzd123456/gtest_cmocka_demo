#include <gtest/gtest.h>
#include "fib.h"
#include <stddef.h>
TEST(FibTest, HandlesZeroInput) {
    EXPECT_EQ(fib(0), 1);
}

TEST(FibTest, HandlesOneInput) {
    EXPECT_EQ(fib(1), 1);
}

TEST(FibTest, HandlesTwoInput) {
    EXPECT_EQ(fib(2), 1);
}

TEST(FibTest, HandlesPositiveInput) {
    EXPECT_EQ(fib(3), 2);
    EXPECT_EQ(fib(4), 3);
    EXPECT_EQ(fib(5), 5);
    EXPECT_EQ(fib(10), 55);
}