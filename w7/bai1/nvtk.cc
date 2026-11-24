
#include "nvtk.h"

ostream &operator<<(ostream &os, const NVTK &nv) {
  nv.xuat(os);
  return os;
}

istream &operator>>(istream &is, NVTK &nv) {
  is >> (NhanVien &)nv;

  is >> std::ws;

  is.ignore(100, '[');

  getline(is, nv.cc_NgoaiNgu, ']');

  is >> std::ws;
  is.ignore(100, '<');
  is >> nv.soBaoCao;

  is.ignore(100, '\n'); // consume '>' and newline

  return is;
}
