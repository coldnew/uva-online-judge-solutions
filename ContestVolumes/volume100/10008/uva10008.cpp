#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

void Solution(std::istream& cin) {
  // first line is line count
  int line_count = 0;
  cin >> line_count;
  cin.ignore(1, '\n');

  std::map<char, int> chars_map;
  for (auto l = 0; l < line_count; l++) {
    char c = '\0';
    while (cin.get(c) && c != '\n') {
      if (isalpha(c))
        chars_map[toupper(c)]++;
    }
  }

  // since std::map can't be sorted directly, copy data to vector
  std::vector<std::pair<char, int>> occurrences;
  std::copy(chars_map.begin(), chars_map.end(),
            std::back_inserter<std::vector<std::pair<char, int>>>(occurrences));

  // sort the occurrences vector
  std::sort(occurrences.begin(), occurrences.end(),
            [](std::pair<char, int>& a, std::pair<char, int>& b) -> bool {
              if (a.second == b.second)
                return (a.first < b.first);
              return a.second > b.second;
            });

  for (const auto& kv : occurrences)
    std::cout << kv.first << " " << kv.second << std::endl;
}

#if !defined(GTEST_TEST)
int main(int argc, char* argv[]) {
  Solution(std::cin);
  return 0;
}
#endif  // !defind(GTEST_TEST)
