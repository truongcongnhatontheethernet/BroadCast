#include <iostream>

class Complex {

private:
  int real, im;
  int sl = 0;
  static int ssl;

public:
  Complex();
  Complex(const int &, const int &);
  Complex(const Complex &);
  ~Complex();

  Complex plus(const Complex &);
  int numberOfComplex();
  static int nNumberOfComplex();
};

Complex::Complex() {

  real = im = 0;
  sl++;
  ssl++;
}
Complex::Complex(const int &th, const int &a) {

  real = th, im = a;
  sl++;
  ssl++;
}
Complex::Complex(const Complex &sp) {

  real = sp.real;
  im = sp.im;
  sl++;
  ssl++;
}
Complex::~Complex() {

  sl--;
  ssl--;
}

Complex Complex::plus(const Complex &sp) {

  Complex res(*this);
  res.im += sp.im;
  res.real += sp.real;

  return res;
}

int Complex::numberOfComplex() { return sl; }
int Complex::nNumberOfComplex() { return ssl; }

int Complex::ssl = 0;

int main() {

  Complex sp1;
  Complex sp2(5, 10);
  Complex sp3(sp1);
  Complex sp4 = sp2.plus(sp1);

  std::cout << Complex::nNumberOfComplex() << std::endl;

  {
    Complex sp5;
    Complex sp6 = sp2.plus(sp4);
  }

  std::cout << sp4.numberOfComplex() << std::endl;
  std::cout << Complex::nNumberOfComplex() << std::endl;

  return 0;
}
