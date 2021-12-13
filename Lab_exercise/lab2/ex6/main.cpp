#include <iostream>
#include <stdio.h>
#include <iostream>
using namespace std;

void printFloat(float num)
{
    int inum = *(int*)&num;
    for (int i = 0; i < 32; ++i) {
        cout << ((inum&0x80000000) ? 1 : 0);
        if (i == 0 || i == 8)
            cout << " ";
        inum <<= 1;
    }
    cout << endl;
}

int main(){
    float a = 0.1;
    float c = 1.0;
    float d = a + a + a + a + a + a + a + a +a + a ;
    cout<< "The binary presentation of a : ";
    printFloat(a);
    // cout<< "The binary presentation of b : ";
    // printFloat(b);
    cout<< "The binary presentation of c : ";
    printFloat(c);
    cout<< "The binary presentation of d : ";
    printFloat(d);
    return 0;
}

