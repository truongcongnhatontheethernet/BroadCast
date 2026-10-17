#include "pupil.h"
#include <cstdio>
#include <cstring>
#include <ostream>

Pupil::Pupil() : a(0), b(0), c(0) {
  name = new char[]{"N/A"};
  arrPupil[nPupils++] = this;
}
Pupil::Pupil(const char *name, float _a, float _b, float _c)
    : a(_a), b(_b), c(_c) {
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
  arrPupil[nPupils++] = this;
}

Pupil::~Pupil() {
  delete[] name;

  nPupils--;
}

float Pupil::avg() { return (float)(a + b + c) / 3; }

void Pupil::in(std::ostream &outDev) {

  char *buffer = new char[BUFF_SIZE];
  sprintf(buffer, "\nHS: %s, DTB: %.2f\n", name, avg());
  outDev << buffer;
  delete[] buffer;
}

void Pupil::setName(const char *s) {
  delete[] name;
  name = new char[BUFF_SIZE];
  strcpy(name, s);
}

void Pupil::setScores(float a, float b, float c) {
  this->a = a;
  this->b = b;
  this->c = c;
}

Pupil &Pupil::bestPupil() {

  Pupil *best = nullptr;
  if (nPupils > 0)
    best = arrPupil[0];
  for (int i = 1; i < nPupils; i++) {

    if (best->avg() < arrPupil[i]->avg())
      best = arrPupil[i];
  }

  return *best;
}
