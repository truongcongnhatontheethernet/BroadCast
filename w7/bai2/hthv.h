

#ifndef _HTHV_H
#define _HTHV_H

#include "hinhhocphang.h"
#include <cmath>
#include <string.h>

class HTHV : public HinhHocPhang {

private:
  float dayLon, dayBe, chieuCao;

public:
  HTHV() { dayLon = dayBe = chieuCao = 0; }
  HTHV(float dL, float dB, float cC) {
    dayLon = dL;
    dayBe = dB;
    chieuCao = cC;
  }

  ~HTHV() {}

  virtual string getName() override { return "hthv"; }
  virtual void nhap(istream &is) override {
    char buffer[LEN];
    is.getline(buffer, LEN, '\n');

    dayLon = stof(strtok(buffer, ","));
    dayBe = stof(strtok(NULL, ","));
    chieuCao = stof(strtok(NULL, ","));
  }
  virtual void xuat(ostream &os) const override {

    char buffer[LEN];

    sprintf(buffer, "htr : %.1f,%.1f, %.1f ", dayLon, dayBe, chieuCao);
    os << buffer;
  }

  virtual float dienTich() const override {
    return (float)(dayLon + dayBe) / 2 * chieuCao;
  }
  virtual float chuVi() const override {
    float t = dayLon - dayBe;

    return dayLon + dayBe + chieuCao + sqrt(chieuCao * chieuCao + t * t);
  }
};

#endif
