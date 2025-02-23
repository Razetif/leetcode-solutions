#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        vector<bool> result(candies.size());
        int maxCandy = *max_element(candies.begin(), candies.end());

        for (size_t i = 0; i < candies.size(); i++) {
            result[i] = candies[i] + extraCandies >= maxCandy;
        }

        return result;
    }
};

class KidsWithCandiesTest : public ::testing::Test {
  protected:
    Solution solution;
};

TEST_F(KidsWithCandiesTest, BasicCases) {
    vector<int> candies;
    int extraCandies;

    candies = {2, 3, 5, 1, 3};
    extraCandies = 3;
    EXPECT_EQ(solution.kidsWithCandies(candies, extraCandies),
              vector<bool>({true, true, true, false, true}));

    candies = {4, 2, 1, 1, 2};
    extraCandies = 1;
    EXPECT_EQ(solution.kidsWithCandies(candies, extraCandies),
              vector<bool>({true, false, false, false, false}));

    candies = {12, 1, 12};
    extraCandies = 10;
    EXPECT_EQ(solution.kidsWithCandies(candies, extraCandies),
              vector<bool>({true, false, true}));
}

TEST_F(KidsWithCandiesTest, EdgeCases) {
    vector<int> candies;
    int extraCandies;

    candies = {1, 1, 1, 1, 1};
    extraCandies = 50;
    EXPECT_EQ(solution.kidsWithCandies(candies, extraCandies),
              vector<bool>({true, true, true, true, true}));

    candies = {100, 99, 98, 97, 96};
    extraCandies = 1;
    EXPECT_EQ(solution.kidsWithCandies(candies, extraCandies),
              vector<bool>({true, true, false, false, false}));

    candies = {1, 2};
    extraCandies = 50;
    EXPECT_EQ(solution.kidsWithCandies(candies, extraCandies),
              vector<bool>({true, true}));
}