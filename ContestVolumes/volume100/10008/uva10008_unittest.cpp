#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

#include "uva10008.cpp"

TEST(UVa10008Test, Solution) {
  auto Solve = [](std::istream& is) -> std::string {
    testing::internal::CaptureStdout();
    Solution(is);
    return std::string("\n") + testing::internal::GetCapturedStdout();
  };

  {
    std::stringstream fake_cin;
    fake_cin << R"(3
This is a test
Count me 1 2 3 4 5
Wow!!!! Is this question easy?)";

    EXPECT_EQ(
        R"(
S 7
T 6
I 5
E 4
O 3
A 2
H 2
N 2
U 2
W 2
C 1
M 1
Q 1
Y 1
)",
        Solve(fake_cin));
  }
}
