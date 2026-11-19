#include <iostream>
#include <ostream>

class Complex {

private:
  int real, im;

public:
  Complex();
  Complex(const int &, const int &);
  Complex(const Complex &);
  ~Complex();

  Complex operator+(const int &);
  std::ostream &operator<<(std::ostream &);
};

Complex Complex::operator+(const int &a) {
  return Complex(real + a,
                 im); // only work seemlessy when there are no dynamic mems
}

std::ostream &Complex::operator<<(std::ostream &outDev) {
  outDev << real;
  if (im < 0)
    outDev << "-";
  else
    outDev << "+";

  outDev << im << "i";

  return outDev;
}

Complex::Complex() { real = im = 0; }
Complex::Complex(const int &th, const int &a) { real = th, im = a; }
Complex::Complex(const Complex &sp) {

  real = sp.real;
  im = sp.im;
}
Complex::~Complex() {}

int main() {

  Complex sp1(3, 5);
  Complex sp2 = sp1.operator+(10);
  Complex sp3 = sp1 + 10;
  // Complex sp4 = sp2.plus(sp1);

  sp1.operator<<(std::cout);
  std::cout << "\n";
  sp2.operator<<(std::cout);
  std::cout << "\n";
  sp3.operator<<(std::cout);
  std::cout << "\n";

  return 0;
}
