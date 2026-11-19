#ifndef _NGAY_H
#define _NGAY_H

#include <math.h>

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
  void xuat();
};

#endif
