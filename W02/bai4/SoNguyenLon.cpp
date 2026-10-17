#include "SoNguyenLon.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

SoNguyenLon::SoNguyenLon() {
  buffer = new char[]{"0"};
  a = new int[LEN];
}

SoNguyenLon::SoNguyenLon(int a) {
  buffer = new char[LEN];
  sprintf(buffer, "%d", a);
  this->a = new int[LEN];
}

SoNguyenLon::SoNguyenLon(int a, int b) {
  char *temp = new char[LEN];
  buffer = new char[LEN];
  for (int i = 0; i < b; i++) {
    sprintf(temp, "%d", a);
    strcat(buffer, temp);
  }

  this->a = new int[LEN];
  delete[] temp;
}

SoNguyenLon::SoNguyenLon(const char *s) {
  buffer = new char[LEN];
  strcpy(buffer, s);
  this->a = new int[LEN];
}

SoNguyenLon::~SoNguyenLon() {
  delete[] buffer;
  delete[] a;
}

void SoNguyenLon::fix() {}
