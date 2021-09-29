# CS205 C/ C++ Programming - Project1

> 樊顺
>
> 11811901

## Part 1 - Requirement

### Task1

![image-20210919234447867](C:\Users\30556\AppData\Roaming\Typora\typora-user-images\image-20210919234447867.png)

### Task2

<img src="C:\Users\30556\AppData\Roaming\Typora\typora-user-images\image-20210919234501598.png" alt="image-20210919234501598" style="zoom:80%;" />

### Task3

> If input wrong input. Program will ask you input again.

![image-20210919234832503](C:\Users\30556\AppData\Roaming\Typora\typora-user-images\image-20210919234832503.png)

### Task4

![image-20210919234944553](C:\Users\30556\AppData\Roaming\Typora\typora-user-images\image-20210919234944553.png)

### Task5

#### 1> negative number

![image-20210919235049760](C:\Users\30556\AppData\Roaming\Typora\typora-user-images\image-20210919235049760.png)

#### 2>wrong number of args

![image-20210919235123561](C:\Users\30556\AppData\Roaming\Typora\typora-user-images\image-20210919235123561.png)

## Part 2 - code

```c++
#include<iostream>
#include<algorithm>
#include<cstring> 
#include<stdlib.h>  //为了使用 c_str() 函数 

using namespace std;


//将string转为char数组并判断输入是否为整数
int check1(string s){
    const int len = s.length();
	char *a = new char[len];
	strcpy(a,s.c_str());
	int i;
	for(i = 1;i<len;i++){
		//如果不是数字
		if(!isdigit(a[i])){
			return -1; 
		}
	}
    
    if (a[0] == '-')
    {
        return 0;
    }
    if(!isdigit(a[0])){
        
        return -1; 
    }

    if (a[0] - '0' == 0)
    {
        return -1; 
    }
    
	return 0; 
    
}

//string 转 int
int s2i(string s)
{
	return atoi( s.c_str() );
}



int main(int argc, char *argv[]){
    string input1;
    string input2;
    if (argc == 1)
    {
        cout << "Please input two integer :" ;
        cin >> input1;
        cin >> input2;
    }
    else if (argc == 3)
    {
        input1 = argv[1];
        input2 = argv[2];
        if (check1(input1) || check1(input2))
        {
            cout<<"Please input correct integer"<<endl;
            return 0;
        }
        
    }
    else
    {
        cout<<"Please input correct number integer"<<endl;
        return 0;
    }
    
    
    while (check1(input1) || check1(input2))
    {   
        cout << "Please input two integer :" ;
        cin >> input1;
        cin >> input2;
    }
    long long n1 = s2i(input1);
    long long n2 = s2i(input2);
    long long result = n1 * n2;
    cout<<n1<<" * "<<n2<<" = "<<result<<endl;
    
}
```

## Part 4 - Problems

+ int always overflow
  + I use `long long` type to store
+ check negative
  + I firstly check the first point of the array which store the input. If it is `'-'`, I will think this can have the choice to be a integer. The other part just check is or not an positive integer. 
+ check the input is or not a number
  + I use three lib:`#include<algorithm>` and `#include<cstring> ` and `#include<stdlib.h>`

