#include <iostream>

using namespace std;

int main(){
    int *arr = new int[5];
    int *old = arr;
    for (int i = 0; i < 5; i++)
    {
        *arr = i;
        arr += 1;
    }
    for (int i = 0; i < 5; i++)
    {
        arr--;
        cout<<*arr<<endl;
    }
    delete[]arr;
}