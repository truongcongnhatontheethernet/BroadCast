#include "bai3.h"
#include <cstdio>

void Time::chuanHoa() {

  _s = abs(_s);
  _m = abs(_m);
  _h = abs(_h);

  int sDu = _s / 60;
  _s = _s % 60;
  _m += sDu;
  int mDu = _m / 60;
  _m = _m % 60;
  _h += mDu;
}

void Time::xuat() { printf("%2.2d:%2.2d:%2.2d\n", _h, _m, _s); }
