#include "quanlyhhp.h"
#include <cstdlib>
#include <iostream>
#include <string>

int main() {

  const string infile = "in.i";

  QuanLy manage;

  manage.readFromFiles(infile);

  manage.xuatAll(cout);
  cout << endl;
  manage.xuatSpecified(cout);

  return EXIT_SUCCESS;
}
