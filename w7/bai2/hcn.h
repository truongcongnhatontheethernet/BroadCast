#ifndef _HCN_H
#define _HCN_H

#include "hinhhocphang.h"
#include <cstdio>
#include <string>

class HCN : public HinhHocPhang {

private:
  float cd, cr;

public:
  HCN() {
    cd = 0;
    cr = 0;
  }
  HCN(float a, float b) {
    cd = a;
    cr = b;
  }
  virtual string getName() override { return "hcn"; }

  virtual void nhap(istream &is) override {
    char buffer[LEN];
    is.getline(buffer, LEN, ',');
    cd = stof(buffer);
    is.getline(buffer, LEN, '\n');
    cr = stof(buffer);
  }
  virtual void xuat(ostream &os) const override {

    char buffer[LEN];

    sprintf(buffer, "hcn : %.1f,%.1f", cd, cr);
    os << buffer;
  }

  virtual float dienTich() const override { return (float)cd * cr; }
  virtual float chuVi() const override { return 2 * (cd + cr); }
};

#endif
