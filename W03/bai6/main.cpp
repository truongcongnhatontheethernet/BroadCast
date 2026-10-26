#include "thoiGian.h"
using namespace std;

int main() {

  Time tg1;
  Time tg2(1212);
  Time tg3(125, 45);
  Time tg4(12, 239, -78);

  // Time tg5 = tg2 + tg3;
  Time tg6 = tg2 + 5000;
  Time tg7 = tg4 - tg6; // 14:16:46
  // Time tg8 = 12300 - tg4; // 0:0:0

  // cout << tg1;
  // cout << tg2;
  // cout << tg3;
  cout << tg4;
  // cout << tg5;
  cout << tg6;
  cout << tg7;
  // cout << tg8;

  return 0;
}
