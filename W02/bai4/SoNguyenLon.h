#ifndef _BIG_NUM
#define _BIG_NUM

#define LEN 99
#define BASE 1e6

#include <iostream>

class SoNguyenLon {

private:
  char *buffer;
  int *a;

  void fix();

public:
  SoNguyenLon();
  SoNguyenLon(int);
  SoNguyenLon(int, int);
  SoNguyenLon(const char *);

  ~SoNguyenLon();

  void in();
};

#endif
