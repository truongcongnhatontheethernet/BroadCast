#include "ngay.h"
#include <cstdio>
#include <cstring>

void Ngay::chuanHoa() {
  _ng = abs(_ng);
  _th = abs(_th);
  _n = abs(_n);

  if (_ng == 0)
    _ng = 1;
  if (_th == 0)
    _th = 1;
  if (_n == 0)
    _n = 1;

  while (_th > 12) {
    _th -= 12;
    _n++;
  }

  while (_ng > dayInMonth(_n, _th)) {
    _ng -= dayInMonth(_n, _th);
    _th++;
    if (_th > 12) {
      _th -= 12;
      _n++;
    }
  }
}

bool Ngay::isLeap(int nam) {
  return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int Ngay::dayInMonth(int nam, int th) {
  if (th == 2)
    return 28 + isLeap(nam);
  return 30 + (th + (th > 7)) % 2;
}

Ngay::Ngay() { _ng = _th = _n = 1; }

Ngay::Ngay(const int &x) : _ng(abs(x)), _th(1), _n(1) { chuanHoa(); }

Ngay::Ngay(const int &ng, const int &th, const int &n)
    : _ng(ng), _th(th), _n(n) {
  chuanHoa();
}

Ngay::Ngay(const char *s) {
  char *buffer = new char[SLEN];
  memcpy(buffer, s, sizeof(char) * (strlen(s) + 1));

  const char *delimiters = "-/";

  char *secure;
  secure = strtok(buffer, delimiters);
  _ng = (secure) ? atoi(secure) : 0;
  secure = strtok(nullptr, delimiters);
  _th = (secure) ? atoi(secure) : 0;
  secure = strtok(nullptr, delimiters);
  _n = (secure) ? atoi(secure) : 0;

  delete[] buffer;

  chuanHoa();
}

Ngay::~Ngay() {}

void Ngay::xuat() { printf("\n%2d/%2d/%.4d\n", _ng, _th, _n); }

Ngay Ngay::operator+(Ngay &src) {

  Ngay res(*this);

  res._n += src._n;
  res.chuanHoa();
  res._th += src._th;
  res.chuanHoa();
  res._ng += src._ng;

  res.chuanHoa();

  return res;
}
Ngay operator+(int a, Ngay &b) {

  Ngay res = Ngay(a) + b;
  res.chuanHoa();

  return res;
}
Ngay Ngay::operator-(Ngay &src) {

  Ngay res(*this);
  res._n -= src._n;
  res.chuanHoa();
  res._th -= src._th;
  res.chuanHoa();
  res._ng -= src._ng;

  res.chuanHoa();

  return res;
}
Ngay operator-(int a, Ngay &b) {

  Ngay res = Ngay(a) - b;
  res.chuanHoa();
  return res;
}
ostream &operator<<(ostream &outDev, Ngay &src) {

  char buffer[SLEN];
  sprintf(buffer, "%2d/%2d/%.4d", src._ng, src._th, src._n);

  outDev << buffer;
  return outDev;
}
