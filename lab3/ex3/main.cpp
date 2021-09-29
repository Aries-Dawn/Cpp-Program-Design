#include <iostream>
#include <algorithm>
#include <cstring> 
#include <stdlib.h>  //为了使用 c_str() 函数 
#include <string>
#include <regex>

#include "inc/calculater.hpp"

using namespace std;


//string 2 char array and check is or not integer
int check(string s){
    const int len = s.length();
	char *a = new char[len];
	strcpy(a,s.c_str());
	int i;
	for(i = 1;i<len;i++){
		//not integer
		if(!isdigit(a[i])){
			return 0; 
		}
	}
    if (a[0] == '-')
    {
        return 1;
    }
    if(!isdigit(a[0])){
        
        return 0; 
    }
	return 1;
}

//string 2 int
int s2i(string s)
{
	return atoi( s.c_str() );
}

bool isOperation(string s){
    char a = s[0];
    return a == '+' || a == '-' || a == '*' || a == '/' || a == '%';
}

void cal(){
    string operation;
    cout << "Please select an operation:\n+\n-\n*\n/\n%\n" ;
    cin >> operation;
    while (operation.length() != 1 || !isOperation(operation))
    {
        cout << "Please select an operation:\n+\n-\n*\n/\n%\n" ;
        cin >> operation;
    }
    
    char ope = operation[0];
    string input1, input2;
    cout << "Please input two integers :\n" ;
    cin >> input1;
    cin >> input2;
    while (!(check(input1) && check(input2)))
    {   
        cout << "Please input two integers :\n" ;
        cin >> input1;
        cin >> input2;
    }
    int n1 = s2i(input1);
    int n2 = s2i(input2);
    int n;
    string temp;
    switch (ope)
    {
    case '+':
        n = n1 + n2;
        break;
    case '-':
        n = n1 - n2;
        break;
    case '*':
        n = n1 * n2;
        break;
    case '/':
        while (n2 == 0)
        {
            cout<<"The dividend can no be 0, please input the dividend again."<<endl;
            cin >> temp;
            while (!check(temp))
            {   
                cout << "Please input integers :\n" ;
                cin >> temp;
            }
            n2 = s2i(temp);
        }
        n = n1 / n2;
        break;
    case '%':
        while (n2 == 0)
        {
            cout<<"The dividend can no be 0, please input the dividend again."<<endl;
            cin >> temp;
            while (!check(temp))
            {   
                cout << "Please input integers :\n" ;
                cin >> temp;
            }
            n2 = s2i(temp);
        }
        n = n1 % n2;
        break;
    
    default:
        break;
    }
    cout<<n1<<" "<<ope<<" "<<n2<<" = "<<n<<endl;
    
}

int main(){
    string isOrNo{"Y"};
    while (isOrNo[0] == 'Y' || isOrNo[0] == 'y')
    {
        cal();
        cout<<"Do you want to continue?(Y/N)";
        cin>>isOrNo;
    }
    cout<<"The operation is over."<<endl;
}