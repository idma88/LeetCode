#include <Start.h>

#include "Solution.h"

typedef std::tuple<std::string, int> TestCaseIn;
typedef std::string TestCaseOut;
typedef std::tuple<TestCaseIn, TestCaseOut> TestCase;
typedef std::vector<TestCase> TestCases;

#include <SolFixture.h>

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SolFixture,
    ::testing::Values(TestCase{TestCaseIn{std::string("PAYPALISHIRING"), 3},
                               std::string("PAHNAPLSIIGYIR")},
                      TestCase{TestCaseIn{std::string("PAYPALISHIRING"), 4},
                               std::string("PINALSIGYAHRPI")},
                      TestCase{TestCaseIn{std::string("A"), 1}, "A"},
                      TestCase{TestCaseIn{std::string("AB"), 1}, "AB"}));

TEST_P(SolFixture, LeetCode) {
  TestCase testCase = GetParam();
  TestCaseIn &in = std::get<0>(testCase);
  TestCaseOut &out = std::get<1>(testCase);

  TestCaseOut res = sol.convert(std::get<0>(in), std::get<1>(in));

  EXPECT_STREQ(res.c_str(), out.c_str());
}