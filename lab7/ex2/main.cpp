#include <cmath>
#include <iostream>

using namespace std;


template <typename T>
void prints(T *ptr, int n){
    T *old = ptr;
    for (int i = 0; i < n; i++)
    {
        cout<<*ptr<<" ";
        ptr++;
    }
    cout<<endl;
    // ptr = old;
}
void vabs(int *p, int n) {
  int *flag = p;
  for (int i = 0; i < n; i++) {
    *flag = abs(*flag);
    flag += 1;
  }
}
void vabs(float *p, int n) {
  float *flag = p;
  for (int i = 0; i < n; i++) {
    *flag = abs(*flag);
    flag += 1;
  }
}
void vabs(double *p, int n) {
  double *flag = p;
  for (int i = 0; i < n; i++) {
    *flag = abs(*flag);
    flag += 1;
  }
}


int main() {
    int n = 6;
    int *intarr = new int[6]{-11,-2,3,-4,5,-6};
    float *floatarr = new float[6]{-23.9,-2.7,3.6,-4.5,5.3,-6.3};
    double *doublearr = new double[6]{-11.2,-2.8,3.8,-4.5,4.5,-6.4};
    cout<<"The init int arr is :";
    prints(intarr,n);
    vabs(intarr,n);
    cout<<"The abs int arr is : ";
    prints(intarr,n);

    cout<<"The init float arr is :";
    prints(floatarr,n);
    vabs(floatarr,n);
    cout<<"The abs float arr is : ";
    prints(floatarr,n);

    cout<<"The init double arr is :";
    prints(doublearr,n);
    vabs(doublearr,n);
    cout<<"The abs double arr is : ";
    prints(doublearr,n);
    free(intarr);
    free(floatarr);
    free(doublearr);

}