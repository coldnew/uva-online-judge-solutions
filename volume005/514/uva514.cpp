#include <iostream>
#include <stack>
#include <vector>

void Solution(std::istream& cin) {
  int n;
  while (cin >> n && n) {
    bool exit = false;
    while (!exit) {
      std::vector<int> out(n + 1);
      for (int i = 1; i <= n; i++) {
        cin >> out[i];
        if (out[i] == 0) {
          exit = true;
          break;
        }
      }

      if (exit)
        continue;

      std::stack<int> station;
      int A = 1, B = 1;
      bool ans = true;
      while (B <= n) {
        if (A == out[B]) {
          A++;
          B++;
        } else if (!station.empty() && station.top() == out[B]) {
          station.pop();
          B++;
        } else if (A <= n) {
          station.push(A++);
        } else {
          ans = false;
          break;
        }
      }
      std::cout << (ans ? "Yes" : "No") << std::endl;
    }
    std::cout << std::endl;
  }
}

#if !defined(GTEST_TEST)
int main(int argc, char* argv[]) {
  Solution(std::cin);
  return 0;
}
#endif  // !defind(GTEST_TEST)
