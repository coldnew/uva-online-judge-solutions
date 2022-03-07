#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

namespace {

uint32_t IntVectorToInt32(std::vector<int> arr) {
  std::reverse(arr.begin(), arr.end());

  uint32_t total = 0;
  int decimal = 1;
  for (auto& it : arr) {
    total += it * decimal;
    decimal *= 10;
  }
  return total;
}

uint32_t Ascending(std::vector<int> arr) {
  std::sort(arr.begin(), arr.end(),
            [](int m, int n) -> bool { return (m < n); });
  return IntVectorToInt32(arr);
}

uint32_t Descending(std::vector<int> arr) {
  std::sort(arr.begin(), arr.end(),
            [](int m, int n) -> bool { return (m > n); });
  return IntVectorToInt32(arr);
}

std::vector<int> NumberToIntVector(uint32_t n) {
  std::vector<int> numbers;
  while (n > 0) {
    numbers.push_back(n % 10);
    n /= 10;
  }

  return numbers;
}

void Solve(const uint32_t n, int chain = 1) {
  if (chain == 1)
    std::cout << "Original number was " << n << std::endl;

  // convert number n to vector
  std::vector<int> numbers = NumberToIntVector(n);

  // calculate ascending/descending number
  auto dsc = Descending(numbers);
  auto asc = Ascending(numbers);

  auto result = dsc - asc;
  std::cout << dsc << " - " << asc << " = " << result << std::endl;

  // when current result the same as input n, stop the chain
  if (result == n) {
    std::cout << "Chain length " << chain << std::endl;
    return;
  }

  Solve(result, ++chain);
}

}  // namespace

#if !defined(GTEST_TEST)
int main(int argc, char* argv[]) {
  // read until user enter '0'
  uint32_t input;
  while (std::cin >> input) {
    if (input == 0)
      break;
    Solve(input);
  }
  return 0;
}
#endif  // !defind(GTEST_TEST)
