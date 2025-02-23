#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution1 {
  public:
    string gcdOfStrings(string str1, string str2) {
        string result;
        string_view shorter =
            min(str1, str2, [](const string &a, const string &b) {
                return a.length() < b.length();
            });

        for (size_t i = shorter.length(); i > 0; i--) {
            string_view prefix = shorter.substr(0, i);

            if (isDivisible(str1, prefix) && isDivisible(str2, prefix)) {
                result = prefix;
                break;
            }
        }

        return result;
    }

  private:
    bool isDivisible(string_view dividend, string_view divisor) {
        if (dividend.length() % divisor.length() != 0) {
            return false;
        }

        for (size_t i = 0; i < dividend.length(); i += divisor.length()) {
            string_view substr = dividend.substr(i, divisor.length());
            if (substr != divisor) {
                return false;
            }
        }

        return true;
    }
};

class GcdOfStringsTest1 : public ::testing::Test {
  protected:
    Solution1 solution;
};

TEST_F(GcdOfStringsTest1, BasicCases) {
    EXPECT_EQ(solution.gcdOfStrings("ABCABC", "ABC"), "ABC");
    EXPECT_EQ(solution.gcdOfStrings("ABABAB", "ABAB"), "AB");
    EXPECT_EQ(solution.gcdOfStrings("LEET", "CODE"), "");
}

TEST_F(GcdOfStringsTest1, EqualStrings) {
    EXPECT_EQ(solution.gcdOfStrings("AAAA", "AAAA"), "AAAA");
}

TEST_F(GcdOfStringsTest1, NoCommonDivisor) {
    EXPECT_EQ(solution.gcdOfStrings("ABCDEF", "ABC"), "");
}

TEST_F(GcdOfStringsTest1, RepeatedDivisor) {
    EXPECT_EQ(solution.gcdOfStrings("ABCABCABC", "ABCABC"), "ABC");
}

class Solution2 {
  public:
    string gcdOfStrings(string str1, string str2) {
        string result;
        string_view shorter =
            min(str1, str2, [](const string &a, const string &b) {
                return a.length() < b.length();
            });
        size_t length = gcd(str1.length(), str2.length());
        string_view prefix = shorter.substr(0, length);

        if (isDivisible(str1, prefix) && isDivisible(str2, prefix)) {
            result = prefix;
        }

        return result;
    }

  private:
    bool isDivisible(string_view dividend, string_view divisor) {
        if (dividend.length() % divisor.length() != 0) {
            return false;
        }

        for (size_t i = 0; i < dividend.length(); i += divisor.length()) {
            string_view substr = dividend.substr(i, divisor.length());
            if (substr != divisor) {
                return false;
            }
        }

        return true;
    }
};

class GcdOfStringsTest2 : public ::testing::Test {
  protected:
    Solution2 solution;
};

TEST_F(GcdOfStringsTest2, BasicCases) {
    EXPECT_EQ(solution.gcdOfStrings("ABCABC", "ABC"), "ABC");
    EXPECT_EQ(solution.gcdOfStrings("ABABAB", "ABAB"), "AB");
    EXPECT_EQ(solution.gcdOfStrings("LEET", "CODE"), "");
}

TEST_F(GcdOfStringsTest2, EqualStrings) {
    EXPECT_EQ(solution.gcdOfStrings("AAAA", "AAAA"), "AAAA");
}

TEST_F(GcdOfStringsTest2, NoCommonDivisor) {
    EXPECT_EQ(solution.gcdOfStrings("ABCDEF", "ABC"), "");
}

TEST_F(GcdOfStringsTest2, RepeatedDivisor) {
    EXPECT_EQ(solution.gcdOfStrings("ABCABCABC", "ABCABC"), "ABC");
}