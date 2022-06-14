#include <cstring>
#include <iostream>
#include <string>
#include <vector>

enum class WeightType {
  Heavy,
  Light,
};

std::string left_coins[3], right_coins[3], balance[3];

bool isHeavyOrLight(char c, WeightType type) {
  int weight = 1;
  if (type == WeightType::Light)
    weight = -1;

  for (int i = 0; i < 3; i++) {
    int left = 0, right = 0;
    for (int j = 0; j < left_coins[i].length(); j++) {
      if (left_coins[i][j] == c)
        left += weight;
      if (right_coins[i][j] == c)
        right += weight;
    }
    if (balance[i] == "even") {
      if (left != right)
        return false;
    } else if (balance[i] == "up") {
      if (left <= right)
        return false;
    } else if (balance[i] == "down") {
      if (left >= right)
        return false;
    }
  }

  return true;
}

bool isHeavy(char c) {
  return isHeavyOrLight(c, WeightType::Heavy);
}

bool isLight(char c) {
  return isHeavyOrLight(c, WeightType::Light);
}

void Solution(std::istream& cin) {
  int n = 0;
  cin >> n;
  while (n--) {
    for (int i = 0; i < 3; i++)
      cin >> left_coins[i] >> right_coins[i] >> balance[i];

    for (char c = 'A'; c <= 'L'; c++) {
      if (isHeavy(c)) {
        std::cout << c << " is the counterfeit coin and it is heavy."
                  << std::endl;
        break;
      } else if (isLight(c)) {
        std::cout << c << " is the counterfeit coin and it is light."
                  << std::endl;
        break;
      }
    }
  }
}

#if !defined(GTEST_TEST)
int main(int argc, char* argv[]) {
  Solution(std::cin);
  return 0;
}
#endif  // !defind(GTEST_TEST)
