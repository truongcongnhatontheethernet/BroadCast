#ifndef _CONGTY_H
#define _CONGTY_H

#include "nhanvien.h"
#include "nvkt.h"
#include "nvtk.h"
#include <fstream>
#include <ios>
#include <ostream>
#include <string>
#include <vector>
class CongTy {
private:
  std::vector<NhanVien *> staffs;

public:
  CongTy() { staffs.resize(0); }

  ~CongTy() {
    for (int i = 0; i < staffs.size(); i++)
      delete staffs[i];
  }

  void readFromFile(const std::string &inFile) {

    ifstream fi(inFile, ios::in);
    std::string type = "";

    if (!fi.is_open())
      return;

    while (fi >> type) {

      if (type == "nvkt:") {
        NVKT *kt = new NVKT;
        fi >> *kt;
        staffs.push_back(kt);
      }
      if (type == "nvtk:") {
        NVTK *tk = new NVTK;
        fi >> *tk;
        staffs.push_back(tk);
      }
    }
  }

  void inRaNhanVienXS(ostream &os) {

    for (int i = 0; i < staffs.size(); i++) {
      if (staffs[i]->laXuatSac()) {
        staffs[i]->xuat(os);
        cout << endl;
      }
    }
  }
};

#endif
