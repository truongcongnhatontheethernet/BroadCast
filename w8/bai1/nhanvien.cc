#include "nhanvien.h"

ostream &operator<<(ostream &os, const NhanVien &nv) {
  os << nv.hoTen << "(" << nv.diaChi << ")";
  return os;
}
