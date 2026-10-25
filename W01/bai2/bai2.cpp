#include "bai2_ngay.h"
#include <iostream>
using namespace std;

int main() {

  Ngay n1;
  n1.xuat();
  Ngay n2(2, 10, 2024);
  n2.xuat();
  Ngay n3(-100, 16, 1990);
  n3.xuat();
  Ngay n4(1000);
  // 1403
  n4.xuat();
  Ngay n5("12-12-2012");
  n5.xuat();

  return 0;
}
