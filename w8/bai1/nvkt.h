#ifndef _NVKT_H
#define _NVKT_H

#include "nhanvien.h"
#include <ostream>

class NVKT : public NhanVien {

private:
  string cc_Nganh;

public:
  NVKT() : NhanVien() { cc_Nganh = ""; };
  NVKT(const string &ht, const string &dc, const string &cc)
      : NhanVien(ht, dc) {
    cc_Nganh = cc;
  }

  friend ostream &operator<<(ostream &os, const NVKT &nv);
};

#endif
