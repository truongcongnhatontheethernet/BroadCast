#ifndef _QUANLY_H
#define _QUANLY_H

#include "hcn.h"
#include "hinhhocphang.h"
#include "ht.h"
#include "htg.h"
#include "hthv.h"
#include <fstream>
#include <ios>
#include <ostream>
#include <string>
#include <vector>

class QuanLy {

private:
  vector<HinhHocPhang *> items;

public:
  QuanLy() {}
  ~QuanLy() {
    for (int i = 0; i < items.size(); i++) {
      delete items[i];
    }
  }

  void readFromFiles(const string &inFile) {

    string type = "";

    ifstream fi(inFile, ios::in);

    if (!fi.is_open())
      return;

    while (fi >> type) {
      HinhHocPhang *t = nullptr;
      if (type == "hcn:") {
        t = new HCN;
      } else if (type == "htr:") {
        t = new HTR;
      } else if (type == "htg:") {
        t = new HTG;
      } else if (type == "hthv:") {
        t = new HTHV;
      }

      t->nhap(fi);
      items.push_back(t);
    }
  }
  void xuatAll(ostream &os) {
    for (int i = 0; i < items.size(); i++) {
      items[i]->xuat(os);
      os << endl;
    }
  }
};

#endif
