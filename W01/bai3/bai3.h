#ifndef _THOIGIAN_H
#define _THOIGIAN_H

#include <iostream>

class Time {

private:
  int _h, _m, _s;
  void chuanHoa();

public:
  Time() : _h(0), _m(0), _s(0) { chuanHoa(); }
  Time(int s) : _h(0), _m(0), _s(s) { chuanHoa(); }
  Time(int m, int s) : _h(0), _m(m), _s(s) { chuanHoa(); }
  Time(int h, int m, int s) : _h(h), _m(m), _s(s) { chuanHoa(); }

  void xuat();
};

#endif
