#include "ngay.h"
#include <ostream>

Ngay::Ngay() : _ng(1), _th(1), _n(1) {}
Ngay::Ngay(const int &n) : _ng(abs(n)), _th(1), _n(1) {

  if (_ng == 0) {
    _ng = 1;
    return;
  }

  while (_ng > ngayCuaThang(_th, _n)) {
    _ng -= ngayCuaThang(_th, _n);
    _th++;

    if (_th > 12) {
      _th = 1;
      _n++;
    }
  }
}

Ngay::~Ngay() {}

bool Ngay::LaNamNhuan(const int &n) {
  return (n % 400 == 0) || (n % 4 == 0 && n % 100 != 0);
}

int Ngay::ngayCuaThang(int th, int n) {
  if (th == 2)
    return 28 + LaNamNhuan(n);
  return 30 + ((th + (th > 7)) % 2);
}

void Ngay::xuat(std::ostream &os) {
  os << _ng << "-" << _th << "-" << _n << '\n';
}
