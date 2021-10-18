#include <iostream>
#include "include/swap.h"

using namespace std;

int main ()
{
   // local variable
   int a = 100;
   int b = 200;
 
   cout << "按值传递交换前，a 的值：" << a << endl;
   cout << "按值传递交换前，b 的值：" << b << endl;
 
   /* call the swap function */
   swapByInteger(a, b);
 
   cout << "按值传递交换后，a 的值：" << a << endl;
   cout << "按值传递交换后，b 的值：" << b << endl;

      // local variable
    int *pa = new int[2];
    pa[0] = 100;
    pa[1] = 200;
 
   cout << "pointer arguments交换前，a 的值：" << pa[0] << endl;
   cout << "pointer arguments交换前，b 的值：" << pa[1] << endl;
 
   /* call the swap function */

   swapByPointer(pa, pa+1);
 
   cout << "pointer arguments交换后，a 的值：" << pa[0] << endl;
   cout << "pointer arguments交换后，b 的值：" << pa[1] << endl;


      // local variable
   a = 100;
   b = 200;
 
   cout << "reference arguments交换前，a 的值：" << a << endl;
   cout << "reference arguments交换前，b 的值：" << b << endl;
 
   /* call the swap function */
   swapByReference(a, b);
 
   cout << "reference arguments交换后，a 的值：" << a << endl;
   cout << "reference arguments交换后，b 的值：" << b << endl;


   
   return 0;
}