#include <Start.h>

#include "Solution.h"

typedef std::vector<int> VecInt;
typedef std::tuple<VecInt, int> TestCaseIn;
typedef VecInt TestCaseOut;
typedef std::tuple<TestCaseIn, TestCaseOut> TestCase;
typedef std::vector<TestCase> TestCases;

#include <SolFixture.h>

INSTANTIATE_TEST_SUITE_P(LeetCode, SolFixture,
                         ::testing::Values(
                             TestCase{
                                 TestCaseIn{{2, 7, 11, 15}, 9}, /* In */
                                 TestCaseOut{0, 1}              /* Out */
                             },
                             TestCase{
                                 TestCaseIn{{3, 2, 4}, 6}, /* In */
                                 TestCaseOut{1, 2}         /* Out */
                             },
                             TestCase{
                                 TestCaseIn{{3, 3}, 6}, /* In */
                                 TestCaseOut{0, 1}      /* Out */
                             }));

TEST_P(SolFixture, LeetCode) {
  TestCase testCase = GetParam();
  TestCaseIn &in = std::get<0>(testCase);
  TestCaseOut &out = std::get<1>(testCase);

  TestCaseOut res = sol.twoSum(std::get<0>(in), std::get<1>(in));

  std::sort(res.begin(), res.end());
  std::sort(out.begin(), out.end());

  ASSERT_TRUE(res == out);
}