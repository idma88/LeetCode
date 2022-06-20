#include <Start.h>

#include "Solution.h"

typedef std::vector<int> VecInt;
typedef std::tuple<VecInt, VecInt> TestCaseIn;
typedef double TestCaseOut;
typedef std::tuple<TestCaseIn, TestCaseOut> TestCase;
typedef std::vector<TestCase> TestCases;

#include <SolFixture.h>

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SolFixture,
    ::testing::Values(TestCase{TestCaseIn{{1, 3}, {2}}, 2.0},
                      TestCase{TestCaseIn{{1, 2}, {3, 4}}, 2.5},
                      TestCase{TestCaseIn{{}, {}}, 0.0}));

TEST_P(SolFixture, LeetCode) {
  TestCase testCase = GetParam();
  TestCaseIn &in = std::get<0>(testCase);
  TestCaseOut &out = std::get<1>(testCase);

  TestCaseOut res = sol.findMedianSortedArrays(std::get<0>(in), std::get<1>(in));

  ASSERT_DOUBLE_EQ(res, out);
}