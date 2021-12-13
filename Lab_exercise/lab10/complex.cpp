#include <iomanip>
#include <iostream>

using namespace std;

class complex {
 private:
  double real;
  double img;

 public:
  void set_real(double real);
  void set_img(double img);
  complex(double real, double img);
  complex();
  complex add(complex a, complex b) const;
  complex sub(complex a, complex b) const;
  complex operator+(const complex &b);
  complex operator-(const complex &b);
  complex operator=(const complex &b);
  complex operator*(const complex &b);
  bool operator==(const complex &b);
  bool operator!=(const complex &b);
  friend std::ostream &operator<<(std::ostream &os, const complex &c);
  friend std::istream &operator>>(std::istream &is, complex &c);
  double get_real() const;
  double get_img() const;
  void show() const;
};
void complex::show() const {
  if (this->img >= 0) {
    printf("%.2f + %.2fi", this->get_real(), this->get_img());
  } else {
    printf("%.2f - %.2fi", this->get_real(), this->get_img() * -1);
  }
};
double complex::get_real() const { return this->real; };
double complex::get_img() const { return this->img; };

complex::complex(double real, double img) {
  this->real = real;
  this->img = img;
};

void complex::set_real(double real) { this->real = real; }
void complex::set_img(double img) { this->img = img; }

complex::complex(){};
complex complex::add(complex a, complex b) const {
  double real = a.get_real() + b.get_real();
  double img = a.get_img() + b.get_img();
  complex *result = new complex(real, img);
  return *result;
};
complex complex::sub(complex a, complex b) const {
  double real = a.get_real() - b.get_real();
  double img = a.get_img() - b.get_img();
  complex *result = new complex(real, img);
  return *result;
};

complex complex::operator+(const complex &b) {
  return complex(get_real() + b.get_real(), get_img() + b.get_img());
}
complex complex::operator-(const complex &b) {
  return complex(get_real() - b.get_real(), get_img() - b.get_img());
}
complex complex::operator=(const complex &b) {
  return complex(b.get_real(), b.get_img());
}
complex complex::operator*(const complex &b) {
  return complex((get_real() * b.get_real()) - (get_img() * b.get_img()),
                 (b.get_real() * get_img()) + (get_real() * b.get_img()));
}
bool complex::operator==(const complex &b) {
  return real == b.get_real() && img == b.get_img();
}
bool complex::operator!=(const complex &b) {
  return real != b.get_real() || img != b.get_img();
}

std::ostream &operator<<(std::ostream &os, const complex &c) {
  cout << fixed << setprecision(2);
  if (c.get_img() >= 0) {
    os << c.get_real() << " + " << c.get_img() << "i";
  } else {
    os << c.get_real() << " - " << c.get_img() * -1 << "i";
  }
  return os;
};
std::istream &operator>>(std::istream &is, complex &c) {
  int real, img;
  is >> real;
  is >> img;
  c.set_real(real);
  c.set_img(img);
  return is;
};

int main() {
  complex a, b;
  cin >> a;
  cin >> b;
  complex c = a + b;
  complex d = a - b;
  complex e = a * b;
  bool equal = a == b;
  bool not_equal = a != b;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "a + b = " << c << endl;
  cout << "a - b = " << d << endl;
  cout << "a * b = " << e << endl;
  cout << "is a = b ? " << boolalpha << equal << endl;
  cout << "is a != b ? " << boolalpha << not_equal << endl;
}
