#include<iostream>
#include<algorithm>
#include<cstring> 
#include<stdlib.h>  //为了使用 c_str() 函数 

#include "inc/fac.hpp"

using namespace std;


//将string转为char数组并判断输入是否为正整数
int check1(string s){
    const int len = s.length();
	char *a = new char[len];
	strcpy(a,s.c_str());
	int i;
	for(i = 0;i<len;i++){
		//如果不是数字
		if(!isdigit(a[i])){
			return -1; 
		}
	}
	return 0; 
    
}

//string 转 int
int s2i(string s)
{
	return atoi( s.c_str() );
}



int main(){
    string input;
    cout << "Please input a positive integer :" ;
    cin >> input;
    while (check1(input))
    {   
        cout << "Please input a positive integer :" ;
        cin >> input;
    }
    int n = s2i(input);
    for (int i = 0; i <= n; i++)
    {
        long long result = calculate(i+1);
        cout<<i<<"! = "<<result<<endl;
    }
}