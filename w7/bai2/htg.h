

#ifndef _HTG_H
#define _HTG_H

#include "hinhhocphang.h"
#include <cstdio>
#include <cstring>
#include <string>

const int soCanhTG = 3;

class HTG : public HinhHocPhang {

private:
  float a[soCanhTG];

public:
  HTG() {
    for (int i = 0; i < soCanhTG; i++)
      a[i] = 0;
  }
  HTG(float x, float y, float z) {
    a[0] = x;
    a[1] = y;
    a[2] = z;
  }

  virtual string getName() override { return "htg"; }

  virtual void nhap(istream &is) override {
    char buffer[LEN];
    is.getline(buffer, LEN, '\n');
    a[0] = stof(strtok(buffer, ","));
    a[1] = stof(strtok(NULL, ","));
    a[2] = stof(strtok(NULL, ","));
  }
  virtual void xuat(ostream &os) const override {

    char buffer[LEN];

    sprintf(buffer, "htg : %.1f,%.1f,%.1f", a[0], a[1], a[2]);
    os << buffer;
  }

  virtual float dienTich() const override {

    float halfP = chuVi() / 2;
    return (float)sqrt(halfP * (halfP - a[0]) * (halfP - a[1]) *
                       (halfP - a[2]));
  }
  virtual float chuVi() const override { return a[0] + a[1] + a[2]; }
};

#endif
