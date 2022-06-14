#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

#include "uva608.cpp"

TEST(UVa608Test, Solution) {
  auto Solve = [](std::istream& is) -> std::string {
    testing::internal::CaptureStdout();
    Solution(is);
    return std::string("\n") + testing::internal::GetCapturedStdout();
  };

  {
    std::stringstream fake_cin;
    fake_cin << R"(
1
ABCD EFGH even
ABCI EFJK up
ABIJ EFGH even
)";

    EXPECT_EQ(R"(
K is the counterfeit coin and it is light.
)",
              Solve(fake_cin));
  }
}
