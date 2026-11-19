#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

class Ships {

private:
  static int numAll;
  char *type;
  int curNo;

public:
  Ships();
  Ships(const char *);

  void createShips();
  ~Ships();
};

int main() {

  Ships *ship1 = new Ships();

  ship1->createShips();

  Ships *ship2 = new Ships();

  delete ship1;
  delete ship2;

  return 0;
}

int Ships::numAll = 0;

Ships::Ships() {
  curNo = ++numAll;
  type = new char[]{"N/A"};
  printf("Created a ship object No. %d: %s\n", curNo, type);
}
Ships::Ships(const char *name) {
  curNo = ++numAll;
  type = new char[strlen(name) + 1];
  strcpy(type, name);
  printf("Created a ship object No. %d: %s\n", curNo, type);
}

Ships::~Ships() {

  numAll--;
  printf("Removed a ship object No. %d: %s\n", curNo, type);
  if (type) {
    delete[] type;
    type = nullptr;
  }
}

void Ships::createShips() {
  Ships ship3;
  Ships ship4("Cruiser");
}
