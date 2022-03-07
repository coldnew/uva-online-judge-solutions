#include <gtest/gtest.h>

#include "uva263.cpp"

TEST(UVa263Test, IntVectorToInt32) {
  EXPECT_EQ(4444, IntVectorToInt32(std::vector<int>{4, 4, 4, 4}));
  EXPECT_EQ(123456789,
            IntVectorToInt32(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

TEST(UVa263Test, Ascending) {
  EXPECT_EQ(4444, Ascending(std::vector<int>{4, 4, 4, 4}));
  EXPECT_EQ(123456789, Ascending(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}));
  EXPECT_EQ(123456789, Ascending(std::vector<int>{1, 9, 2, 6, 7, 8, 3, 5, 4}));
  EXPECT_EQ(456, Ascending(std::vector<int>{6, 5, 4}));
}

TEST(UVa263Test, Descending) {
  EXPECT_EQ(4444, Descending(std::vector<int>{4, 4, 4, 4}));
  EXPECT_EQ(987654321, Descending(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}));
  EXPECT_EQ(987654321, Descending(std::vector<int>{1, 9, 2, 6, 7, 8, 3, 5, 4}));
  EXPECT_EQ(654, Descending(std::vector<int>{6, 5, 4}));
}

namespace {

std::string SolveByCaptureStdout(uint32_t n) {
  testing::internal::CaptureStdout();
  Solve(n);
  return testing::internal::GetCapturedStdout();
}

}  // namespace

TEST(UVa263Test, Solver) {
  EXPECT_STREQ(SolveByCaptureStdout(123456789).c_str(),
               "Original number was 123456789\n"
               "987654321 - 123456789 = 864197532\n"
               "987654321 - 123456789 = 864197532\n"
               "Chain length 2\n");

  EXPECT_STREQ(SolveByCaptureStdout(1234).c_str(),
               "Original number was 1234\n"
               "4321 - 1234 = 3087\n"
               "8730 - 378 = 8352\n"
               "8532 - 2358 = 6174\n"
               "7641 - 1467 = 6174\n"
               "Chain length 4\n");

  EXPECT_STREQ(SolveByCaptureStdout(444).c_str(),
               "Original number was 444\n"
               "444 - 444 = 0\n"
               "0 - 0 = 0\n"
               "Chain length 2\n");
}
