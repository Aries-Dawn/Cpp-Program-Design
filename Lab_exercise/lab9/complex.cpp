#include <iostream>

using namespace std;

class complex {
 private:
  double real;
  double img;

 public:
  complex(double real, double img);
  complex add(complex a, complex b) const;
  complex sub(complex a, complex b) const;
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

int main() {
  complex *a = new complex(2, 3);
  complex *b = new complex(5, 5);
  complex c = a->add(*a, *b);
  complex d = a->sub(*a, *b);
  a->show();
  cout << " + ";
  b->show();
  cout << " = ";
  c.show();
  cout << endl;
  a->show();
  cout << " - ";
  b->show();
  cout << " = ";
  d.show();
  cout << endl;
}
