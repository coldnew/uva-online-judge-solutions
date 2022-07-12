#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <set>
#include <vector>

namespace {

const int kCardNumbers = 52;
const int kPilesNumber = 7;
}  // namespace

class CardGame {
 public:
  CardGame() = default;
  ~CardGame() = default;

  void Reset() {
    cards_.clear();
    piles_.clear();
    phases_.clear();
  }

  void AddCard(int card) { cards_.push_back(card); }

  void Start() {
    AddCardsToPile();

    int t = kPilesNumber;
    while (true) {
      if (!Process(t++))
        break;
    }
  }

 private:  // functions
  void AddCardsToPile() {
    for (int i = 0; i < kPilesNumber; ++i) {
      std::deque<int> pile;
      pile.push_back(cards_.front());
      cards_.pop_front();
      piles_.push_back(pile);
    }
  }

  std::string GeneratePhases() {
    std::string ans;
    for (auto& p : piles_) {
      for (auto c : p)
        ans += std::to_string(c);
      ans += "|";
    }
    for (auto c : cards_)
      ans += std::to_string(c);
    return ans;
  }

  void ProcessPile(std::deque<int>& p) {
    int n = p.size();
    if (n < 3)
      return;
    if ((p[0] + p[1] + p.back()) % 10 == 0) {
      cards_.push_back(p[0]);
      cards_.push_back(p[1]);
      cards_.push_back(p.back());
      p.pop_front();
      p.pop_front();
      p.pop_back();
      ProcessPile(p);
      return;
    }

    if ((p[0] + p[n - 2] + p[n - 1]) % 10 == 0) {
      cards_.push_back(p[0]);
      cards_.push_back(p[n - 2]);
      cards_.push_back(p[n - 1]);
      p.pop_front();
      p.pop_back();
      p.pop_back();
      ProcessPile(p);
      return;
    }

    if ((p[n - 3] + p[n - 2] + p[n - 1]) % 10 == 0) {
      cards_.push_back(p[n - 3]);
      cards_.push_back(p[n - 2]);
      cards_.push_back(p[n - 1]);
      p.pop_back();
      p.pop_back();
      p.pop_back();
      ProcessPile(p);
      return;
    }
  }

  bool Process(int time) {
    if (piles_.empty()) {
      std::cout << "Win : " << time << std::endl;
      return false;
    }

    if (cards_.empty()) {
      std::cout << "Loss: " << time << std::endl;
      return false;
    }

    std::string pha = GeneratePhases();
    if (phases_.count(pha)) {
      std::cout << "Draw: " << time << std::endl;
      return false;
    }

    phases_.insert(pha);

    int c = cards_.front();
    cards_.pop_front();
    piles_.push_back(piles_.front());
    piles_.erase(piles_.begin());

    auto& p = piles_.back();
    p.push_back(c);
    ProcessPile(p);
    if (p.empty())
      piles_.pop_back();

    return true;
  }

 private:  // variables
  std::deque<int> cards_;
  std::vector<std::deque<int>> piles_;
  std::set<std::string> phases_;
};

void Solution(std::istream& cin) {
  CardGame game;

  while (true) {
    game.Reset();

    for (int i = 0; i < kCardNumbers; ++i) {
      int c;
      cin >> c;
      if (c == 0)
        return;
      game.AddCard(c);
    }

    game.Start();
  }
}

#if !defined(GTEST_TEST)
int main(int argc, char* argv[]) {
  Solution(std::cin);
  return 0;
}
#endif  // !defind(GTEST_TEST)
