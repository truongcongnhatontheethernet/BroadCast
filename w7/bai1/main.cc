
#include "congty.h"
#include "nhanvien.h"
#include "nvkt.h"
#include "nvtk.h"

int main() {

  std::string inFile = "in.i";

  CongTy a;
  a.readFromFile(inFile);

  a.inRaNhanVienXS(cout);

  return EXIT_SUCCESS;
}
