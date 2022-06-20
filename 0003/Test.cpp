#include <Start.h>

#include "Solution.h"

typedef std::string TestCaseIn;
typedef int TestCaseOut;
typedef std::tuple<TestCaseIn, TestCaseOut> TestCase;
typedef std::vector<TestCase> TestCases;

#include <SolFixture.h>

INSTANTIATE_TEST_SUITE_P(LeetCode, SolFixture,
                         ::testing::Values(TestCase{"abcabcbb", 3},
                                           TestCase{"bbbbb", 1},
                                           TestCase{"pwwkew", 3},
                                           TestCase{" ", 1},
                                           TestCase{"dvdf", 3}));

TEST_P(SolFixture, LeetCode) {
  TestCase testCase = GetParam();
  TestCaseIn &in = std::get<0>(testCase);
  TestCaseOut &out = std::get<1>(testCase);

  int res = sol.lengthOfLongestSubstring(in);

  ASSERT_TRUE(res == out);
}