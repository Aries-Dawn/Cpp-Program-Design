#include "inc/fib.hpp"

int *fib(int n){
    int *fibonacci = new int[n];
    if (n == 1)
    {
        fibonacci[0] = 1;
        return fibonacci;
    }
    else if (n == 2)
    {
        fibonacci[0] = 1;
        fibonacci[1] = 1;
        return fibonacci;
    }
    else
    {
        fibonacci[0] = 1;
        fibonacci[1] = 1;
        for (int i = 2; i < n; i++)
        {
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
        }
        return fibonacci;
    }
    
    
    
}