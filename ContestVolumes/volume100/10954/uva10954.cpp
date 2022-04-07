#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

void Solution(std::istream& cin) {
  int N = 0;
  while (cin >> N && (N != 0)) {
    std::vector<int> nums;
    for (auto i = 0; i < N; i++) {
      int x;
      cin >> x;
      nums.push_back(x);
    }
    assert(N == nums.size());

    std::sort(nums.begin(), nums.end(), std::less<int>());

    int ans = 0;
    for (auto i = 0; i < nums.size() - 1; i++) {
      int sum = nums[i] + nums[i + 1];
      ans += sum;
      nums[i + 1] = sum;

      if (i < nums.size() - 2)
        std::sort(nums.begin() + i + 1, nums.end(), std::less<int>());
    }

    std::cout << ans << std::endl;
  }
}

#if !defined(GTEST_TEST)
int main(int argc, char* argv[]) {
  Solution(std::cin);
  return 0;
}
#endif  // !defind(GTEST_TEST)
