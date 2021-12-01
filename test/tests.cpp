#include <gtest/gtest.h>

class Tests : public ::testing::Test {};

TEST_F(Tests, test_something) {
    EXPECT_TRUE(0);
}
