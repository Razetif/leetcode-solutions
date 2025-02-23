#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution1 {
  public:
    string mergeAlternately(string word1, string word2) {
        string result;
        size_t i = 0;
        size_t j = 0;

        while (i < word1.length() && j < word2.length()) {
            if (i <= j) {
                result += word1[i++];
            } else {
                result += word2[j++];
            }
        }

        if (i < word1.length()) {
            result += word1.substr(i);
        }

        if (j < word2.length()) {
            result += word2.substr(j);
        }

        return result;
    }
};

class MergeAlternatelyTest1 : public ::testing::Test {
  protected:
    Solution1 solution;
};

TEST_F(MergeAlternatelyTest1, BasicCases) {
    EXPECT_EQ(solution.mergeAlternately("abc", "pqr"), "apbqcr");
    EXPECT_EQ(solution.mergeAlternately("ab", "pqrs"), "apbqrs");
    EXPECT_EQ(solution.mergeAlternately("abcd", "pq"), "apbqcd");
}

TEST_F(MergeAlternatelyTest1, EdgeCases) {
    EXPECT_EQ(solution.mergeAlternately("abc", "d"), "adbc");
    EXPECT_EQ(solution.mergeAlternately("a", "bcd"), "abcd");
    EXPECT_EQ(solution.mergeAlternately("a", "b"), "ab");
}

class Solution2 {
  public:
    string mergeAlternately(string word1, string word2) {
        string result;
        size_t i = 0;
        size_t j = 0;

        while (i < word1.length() || j < word2.length()) {
            if (i < word1.length()) {
                result += word1[i++];
            }

            if (j < word2.length()) {
                result += word2[j++];
            }
        }

        return result;
    }
};

class MergeAlternatelyTest2 : public ::testing::Test {
  protected:
    Solution2 solution;
};

TEST_F(MergeAlternatelyTest2, BasicCases) {
    EXPECT_EQ(solution.mergeAlternately("abc", "pqr"), "apbqcr");
    EXPECT_EQ(solution.mergeAlternately("ab", "pqrs"), "apbqrs");
    EXPECT_EQ(solution.mergeAlternately("abcd", "pq"), "apbqcd");
}

TEST_F(MergeAlternatelyTest2, EdgeCases) {
    EXPECT_EQ(solution.mergeAlternately("abc", "d"), "adbc");
    EXPECT_EQ(solution.mergeAlternately("a", "bcd"), "abcd");
    EXPECT_EQ(solution.mergeAlternately("a", "b"), "ab");
}

class Solution3 {
  public:
    string mergeAlternately(string word1, string word2) {
        string result;
        size_t maxLength = max(word1.length(), word2.length());

        for (size_t i = 0; i < maxLength; i++) {
            if (i < word1.length()) {
                result += word1[i];
            }

            if (i < word2.length()) {
                result += word2[i];
            }
        }

        return result;
    }
};

class MergeAlternatelyTest3 : public ::testing::Test {
  protected:
    Solution3 solution;
};

TEST_F(MergeAlternatelyTest3, BasicCases) {
    EXPECT_EQ(solution.mergeAlternately("abc", "pqr"), "apbqcr");
    EXPECT_EQ(solution.mergeAlternately("ab", "pqrs"), "apbqrs");
    EXPECT_EQ(solution.mergeAlternately("abcd", "pq"), "apbqcd");
}

TEST_F(MergeAlternatelyTest3, EdgeCases) {
    EXPECT_EQ(solution.mergeAlternately("abc", "d"), "adbc");
    EXPECT_EQ(solution.mergeAlternately("a", "bcd"), "abcd");
    EXPECT_EQ(solution.mergeAlternately("a", "b"), "ab");
}