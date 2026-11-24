#include "nvkt.h"
#include <ostream>

ostream &operator<<(ostream &os, const NVKT &nv) {
  os << (NhanVien)nv; // nvkt is still a "nv" - IS-A relationship
  os << "[" << nv.cc_Nganh << "]";
  return os;
}
