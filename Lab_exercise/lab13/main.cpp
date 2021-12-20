#include <iostream>
#include "stdlib.h"

using namespace std;

template <class T>
class Matrix {
 private:
  T *p_mat;
  int row;
  int col;

 public:
  Matrix(int row, int col, T *list);
  Matrix(int row, int col);
  Matrix<T> operator+(Matrix<T> &m);
  Matrix<T> operator*(Matrix<T> &m);
  T& operator()(int row, int col);
  void operator+=(Matrix<T> &m);
  void print();
  ~Matrix();
};

template <class T>
Matrix<T>::Matrix(int row, int col) {
  this->row = row;
  this->col = col;
  p_mat = (T *)calloc(row * col, sizeof(T));
}
template <class T>
Matrix<T>::Matrix(int row, int col, T *list) {
  this->row = row;
  this->col = col;
  p_mat = (T *)calloc(row * col, sizeof(T));
  for (size_t i = 0; i < row * col; i++) {
    p_mat[i] = list[i];
  }
}
template <class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &m) {
  Matrix<T> temp(m.row, m.col);
  if (this->row != m.row || this->col != m.col) {
    cerr << "Not same size";
    return temp;
  }
  for (size_t i = 0; i < m.row * m.col; i++) {
    temp.p_mat[i] = this->p_mat[i] + m.p_mat[i];
  }
  return temp;
}
template <class T>
void Matrix<T>::operator+=(Matrix<T> &m) {
  if (this->row != m.row || this->col != m.col) {
    cerr << "Not same size";
    return;
  }
  for (size_t i = 0; i < m.row * m.col; i++) {
    this->p_mat[i] = this->p_mat[i] + m.p_mat[i];
  }
  return;
}
template <class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &m) {
  Matrix<T> temp(m.row, m.col);
  if (this->row != m.col || this->col != m.row) {
    cerr << "size error can't multiple";
    return temp;
  }
  for (int i = 0; i < temp.row; i++) {
    for (int k = 0; k < this->col; k++) {
      float tmp = this->p_mat[i * this->col + k];
      for (int j = 0; j < temp.col; j++) {
        temp.p_mat[i * this->col + j] += tmp * m.p_mat[k * this->col + j];
      }
    }
  }
  return temp;
}
template <class T>

T& Matrix<T>::operator()(int row, int col) {
  return this->p_mat[(row)*this->col + col];
}
template <class T>
void Matrix<T>::print() {
  size_t t = 0;
  for (size_t i = 0; i < this->row; i++) {
    for (size_t j = 0; j < this->col; j++) {
      cout << this->p_mat[t] << " ";
      t++;
    }
    cout << endl;
  }
}

template <class T>
Matrix<T>::~Matrix() {
  free(p_mat);
}

int main() {
  float *f = new float[12];
  float num = 3.3f;
  for (size_t i = 0; i < 12; i++) {
    f[i] = num;
    num += 1.0f;
    num = (float)((int)num % 7) + 0.4;
  }
  Matrix<float> a(3, 4, f);
  Matrix<float> b(3, 4, f);
  Matrix<float> x(4, 3, f);
  cout << "a:" << endl << endl;
  a.print();
  cout<<a(1,1)<<endl;
  cout << "b:" << endl << endl;
  b.print();
  a += b;
  cout << "a + b:" << endl << endl;
  a.print();
  Matrix<float> d = a * x;
  cout << "x:" << endl << endl;
  x.print();
  cout << "a * x:" << endl << endl;
  d.print();
}