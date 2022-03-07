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
               "Chain length 2\n\n");

  EXPECT_STREQ(SolveByCaptureStdout(1234).c_str(),
               "Original number was 1234\n"
               "4321 - 1234 = 3087\n"
               "8730 - 378 = 8352\n"
               "8532 - 2358 = 6174\n"
               "7641 - 1467 = 6174\n"
               "Chain length 4\n\n");

  EXPECT_STREQ(SolveByCaptureStdout(444).c_str(),
               "Original number was 444\n"
               "444 - 444 = 0\n"
               "0 - 0 = 0\n"
               "Chain length 2\n\n");

  EXPECT_STREQ(SolveByCaptureStdout(87543).c_str(),
               "Original number was 87543\n"
               "87543 - 34578 = 52965\n"
               "96552 - 25569 = 70983\n"
               "98730 - 3789 = 94941\n"
               "99441 - 14499 = 84942\n"
               "98442 - 24489 = 73953\n"
               "97533 - 33579 = 63954\n"
               "96543 - 34569 = 61974\n"
               "97641 - 14679 = 82962\n"
               "98622 - 22689 = 75933\n"
               "97533 - 33579 = 63954\n"
               "Chain length 10\n\n");

  EXPECT_STREQ(SolveByCaptureStdout(1762893).c_str(),
               "Original number was 1762893\n"
               "9876321 - 1236789 = 8639532\n"
               "9865332 - 2335689 = 7529643\n"
               "9765432 - 2345679 = 7419753\n"
               "9775431 - 1345779 = 8429652\n"
               "9865422 - 2245689 = 7619733\n"
               "9776331 - 1336779 = 8439552\n"
               "9855432 - 2345589 = 7509843\n"
               "9875430 - 345789 = 9529641\n"
               "9965421 - 1245699 = 8719722\n"
               "9877221 - 1227789 = 8649432\n"
               "9864432 - 2344689 = 7519743\n"
               "9775431 - 1345779 = 8429652\n"
               "Chain length 12\n\n");
}
