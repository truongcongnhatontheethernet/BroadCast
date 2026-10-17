#include "pupil.h"
#include <iostream>

int Pupil::nPupils = 0;
Pupil *Pupil::arrPupil[BUFF_SIZE];

int main() {

  Pupil hs1;
  hs1.setName("Nguyen Van A");
  hs1.setScores(7, 8, 10);
  Pupil hs2("Tran Thi B", 5, 8, 4.5);
  Pupil hs3("Hoang Thi C", -9.5, 8.5, 4.5);
  Pupil hs4("Le Van D", 7.5, 9, -10);
  /// “HS: Nguyen Van A, MS: 23120001, DTB: 7.53"
  hs1.in(std::cout);
  hs2.in(std::cout);
  hs3.in(std::cout);
  hs4.in(std::cout);
  std::cout << "Hoc sinh co diem TB cao nhat:" << std::endl;
  Pupil::bestPupil().in(std::cout);
  return 0;
}
