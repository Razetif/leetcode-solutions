#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int add(int a, int b) { return a + b; }
};

class AddTest : public ::testing::Test {
  protected:
    Solution solution;
};

TEST_F(AddTest, PositiveNumbers) {
    EXPECT_EQ(solution.add(1, 1), 2);
    EXPECT_EQ(solution.add(1, 2), 3);
    EXPECT_EQ(solution.add(2, 2), 4);
}

TEST_F(AddTest, NegativeNumbers) {
    EXPECT_EQ(solution.add(-1, -1), -2);
    EXPECT_EQ(solution.add(-1, -2), -3);
    EXPECT_EQ(solution.add(-2, -2), -4);
}