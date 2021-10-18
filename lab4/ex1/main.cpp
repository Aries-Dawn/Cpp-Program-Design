#include <iostream>
#include "include/stuinfo.hpp"


using namespace std;

int main(){
    int n = 5;
    cin >> n;
    string temp;
    getline(cin,temp);
    stuinfo *stu = new stuinfo[n];
    inputstu(stu,n);
    showstu(stu,n);
    sortstu(stu,n);
    printf("Please input the name you want to find :");
    char name[20];
    string str;
    getline(cin,str);
    strcpy(name,(char *)str.data());
    if (findstu(stu,n,name))
    {
        printf("%s is in students list.\n", name);
    }
    else {
        printf("%s is not in students list.\n", name);
    }
}