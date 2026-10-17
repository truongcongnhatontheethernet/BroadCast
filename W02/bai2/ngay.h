#ifndef _NGAY_H
#define _NGAY_H

#include <iostream>
#include <ostream>

class Ngay {

private:
  int _ng, _th, _n;
  static int ngayCuaThang(int, int);
  static bool LaNamNhuan(const int &n);

public:
  Ngay();
  Ngay(const int &);
  ~Ngay();
  void xuat(std::ostream &);
};

#endif
