#include "nhanvien.h"
#include <istream>
#include <string>

ostream &operator<<(ostream &os, const NhanVien &nv) {
  nv.xuat(os);
  return os;
}
istream &operator>>(istream &is, NhanVien &nv) {
  is >> std::ws; // std::ws would eat all leading whitespaces

  getline(is, nv.hoTen, '(');
  if (!nv.hoTen.empty() && nv.hoTen.back() == ' ')
    nv.hoTen.pop_back();

  is >> std::ws; // std::ws would eat all leading whitespaces

  getline(is, nv.diaChi, ')');

  return is;
}
