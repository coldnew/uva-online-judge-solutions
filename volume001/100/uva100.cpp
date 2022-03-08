#include <cstdint>
#include <iostream>

namespace {

const int kMaxSize = 1000000;

uint32_t CycleLength(uint32_t n) {
  static uint32_t cache[kMaxSize] = {0};

  if (n == 1)
    return n;

  if (n & 1)  // odd
    n = 3 * n + 1;
  else
    n /= 2;

  if (n < kMaxSize) {
    if (!cache[n])
      cache[n] = CycleLength(n);
    return 1 + cache[n];
  }

  return 1 + CycleLength(n);
}

void Solve(uint32_t first, uint32_t second) {
  // make sure start is less then end
  auto start = std::min(first, second);
  auto end = std::max(first, second);

  uint32_t result = 0;
  for (uint32_t i = start; i <= end; i++) {
    uint32_t steps = CycleLength(i);
    if (steps > result)
      result = steps;
  }

  std::cout << first << " " << second << " " << result << std::endl;
}

}  // namespace

#if !defined(GTEST_TEST)
int main(int argc, char* argv[]) {
  int first = 0, second = 0;
  while (std::cin >> first >> second)
    Solve(first, second);
  return 0;
}
#endif  // !defind(GTEST_TEST)
