#ifndef _HHP_H
#define _HHP_H

#include <cstdlib>
#include <iostream>
#include <ostream>

#include <math.h>
using namespace std;

#define LEN 99

class HinhHocPhang {

  // more like an abstract class
  // it's here to help us know how other shapes would behave

public:
  HinhHocPhang() {}

  virtual string getName() = 0;
  virtual void nhap(istream &) = 0;
  virtual void xuat(ostream &) const = 0;

  virtual float dienTich() const = 0;
  virtual float chuVi() const = 0;

  virtual ~HinhHocPhang() = default;
};

#endif
