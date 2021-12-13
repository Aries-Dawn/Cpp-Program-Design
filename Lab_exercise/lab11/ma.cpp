#include <iostream>

using namespace std;

class Matrix {
 public:
  size_t row;
  size_t col;
  float *ptr;

 public:
  Matrix(size_t row, size_t col);
  Matrix operator+(Matrix &m);
  Matrix operator=(Matrix &m);
  Matrix operator*(float f);
  void set_Data(float *f, size_t len);
  ~Matrix();
};

Matrix::Matrix(size_t row, size_t col) {
  this->row = row;
  this->col = col;
  this->ptr = new float[row * col];
}

Matrix::~Matrix() { delete[] ptr; }
Matrix Matrix::operator+(Matrix &m) {
  // if (m.row != this->row || m.col!=this->col)
  // {
  //     cout<<"Size Not Equal \n"<<this->row<<" * "<<this->col<<" + "<<m.row<<"
  //     * "<<m.col<<endl; return NULL;
  // }
  // else{
  Matrix temp(m.row, m.col);
  size_t size = m.row * m.col;
  for (size_t i = 0; i < size; i++) {
    temp.ptr[i] = this->ptr[i] + m.ptr[i];
  }
  return temp;
  // }
}

Matrix Matrix::operator*(float f) {
  size_t size = this->row * this->col;
  Matrix result(this->row, this->col);
  for (size_t i = 0; i < size; i++) {
    result.ptr[i] = this->ptr[i] * f;
  }
  return result;
}
void Matrix::set_Data(float *f, size_t len) {
  size_t temp = 0;
  for (size_t i = 0; i < this->row * this->col; i++) {
    if (temp > len) {
      this->ptr[i] = 0;
    } else {
      this->ptr[i] = f[temp];
    }
    temp += 1;
  }
}
Matrix Matrix::operator=(Matrix &m) {
  this->col = m.col;
  this->row = m.row;
  this->ptr = new float[row * col];
  size_t size = m.col * m.col;
  for (size_t i = 0; i < size; i++) {
    this->ptr[i] = m.ptr[i];
  }
  return *this;
}

void display(Matrix &m){
    size_t t = 0;
    for (size_t i = 0; i < m.row; i++)
    {
        for (size_t j = 0; j < m.col; j++)
        {
            cout<<m.ptr[t]<<" ";
            t++;
        }
        cout<<endl;
    }
}

int main() {
  Matrix a(3, 4);
  Matrix b(3, 4);
  float *f = new float[12];
  float num = 3.0f;
  for (size_t i = 0; i < 12; i++) {
    f[i] = num;
    num += 1.0f;
    num = (float)((int)num % 7);
  }
  a.set_Data(f, 12);
  b.set_Data(f, 12);
  cout<<"this is a\n";
  display(a);
  cout<<"this is b\n";
  display(b);
  Matrix c = a + b;
  cout<<"this is a + b\n";
  display(c);
  Matrix d = a * 2.0f;
  cout<<"this is a * 2.0f\n";
  display(d);
  delete[] f;
}