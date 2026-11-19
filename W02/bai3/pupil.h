#ifndef _PUPIL_H
#define _PUPIL_H

#include <cstring>
#include <iostream>

#define BUFF_SIZE 99
#define NUM_S 3

class Pupil {

private:
  char *name;
  float a, b, c;
  float avg();
  static Pupil *arrPupil[BUFF_SIZE];
  static int nPupils;

public:
  Pupil();
  Pupil(const char *, float, float, float);
  ~Pupil();

  void in(std::ostream &);

  void setName(const char *);
  void setScores(float, float, float);

  static Pupil &bestPupil();
};

#endif
