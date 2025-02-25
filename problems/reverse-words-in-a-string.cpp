#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    string reverseWords(string s) {
        string result;
        vector<string> words;
        stringstream ss(s);
        string word;

        while (getline(ss, word, ' ')) {
            if (!word.empty()) {
                words.push_back(word);
            }
        }

        for (size_t i = words.size(); i-- > 0;) {
            result += words[i];
            if (i != 0) {
                result += ' ';
            }
        }

        return result;
    }
};

class ReverseWordsTest : public ::testing::Test {
  protected:
    Solution solution;
};

TEST_F(ReverseWordsTest, BasicCases) {
    EXPECT_EQ(solution.reverseWords("the sky is blue"), "blue is sky the");
    EXPECT_EQ(solution.reverseWords("  hello world  "), "world hello");
    EXPECT_EQ(solution.reverseWords("a good   example"), "example good a");
}

TEST_F(ReverseWordsTest, EdgeCases) {
    EXPECT_EQ(solution.reverseWords("a"), "a");
    EXPECT_EQ(solution.reverseWords("123"), "123");
    EXPECT_EQ(solution.reverseWords("abc   "), "abc");
    EXPECT_EQ(solution.reverseWords("   abc"), "abc");
}