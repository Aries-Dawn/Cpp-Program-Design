#include "include/stuinfo.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;


void inputstu(stuinfo stu[] , int n){
    printf("Please input information of %d students : \n", n);
    for (int i = 0; i < n; i++)
    {
        string str;
        string temp;
        printf("Student %d's name:",i);
        getline(cin,str);
        strcpy(stu[i].name,(char *)str.data());
        // stu[i].name = (char *)str.data();
        // scanf("%s",stu[i].name);
        printf("%s\n",stu[i].name);
        printf("Student %d's scores:",i);
        for (int j = 0; j < 3; j++){
            cin >> stu[i].score[j];
            printf("%f\n",stu[i].score[j]);
        }
            // scanf("%f",stu[i].score[j]);
        stu[i].ave = (stu[i].score[0] + 
                        stu[i].score[1] + 
                        stu[i].score[2])/3.0;
                        
        getline(cin,str);
    }
}
void showstu(stuinfo stu[] , int n){
    printf("The information of %d students you input are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Student %d name: %s, scores: %.2f %.2f %.2f\r\n",
                i,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
    }
}

bool compare(stuinfo a,stuinfo b)
{
    return a.ave>b.ave; //升序排列，如果改为return a>b，则为降序
}

void sortstu(stuinfo stu[] , int n){
    printf("The descending order of the students:\n");
    std::sort(stu,stu+n,compare);
    for (int i = 0; i < n; i++)
    {
        printf("Student %d name : %s, scores: %.2f %.2f %.2f average: %.4f\r\n",i,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].ave);
    }
    
}
bool findstu(stuinfo stu[] , int n, char ch[]){
    for (int i = 0; i < n; i++)
    {
        char *n = stu[i].name;
        char *f = ch;
        printf("%s,%s\n",n,f);
        printf("%s,%s\n",stu[i].name,ch);
        if (strncmp(n,f,20)==0)
        {
            return true;
        }
        
    }
    return false;
}