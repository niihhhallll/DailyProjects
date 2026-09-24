#include <chrono>
#include <iostream>
#include <vector>

// oop way.
//

class player {
private:
  int health;
  int money;

public:
  player(int health, int money) : health(health), money(money){};

  void print() {
      this->health += 10;
      this->money += 10;
      return;
  }
};

// in dod way.
//
struct playerdod {
  std::vector<int> health;
  std::vector<int> money;

  void print(size_t index) {  health[index] += 10; money[index] += 10; }
};

int main() {
  // init of the oop
  std::vector<player> playeroop;
  playeroop.reserve(1000000);
  for (int i = 0; i < 1000000; i++) {
    playeroop.push_back({i, i});
  }


  // init of the dod
  playerdod player1;
  player1.health.reserve(1000000);
  player1.money.reserve(1000000);
  for(int i = 0; i < 1000000; i++)
  {
      player1.health[i] = i;
      player1.money[i] = i;
  }

  // accessing and modifying the elements
  // dod
  auto start_time = std::chrono::high_resolution_clock::now();
  for(int i = 0; i < 100000; i++)
  {
      player1.print(i);
  }
  auto end_time = std::chrono::high_resolution_clock::now();
  auto dura = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

  // oop
  auto start_oop = std::chrono::high_resolution_clock::now();
  for(auto &a : playeroop)
  {
      a.print();
  }
  auto end_oop = std::chrono::high_resolution_clock::now();
  auto dura_oop = std::chrono::duration_cast<std::chrono::microseconds>(end_oop - start_oop);
  system("clear");
  std::cout << "dod: " << dura.count() << "\n" << "oop: " << dura_oop.count() << "\n" << std::endl;
  return 0;
}
