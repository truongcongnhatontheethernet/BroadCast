
//
// !! "=" could be copy constructor
// not operator= (user defined)
// copy constructor is called 1st!
// to init the object
// -> operator= is called later on
// !! Notice the memory management
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

#define LEN 99

class CString {

private:
  char *_mang;

public:
  CString();
  CString(const char *);
  CString(const CString &);
  ~CString();

  char &operator[](const int &);
  CString &operator=(const CString &);
  friend ostream &operator<<(ostream &, const CString &);
};

int main() {
  const int iN = 2;

  CString cs1("cs1_content");
  cout << "cs2(cs1)" << endl;
  CString cs2 = cs1;
  cs2[iN] = '2';
  cout << "cs3 = cs1";
  CString cs3 = cs1;
  cs3[iN] = '3';
  cout << cs1 << endl << cs2 << endl << cs3 << endl;
  cout << "cs3 = cs2";
  cs3 = cs2;
  cout << cs3 << endl;

  return 0;
};

CString::CString() { _mang = nullptr; }

CString::~CString() {
  if (_mang)
    delete[] _mang;
}

CString::CString(const char *in) {
  _mang = new char[strlen(in) + 1];
  strncpy(_mang, in, strlen(in) + 1);
}

CString::CString(const CString &in) : CString(in._mang) {
  cout << "copy instructor was called" << endl;
}

char &CString::operator[](const int &in) {
  if (in >= strlen(_mang) || in < 0)
    throw std::out_of_range("Out of range :3");

  return _mang[in];
}

CString &CString::operator=(const CString &in) {
  cout << "operator= was called" << endl;
  if (_mang)
    delete[] _mang;
  _mang = new char[LEN];
  strncpy(_mang, in._mang, strlen(in._mang) + 1);

  return *this;
}
// return CString only would just return
// a shallow copy

ostream &operator<<(ostream &out, const CString &s) {

  out << s._mang;
  return out;
}
