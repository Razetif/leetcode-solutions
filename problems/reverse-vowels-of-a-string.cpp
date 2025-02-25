#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution1 {
  public:
    string reverseVowels(string s) {
        vector<char> vowels;

        for (size_t i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                vowels.push_back(s[i]);
            }
        }

        reverse(vowels.begin(), vowels.end());

        size_t j = 0;
        for (size_t i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[j++];
            }
        }

        return s;
    }

  private:
    bool isVowel(char c) {
        bool lowercase =
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        bool uppercase =
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        return lowercase || uppercase;
    }
};

class ReverseVowelsTest1 : public ::testing::Test {
  protected:
    Solution1 solution;
};

TEST_F(ReverseVowelsTest1, BasicCases) {
    EXPECT_EQ(solution.reverseVowels("IceCreAm"), "AceCreIm");
    EXPECT_EQ(solution.reverseVowels("leetcode"), "leotcede");
}

TEST_F(ReverseVowelsTest1, EdgeCases) {
    EXPECT_EQ(solution.reverseVowels("aeiou"), "uoiea");
    EXPECT_EQ(solution.reverseVowels("AEIOU"), "UOIEA");
    EXPECT_EQ(solution.reverseVowels("bcdfg"), "bcdfg");
}

class Solution2 {
  public:
    string reverseVowels(string s) {
        size_t left = 0;
        size_t right = s.length() - 1;

        while (left < right) {
            while (left < right && !isVowel(s[left])) {
                left++;
            }

            while (left < right && !isVowel(s[right])) {
                right--;
            }

            swap(s[left], s[right]);

            left++;
            if (right != 0) {
                right--;
            } else {
                break;
            }
        }

        return s;
    }

  private:
    bool isVowel(char c) {
        bool lowercase =
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        bool uppercase =
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        return lowercase || uppercase;
    }
};

class ReverseVowelsTest2 : public ::testing::Test {
  protected:
    Solution2 solution;
};

TEST_F(ReverseVowelsTest2, BasicCases) {
    EXPECT_EQ(solution.reverseVowels("IceCreAm"), "AceCreIm");
    EXPECT_EQ(solution.reverseVowels("leetcode"), "leotcede");
}

TEST_F(ReverseVowelsTest2, EdgeCases) {
    EXPECT_EQ(solution.reverseVowels("aeiou"), "uoiea");
    EXPECT_EQ(solution.reverseVowels("AEIOU"), "UOIEA");
    EXPECT_EQ(solution.reverseVowels("bcdfg"), "bcdfg");
    EXPECT_EQ(solution.reverseVowels("a"), "a");
    EXPECT_EQ(solution.reverseVowels("b"), "b");
    EXPECT_EQ(solution.reverseVowels("a."), "a.");
}