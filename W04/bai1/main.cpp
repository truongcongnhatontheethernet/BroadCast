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
  ~CString();

  char &operator[](const int &);
  friend ostream &operator<<(ostream &, const CString &);
};

int main() {
  const int iN = 2;

  CString cs1("cs1_content");
  cout << cs1 << endl;
  cout << "cs1[" << iN << "] : " << cs1[iN] << endl;
  cs1[iN] = 'N';

  cout << cs1 << endl;
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

char &CString::operator[](const int &in) {
  if (in >= strlen(_mang) || in < 0)
    throw std::out_of_range("Out of range :3");

  return _mang[in];
}

ostream &operator<<(ostream &out, const CString &s) {

  out << s._mang;
  return out;
}
