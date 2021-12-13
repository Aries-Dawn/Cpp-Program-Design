#include <iostream>
#include <string>
#include "include/function.h"
using namespace std;

int main(){
    cout<<"Please input a String"<<endl;
    string str;
    getline(cin,str);
    cout<<"Please input a character"<<endl;
    char in;
    cin >> in;
    char *result = match((char *)str.data(),in);
    if (result == nullptr)
        cout<<"Not Found"<<endl;
    else{
        cout<<&result[0]<<endl;
        cout<<result<<endl;
    }
    return 0;
}