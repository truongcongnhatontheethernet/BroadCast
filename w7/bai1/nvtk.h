
#ifndef _NVTK_H
#define _NVTK_H

#include "nhanvien.h"

class NVTK : public NhanVien {

private:
  string cc_NgoaiNgu;
  int soBaoCao;

public:
  NVTK() : NhanVien() {
    cc_NgoaiNgu = "";
    soBaoCao = 0;
  };
  NVTK(const string &ht, const string &dc, const string &cc, const int &sbc)
      : NhanVien(ht, dc) {
    cc_NgoaiNgu = cc;
    soBaoCao = sbc;
  }

  virtual bool laXuatSac() const override { return soBaoCao >= 12; }

  virtual void xuat(ostream &os) const override {
    os << "nvtk : ";
    NhanVien::xuat(os);
    os << "[" << cc_NgoaiNgu << "]";
    os << " <" << soBaoCao << ">";
  }
  friend ostream &operator<<(ostream &os, const NVTK &nv);
  friend istream &operator>>(istream &is, NVTK &nv);
};

#endif
