#include "nvkt.h"

ostream &operator<<(ostream &os, const NVKT &nv) {
  nv.xuat(os);
  return os;
}

istream &operator>>(istream &is, NVKT &nv) {
  is >> (NhanVien &)nv;

  is >> std::ws;

  is.ignore(100, '[');

  getline(is, nv.cc_Nganh, ']');

  is >> std::ws;
  is.ignore(100, '<');
  is >> nv.soSangKien;

  is.ignore(100, '\n'); // consume '>' and newline

  return is;
}
