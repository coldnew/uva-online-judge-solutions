#include <gtest/gtest.h>

#include "uva246.cpp"

TEST(UVa246Test, Solution) {
  auto Solve = [](std::istream& is) -> std::string {
    testing::internal::CaptureStdout();
    Solution(is);
    return std::string("\n") + testing::internal::GetCapturedStdout();
  };

  {
    std::stringstream fake_cin;
    fake_cin << R"(
2 6 5 10 10 4 10 10 10 4 5 10 4 5 10 9 7 6 1 7 6 9 5 3 10 10 4 10 9 2 1
10 1 10 10 10 3 10 9 8 10 8 7 1 2 8 6 7 3 3 8 2
4 3 2 10 8 10 6 8 9 5 8 10 5 3 5 4 6 9 9 1 7 6 3 5 10 10 8 10 9 10 10 7
2 6 10 10 4 10 1 3 10 1 1 10 2 2 10 4 10 7 7 10
10 5 4 3 5 7 10 8 2 3 9 10 8 4 5 1 7 6 7 2 6 9 10 2 3 10 3 4 4 9 10 1 1
10 5 10 10 1 8 10 7 8 10 6 10 10 10 9 6 2 10 10
0
)";

    EXPECT_EQ(
        R"(
Win : 66
Loss: 82
Draw: 73
)",
        Solve(fake_cin));
  }
}
