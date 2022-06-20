/**
 * You need to define `class Solution` before include this file
 * You need to define `TestCase` before include this file
 */

#pragma once

#include "gtest/gtest.h"

class SolFixture : public ::testing::TestWithParam<TestCase> {
protected:
  void SetUp() {}
  void TearDown() {}

public:
  Solution sol;
};
