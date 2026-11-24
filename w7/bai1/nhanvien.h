#ifndef _NHANVIEN_H
#define _NHANVIEN_H

#include <iostream>
#include <istream>
#include <ostream>
#include <string>

using namespace std;

class NhanVien {

private:
  string hoTen, diaChi;

public:
  NhanVien() {
    hoTen = "";
    diaChi = "";
  }

  NhanVien(const string &ht, const string &dc) {
    hoTen = ht;
    diaChi = dc;
  }

  friend ostream &operator<<(ostream &, const NhanVien &);
  // friend function can not be virtual, hence the existence of 'xuat()'

  virtual void xuat(ostream &os) const { os << hoTen << "(" << diaChi << ")"; }

  friend istream &operator>>(istream &os, NhanVien &nv);

  virtual bool laXuatSac() const = 0;

  virtual ~NhanVien() = default; // just for intentionally empty
};

#endif
