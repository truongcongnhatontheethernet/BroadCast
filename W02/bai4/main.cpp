#include "SoNguyenLon.h"

int main() {

  SoNguyenLon snl1;
  SoNguyenLon snl2("1234567");
  SoNguyenLon snl3(3, 14);
  SoNguyenLon snl4(9, 20);
  SoNguyenLon snl5 = snl3.cong(snl2);

  snl1.in();
  snl2.in();
  snl3.in();
  snl4.in();
  snl5.in();


  return 0;
}
