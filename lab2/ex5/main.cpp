#include <stdio.h>

int main(){
    int a = 121;
    char b = (char)a;
    char c = 'F';
    int d = (int)c;
    printf("int  a = %d conversion to char %c\n",a,b);
    printf("char c = %c conversion to int  %d\n",c,d);
    return 0;
}