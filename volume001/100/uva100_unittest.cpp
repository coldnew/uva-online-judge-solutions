#include <gtest/gtest.h>

#include "uva100.cpp"

namespace {

std::string SolveByCaptureStdout(uint32_t start, uint32_t end) {
  testing::internal::CaptureStdout();
  Solve(start, end);
  return testing::internal::GetCapturedStdout();
}

}  // namespace

TEST(UVa100Test, Solve) {
  EXPECT_STREQ(SolveByCaptureStdout(1, 10).c_str(), "1 10 20\n");
  EXPECT_STREQ(SolveByCaptureStdout(100, 200).c_str(), "100 200 125\n");
  EXPECT_STREQ(SolveByCaptureStdout(201, 210).c_str(), "201 210 89\n");
  EXPECT_STREQ(SolveByCaptureStdout(900, 1000).c_str(), "900 1000 174\n");
}
