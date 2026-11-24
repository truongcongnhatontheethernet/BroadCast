#ifndef _NHANVIEN_H
#define _NHANVIEN_H

#include <iostream>
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
};

#endif
