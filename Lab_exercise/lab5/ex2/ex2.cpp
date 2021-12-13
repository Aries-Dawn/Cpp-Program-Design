#include <iostream>

using namespace std;

int main(){
    char *arr = new char[5];
    char *old = arr;
    // *(arr-1) = 'k';
    *arr = 'a';
    arr += 1;
    *arr = 'b';
    arr += 1;
    *arr = 'c';
    arr += 1;
    *arr = 'd';
    arr += 1;
    *arr = 'e';
    arr += 1;
    // *arr = 'h';
    // arr += 1;
    for (int i = 0; i < 7; i++)
    {
        arr--;
        cout<<*arr<<endl;
    }
    
    delete[] old;
}