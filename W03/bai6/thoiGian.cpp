#include "thoiGian.h"
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

Time Time::operator+(Time &src) {
  Time res(*this);

  res._s += src._s;
  res.chuanHoa();

  res._m += src._m;

  res.chuanHoa();
  res._h += src._h;
  res.chuanHoa();

  return res;
}

Time Time::operator+(int src) {

  Time res(src);
  res = res + *this;
  res.chuanHoa();
  return res;
}

Time operator+(int a, Time &b) {

  Time res(a);
  res = res + b;
  res.chuanHoa();
  return res;
}
Time Time::operator-(const Time &t_src) {
  Time res(*this);
  Time src(t_src);

  if (res._s - src._s < 0) {
    res._s = 60 + (res._s - src._s);
    src._m++;
  } else
    res._s -= src._s;

  if (res._m - src._m < 0) {
    res._m = 60 + (res._m - src._m);
    src._h++;
  } else
    res._m -= src._m;
  res._h -= src._h;
  res.chuanHoa();
  return res;
}

Time Time::operator-(int src) {

  Time res(src);
  res = res - *this;
  res.chuanHoa();
  return res;
}

Time operator-(int a, Time &b) {

  Time res(a);
  res = res - b;
  res.chuanHoa();
  return res;
}
ostream &operator<<(ostream &outDev, Time src) {

  char buffer[LEN];
  sprintf(buffer, "%2.2d:%2.2d:%2.2d\n", src._h, src._m, src._s);
  outDev << buffer;
  return outDev;
}
