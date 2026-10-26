#ifndef _THOIGIAN_H
#define _THOIGIAN_H

#include <iostream>
#include <ostream>
using namespace std;

#define LEN 99

class Time {

private:
  int _h, _m, _s;
  void chuanHoa();

public:
  Time() : _h(0), _m(0), _s(0) { chuanHoa(); }
  Time(int s) : _h(0), _m(0), _s(s) { chuanHoa(); }
  Time(int m, int s) : _h(0), _m(m), _s(s) { chuanHoa(); }
  Time(int h, int m, int s) : _h(h), _m(m), _s(s) { chuanHoa(); }

  Time operator+(Time &);
  Time operator+(int);
  friend Time operator+(int, Time &);
  Time operator-(const Time &);
  Time operator-(int);
  friend Time operator-(int, Time &);

  friend ostream &operator<<(ostream &, Time src);

  void xuat();
};

#endif
