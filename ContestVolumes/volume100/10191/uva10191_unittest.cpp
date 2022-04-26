#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

#include "uva10191.cpp"

TEST(UVa10191Test, Time_Hour) {
  EXPECT_EQ(0, Time("00:10").Hour());
  EXPECT_EQ(5, Time("05:10").Hour());
}

TEST(UVa10191Test, Time_Minutes) {
  EXPECT_EQ(10, Time("00:10").Minutes());
  EXPECT_EQ(23, Time("08:23").Minutes());
}

TEST(UVa10191Test, Time_ToMinutes) {
  EXPECT_EQ(10, Time("00:10").ToMinutes());
  EXPECT_EQ(60 * 5 + 10, Time("05:10").ToMinutes());
}

TEST(UVa10191Test, Solution) {
  auto Solve = [](std::istream& is) -> std::string {
    testing::internal::CaptureStdout();
    Solution(is);
    return std::string("\n") + testing::internal::GetCapturedStdout();
  };

  {
    std::stringstream fake_cin;
    fake_cin << R"(
4
10:00 12:00 Lectures
12:00 13:00 Lunch, like always.
13:00 15:00 Boring lectures...
15:30 17:45 Reading
4
10:00 12:00 Lectures
12:00 13:00 Lunch, just lunch.
13:00 15:00 Lectures, lectures... oh, no!
16:45 17:45 Reading (to be or not to be?)
4
10:00 12:00 Lectures, as everyday.
12:00 13:00 Lunch, again!!!
13:00 15:00 Lectures, more lectures!
15:30 17:15 Reading (I love reading, but should I schedule it?)
1
12:00 13:00 I love lunch! Have you ever noticed it? :)
)";

    EXPECT_EQ(
        R"(
Day #1: the longest nap starts at 15:00 and will last for 30 minutes.
Day #2: the longest nap starts at 15:00 and will last for 1 hours and 45 minutes.
Day #3: the longest nap starts at 17:15 and will last for 45 minutes.
Day #4: the longest nap starts at 13:00 and will last for 5 hours and 0 minutes.
)",
        Solve(fake_cin));
  }
}
