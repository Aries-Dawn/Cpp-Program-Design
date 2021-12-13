#include "include/swap.h"
#include <vector>

 void swapByInteger(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void swapByPointer(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void swapByReference(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}