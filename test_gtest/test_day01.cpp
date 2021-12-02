#include <gtest/gtest.h>

extern long count_increases(const std::vector<int> & input);

class Tests : public ::testing::Test {};

TEST_F(Tests, test_count_increases) {
    std::vector<int> input {
        199,
        200,
        208,
        210,
        200,
        207,
        240,
        269,
        260,
        263};

    EXPECT_EQ(7, count_increases(input));
}
