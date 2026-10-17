#include <iostream>
#include <ostream>

class Complex {

private:
  int real, im;

public:
  Complex();
  Complex(const int &);
  Complex(const int &, const int &);
  Complex(const Complex &);
  ~Complex();

  friend Complex operator+(const int &, const Complex &);
  friend std::ostream &operator<<(std::ostream &, const Complex &);
};

Complex operator+(const int &a, const Complex &src) {

  return Complex(a + src.real, src.im);
}

std::ostream &operator<<(std::ostream &outDev, const Complex &src) {
  outDev << src.real;
  if (src.im < 0)
    outDev << "-";
  else
    outDev << "+";

  outDev << src.im << "i";

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
  Complex sp3 = 10 + sp1;
  // Complex sp4 = sp2.plus(sp1);

  std::cout << sp1;
  std::cout << "\n";
  std::cout << sp3;
  std::cout << "\n";

  return 0;
}
