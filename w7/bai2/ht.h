
#ifndef _HTR_H
#define _HTR_H

#include "hinhhocphang.h"
#include <cstdio>
#include <string>

#define PI 3.14

class HTR : public HinhHocPhang {

private:
  float banKinh;

public:
  HTR() { banKinh = 0; }
  HTR(float r) { banKinh = r; }
  virtual string getName() override { return "htr"; }

  virtual void nhap(istream &is) override {
    char buffer[LEN];
    is.getline(buffer, LEN, '\n');
    banKinh = stof(buffer);
  }
  virtual void xuat(ostream &os) const override {

    char buffer[LEN];

    sprintf(buffer, "htr : %.1f", banKinh);
    os << buffer;
  }

  virtual float dienTich() const override {
    return (float)PI * banKinh * banKinh;
  }
  virtual float chuVi() const override { return 2 * PI * banKinh; }
};

#endif
