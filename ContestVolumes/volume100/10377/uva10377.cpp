#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

constexpr int kMazeWidth = 62;
constexpr int kMazeHeight = 62;

class Maze {
 public:
  Maze(int row, int column, int x, int y, std::vector<std::string>& vec)
      : row_(row), column_(column), x_(x), y_(y), direction_('N') {
    for (int i = 0; i < row_; i++) {
      vec[i].copy(maze_[i], column_, 0);
    }
  };

  ~Maze() = default;

  bool Execute(const char command);
  std::string GetResult();

 private:
  char maze_[kMazeWidth][kMazeHeight];
  int row_;
  int column_;
  int x_;
  int y_;
  char direction_;

 private:  // function
  void Rotate(char c);
  void Forward();
};

bool Maze::Execute(const char command) {
  if (command == 'Q')
    return false;

  if (command == 'R' || command == 'L')
    Rotate(command);
  else if (command == 'F')
    Forward();

  return true;
}

void Maze::Rotate(const char c) {
  if (direction_ == 'N')
    (c == 'R') ? direction_ = 'E' : direction_ = 'W';
  else if (direction_ == 'S')
    (c == 'R') ? direction_ = 'W' : direction_ = 'E';
  else if (direction_ == 'E')
    (c == 'R') ? direction_ = 'S' : direction_ = 'N';
  else if (direction_ == 'W')
    (c == 'R') ? direction_ = 'N' : direction_ = 'S';
}

void Maze::Forward() {
  if (direction_ == 'N') {
    if (maze_[x_ - 1][y_] != '*')
      x_--;
  } else if (direction_ == 'S') {
    if (maze_[x_ + 1][y_] != '*')
      x_++;
  } else if (direction_ == 'E') {
    if (maze_[x_][y_ + 1] != '*')
      y_++;
  } else if (direction_ == 'W') {
    if (maze_[x_][y_ - 1] != '*')
      y_--;
  }
}

std::string Maze::GetResult() {
  return std::to_string(x_ + 1) + " " + std::to_string(y_ + 1) + " " +
         direction_ + "\n";
}

void Solution(std::istream& cin) {
  int number = 0;
  cin >> number;
  cin.ignore(1, '\n');
  if (number <= 0)
    return;

  while (number--) {
    int row, column;
    cin >> row;
    cin >> column;

    cin.ignore(1, '\n');

    std::vector<std::string> vec;
    for (int i = 0; i < row; ++i) {
      std::string line;
      std::getline(cin, line);
      vec.push_back(line);
    }

    int x, y;
    cin >> x;
    cin >> y;
    x--;
    y--;

    Maze maze(row, column, x, y, vec);

    char command;
    while ((cin >> command) && maze.Execute(command))
      ;

    std::cout << maze.GetResult();
    if (number)
      std::cout << std::endl;
  }
}

#if !defined(GTEST_TEST)
int main(int argc, char* argv[]) {
  Solution(std::cin);
  return 0;
}
#endif  // !defind(GTEST_TEST)
