#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        vector<int> result(nums.size());

        for (size_t i = 0; i < nums.size(); i++) {
            prefix[i] = (i == 0 ? 1 : prefix[i - 1]) * nums[i];
            size_t j = nums.size() - i - 1;
            suffix[j] = (j == nums.size() - 1 ? 1 : suffix[j + 1]) * nums[j];
        }
        for (size_t i = 0; i < nums.size(); i++) {
            result[i] = (i == 0 ? 1 : prefix[i - 1]) *
                        (i == nums.size() - 1 ? 1 : suffix[i + 1]);
        }

        return result;
    }
};

class ProductExceptSelfTest : public ::testing::Test {
  protected:
    Solution solution;
};

TEST_F(ProductExceptSelfTest, BasicCases) {
    vector<int> nums;

    nums = {1, 2, 3, 4};
    EXPECT_EQ(solution.productExceptSelf(nums), vector<int>({24, 12, 8, 6}));

    nums = {-1, 1, 0, -3, 3};
    EXPECT_EQ(solution.productExceptSelf(nums), vector<int>({0, 0, 9, 0, 0}));
}

TEST_F(ProductExceptSelfTest, EdgeCases) {
    vector<int> nums;

    nums = {1, 1};
    EXPECT_EQ(solution.productExceptSelf(nums), vector<int>({1, 1}));

    nums = {-1, 1};
    EXPECT_EQ(solution.productExceptSelf(nums), vector<int>({1, -1}));
}