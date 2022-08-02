#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

#include "uva10377.cpp"

TEST(UVa10377Test, Solution) {
  auto Solve = [](std::istream& is) -> std::string {
    testing::internal::CaptureStdout();
    Solution(is);
    return std::string("\n") + testing::internal::GetCapturedStdout();
  };

  {
    std::stringstream fake_cin;
    fake_cin << R"(
1
7 8
********
* * * **
* *    *
* * ** *
* * *  *
*   * **
********
2 4
RRFLFF FFR
FF
RFFQ
)";

    EXPECT_EQ(R"(
5 6 W
)",
              Solve(fake_cin));
  }
}
