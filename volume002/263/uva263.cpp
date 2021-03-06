#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

namespace {

uint32_t ToUInt32(std::vector<int> arr) {
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
  return ToUInt32(arr);
}

uint32_t Descending(std::vector<int> arr) {
  std::sort(arr.begin(), arr.end(),
            [](int m, int n) -> bool { return (m > n); });
  return ToUInt32(arr);
}

std::vector<int> ToIntVector(uint32_t n) {
  std::vector<int> numbers;
  while (n > 0) {
    numbers.emplace(numbers.begin(), n % 10);
    n /= 10;
  }

  return numbers;
}

void Solve(uint32_t number) {
  std::cout << "Original number was " << number << std::endl;

  std::set<uint32_t> visited;
  for (int chain = 1;; ++chain) {
    // convert number to vector
    std::vector<int> numbers = ToIntVector(number);

    // calculate ascending/descending number
    auto dsc = Descending(numbers);
    auto asc = Ascending(numbers);

    auto result = dsc - asc;
    std::cout << dsc << " - " << asc << " = " << result << std::endl;

    // if result in our visited set, return chain length.
    auto search = visited.find(result);
    if (search != visited.end()) {
      std::cout << "Chain length " << chain << std::endl << std::endl;
      break;
    }

    number = result;
    visited.emplace(result);
  }
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
