#include "SoNguyenLon.h"
#include <algorithm>
#include <cstdio>
#include <cstring>

SoNguyenLon::SoNguyenLon() {
  buffer = new char[]{"0"};
  a = new int[LEN];
  for (int i = 0; i < LEN; i++)
    a[i] = 0;
  nA = 0;
  fix();
}

SoNguyenLon::SoNguyenLon(int a) {
  buffer = new char[LEN];
  sprintf(buffer, "%d", a);
  this->a = new int[LEN];
  for (int i = 0; i < LEN; i++)
    this->a[i] = 0;
  nA = 0;
  fix();
}

SoNguyenLon::SoNguyenLon(int a, int b) {
  char *temp = new char[LEN];
  buffer = new char[LEN];
  for (int i = 0; i < b; i++) {
    sprintf(temp, "%d", a);
    strcat(buffer, temp);
    nA = 0;
  }

  this->a = new int[LEN];
  for (int i = 0; i < LEN; i++)
    this->a[i] = 0;
  delete[] temp;
  fix();
}

SoNguyenLon::SoNguyenLon(const char *s) {
  buffer = new char[LEN];
  strcpy(buffer, s);
  this->a = new int[LEN];
  nA = 0;
  for (int i = 0; i < LEN; i++)
    this->a[i] = 0;
  fix();
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon &snl) {

  buffer = new char[LEN];
  strcpy(buffer, snl.buffer);
  this->a = new int[LEN];
  nA = snl.nA;
  for (int i = 0; i < LEN; i++)
    this->a[i] = 0;

  for (int i = 0; i < nA; i++) {
    a[i] = snl.a[i];
  }
}

SoNguyenLon::~SoNguyenLon() {
  delete[] buffer;
  delete[] a;
}

void SoNguyenLon::fix() {

  char *temp = new char[LEN];
  char *tempSeg = new char[LEN];
  char *p = temp;

  int tempInt = 0;

  strcpy(temp, buffer);

  while (*p) {
    p++;
  }

  while (p != temp || *p == '\0') {
    for (int i = 0; p != temp && i < BASE_LEN; i++) {

      p--;
    }

    strcpy(tempSeg, p);
    *p = '\0';

    tempInt = atoi(tempSeg);
    a[nA++] = tempInt;

    if (p == temp)
      break;
  }
}

void SoNguyenLon::in() {

  printf("\n%s\n", buffer);
  for (int i = 0; i <= nA; i++) {
    printf("Base %d^%d : %*d\n", (int)BASE, i, BASE_LEN, a[i]);
  }
}

SoNguyenLon &SoNguyenLon::cong(const SoNguyenLon &src) {

  SoNguyenLon *temp = new SoNguyenLon();

  temp->nA = std::max(this->nA, src.nA);

  for (int i = 0; i < temp->nA; i++) {
    temp->a[i] = this->a[i] + src.a[i];
  }

  for (int i = 0; i < temp->nA; i++) {

    bool up = false;

    if (temp->a[i] >= BASE) {
      temp->a[i] -= BASE;
      temp->a[i + 1]++;
      up = true;
    }

    if (i == temp->nA - 1 && up)
      temp->nA++;
  }

  char *t = new char[LEN];
  for (int i = nA - 1; i >= 0; i--) {

    sprintf(t, "%d", temp->a[i]);
    strcat(temp->buffer, t);
  }

  delete[] t;
  temp->removeZeroes();

  return *temp;
}

void SoNguyenLon::removeZeroes() {

  char *p = buffer;
  for (; *p == '0'; p++)
    ;

  strcpy(buffer, p);
}

// SoNguyenLon &SoNguyenLon::tru(const SoNguyenLon &src) {

//   SoNguyenLon *temp = new SoNguyenLon();

//   temp->nA = std::max(this->nA, src.nA);

//   for (int i = 0; i < temp->nA; i++) {
//     temp->a[i] = this->a[i] + src.a[i];
//   }

//   for (int i = 0; i < temp->nA; i++) {

//     bool up = false;

//     if (temp->a[i] >= BASE) {
//       temp->a[i] -= BASE;
//       temp->a[i + 1]++;
//       up = true;
//     }

//     if (i == temp->nA - 1 && up)
//       temp->nA++;
//   }

//   char *t = new char[LEN];
//   for (int i = nA - 1; i >= 0; i--) {

//     sprintf(t, "%d", temp->a[i]);
//     strcat(temp->buffer, t);
//   }

//   delete[] t;
//   temp->removeZeroes();

//   return *temp;
// }
