#ifndef _NVKT_H
#define _NVKT_H

#include "nhanvien.h"

class NVKT : public NhanVien {

private:
  string cc_Nganh;
  int soSangKien;

public:
  NVKT() : NhanVien() {
    cc_Nganh = "";
    soSangKien = 0;
  };
  NVKT(const string &ht, const string &dc, const string &cc, const int &ssk)
      : NhanVien(ht, dc) {
    cc_Nganh = cc;
    soSangKien = ssk;
  }

  virtual bool laXuatSac() const override { return soSangKien >= 6; }
  // using NhanVien::laXuatSac; : just a reminder

  virtual void xuat(ostream &os) const override {
    os << "nvkt : ";
    NhanVien::xuat(os);
    os << "[" << cc_Nganh << "]";
    os << " <" << soSangKien << ">";
  }

  friend ostream &operator<<(ostream &os, const NVKT &nv);
  friend istream &operator>>(istream &is, NVKT &nv);
};

#endif
