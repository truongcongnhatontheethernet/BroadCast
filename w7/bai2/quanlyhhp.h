#ifndef _QUANLY_H
#define _QUANLY_H

#include "hcn.h"
#include "hinhhocphang.h"
#include "ht.h"
#include "htg.h"
#include "hthv.h"
#include <cstdio>
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

  void xuatSpecified(ostream &os) {

    float totalArea = 0, totalP = 0;
    string nameT = "";

    vector<HinhHocPhang *> t = items;
    while (t.size() > 0) {
      nameT = t[0]->getName();
      for (int i = 0; i < t.size();) {

        if (t[i]->getName() == nameT) {
          totalArea += t[i]->dienTich();
          totalP += t[i]->chuVi();
          t.erase(t.begin() + i);
        }

        else
          i++;
      }

      os << nameT << " : ";
      printf("Tong dien tich = %.2f ; Tong chu vi = %.2f\n", totalArea, totalP);
    }
  }
};

#endif
