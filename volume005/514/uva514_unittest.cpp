#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

#include "uva514.cpp"

TEST(UVa514Test, Solution) {
  auto Solve = [](std::istream& is) -> std::string {
    testing::internal::CaptureStdout();
    Solution(is);
    return std::string("\n") + testing::internal::GetCapturedStdout();
  };

  {
    std::stringstream fake_cin;
    fake_cin << R"(
5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0
)";

    EXPECT_EQ(
        R"(
Yes
No

Yes

)",
        Solve(fake_cin));
  }
}
