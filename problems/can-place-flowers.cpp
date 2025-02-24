#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        for (size_t i = 0; i < flowerbed.size() && n > 0; i++) {
            bool leftOk = true;
            if (i > 0) {
                leftOk = flowerbed[i - 1] == 0;
            }

            bool middleOk = flowerbed[i] == 0;

            bool rightOk = true;
            if (i < flowerbed.size() - 1) {
                rightOk = flowerbed[i + 1] == 0;
            }

            if (leftOk && middleOk && rightOk) {
                flowerbed[i] = 1;
                n--;
            }
        }

        return n == 0;
    }
};

class CanPlaceFlowersTest : public ::testing::Test {
  protected:
    Solution solution;
};

TEST_F(CanPlaceFlowersTest, BasicCases) {
    vector<int> flowerbed;
    int n;

    flowerbed = {1, 0, 0, 0, 1};
    n = 1;
    EXPECT_EQ(solution.canPlaceFlowers(flowerbed, n), true);

    flowerbed = {1, 0, 0, 0, 1};
    n = 2;
    EXPECT_EQ(solution.canPlaceFlowers(flowerbed, n), false);

    flowerbed = {1, 0, 0, 0, 0, 1};
    n = 2;
    EXPECT_EQ(solution.canPlaceFlowers(flowerbed, n), false);

    flowerbed = {1, 0, 1, 0, 1, 0, 1};
    n = 1;
    EXPECT_EQ(solution.canPlaceFlowers(flowerbed, n), false);
}

TEST_F(CanPlaceFlowersTest, EdgeCases) {
    vector<int> flowerbed;
    int n;

    flowerbed = {1};
    n = 1;
    EXPECT_EQ(solution.canPlaceFlowers(flowerbed, n), false);

    flowerbed = {0};
    n = 1;
    EXPECT_EQ(solution.canPlaceFlowers(flowerbed, n), true);

    flowerbed = {0, 1};
    n = 1;
    EXPECT_EQ(solution.canPlaceFlowers(flowerbed, n), false);

    flowerbed = {0, 0, 0};
    n = 1;
    EXPECT_EQ(solution.canPlaceFlowers(flowerbed, n), true);

    flowerbed = {0, 0, 0};
    n = 0;
    EXPECT_EQ(solution.canPlaceFlowers(flowerbed, n), true);

    flowerbed = {0, 0, 1, 0, 1};
    n = 1;
    EXPECT_EQ(solution.canPlaceFlowers(flowerbed, n), true);

    flowerbed = {1, 0, 1, 0, 0};
    n = 1;
    EXPECT_EQ(solution.canPlaceFlowers(flowerbed, n), true);
}