#ifndef _BIG_NUM
#define _BIG_NUM

#define LEN 99
#define BASE 1e6
#define BASE_LEN 6

#include <iostream>

class SoNguyenLon {

private:
  char *buffer;
  int *a;
  int nA;

  void fix();
  void removeZeroes();

public:
  SoNguyenLon();
  SoNguyenLon(int);
  SoNguyenLon(int, int);
  SoNguyenLon(const char *);
  SoNguyenLon(const SoNguyenLon &snl);

  SoNguyenLon &cong(const SoNguyenLon &);
  SoNguyenLon &tru(const SoNguyenLon &);

  ~SoNguyenLon();

  void in();
};

#endif
