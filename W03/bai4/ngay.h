#ifndef _NGAY_H
#define _NGAY_H

#include <iostream>
#include <math.h>

using namespace std;
#define SLEN 99

class Ngay {

private:
  int _ng, _th, _n;
  void chuanHoa();

public:
  Ngay();
  Ngay(const int &);
  Ngay(const int &, const int &, const int &);
  Ngay(const char *);
  ~Ngay();

  Ngay operator+(Ngay &); // use implicit casting
  friend Ngay operator+(int, Ngay &);
  Ngay operator-(Ngay &src);
  friend Ngay operator-(int a, Ngay &b);

  friend ostream &operator<<(ostream &, Ngay &);

  void xuat();
};

#endif
