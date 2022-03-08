#include <gtest/gtest.h>

#include "uva263.cpp"

TEST(UVa263Test, ToUInt32) {
  EXPECT_EQ(4444, ToUInt32(std::vector<int>{4, 4, 4, 4}));
  EXPECT_EQ(123456789, ToUInt32(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}));
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

TEST(UVa263Test, ToIntVector) {
  EXPECT_EQ(ToIntVector(4444), (std::vector<int>{4, 4, 4, 4}));
  EXPECT_EQ(ToIntVector(123456789),
            (std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

namespace {

std::string SolveByCaptureStdout(uint32_t n) {
  testing::internal::CaptureStdout();
  Solve(n);
  return std::string("\n") + testing::internal::GetCapturedStdout();
}

}  // namespace

TEST(UVa263Test, Solve) {
  EXPECT_EQ(SolveByCaptureStdout(123456789), R"(
Original number was 123456789
987654321 - 123456789 = 864197532
987654321 - 123456789 = 864197532
Chain length 2

)");

  EXPECT_EQ(SolveByCaptureStdout(1234), R"(
Original number was 1234
4321 - 1234 = 3087
8730 - 378 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
Chain length 4

)");

  EXPECT_EQ(SolveByCaptureStdout(444), R"(
Original number was 444
444 - 444 = 0
0 - 0 = 0
Chain length 2

)");

  EXPECT_EQ(SolveByCaptureStdout(87543), R"(
Original number was 87543
87543 - 34578 = 52965
96552 - 25569 = 70983
98730 - 3789 = 94941
99441 - 14499 = 84942
98442 - 24489 = 73953
97533 - 33579 = 63954
96543 - 34569 = 61974
97641 - 14679 = 82962
98622 - 22689 = 75933
97533 - 33579 = 63954
Chain length 10

)");

  EXPECT_EQ(SolveByCaptureStdout(1762893), R"(
Original number was 1762893
9876321 - 1236789 = 8639532
9865332 - 2335689 = 7529643
9765432 - 2345679 = 7419753
9775431 - 1345779 = 8429652
9865422 - 2245689 = 7619733
9776331 - 1336779 = 8439552
9855432 - 2345589 = 7509843
9875430 - 345789 = 9529641
9965421 - 1245699 = 8719722
9877221 - 1227789 = 8649432
9864432 - 2344689 = 7519743
9775431 - 1345779 = 8429652
Chain length 12

)");
}
