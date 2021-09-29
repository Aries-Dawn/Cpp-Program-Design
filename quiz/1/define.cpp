#include <iostream>
#include <typeinfo>

#define PI 3.14

int main(){
    std::cout<<typeid(PI).name() <<std::endl;
}