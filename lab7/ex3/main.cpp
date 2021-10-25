#include <iostream>

using namespace std;

template <typename T>
T minimum(T a, T b){
    return a > b ? b : a;
}

int main(){
    int ai = 7;
    int bi = 2;
    char ac = 'd';
    char bc = 'g';
    float af = 3.4;
    float bf = 9.2;
    double ad = 4.3;
    double bd = 5.0;
    cout<<"Test Integer:\na = "<<ai<<"\nb = "<<bi<<"\nThe minimum is "<<minimum<int>(ai,bi)<<endl;
    cout<<"Test Character:\na is "<<ac<<"\nb is "<<bc<<"\nThe minimum is "<<minimum<char>(ac,bc)<<endl;
    cout<<"Test Float:\na = "<<af<<"\nb = "<<bf<<"\nThe minimum is "<<minimum<float>(af,bf)<<endl;
    cout<<"Test Double:\na = "<<ad<<"\nb = "<<bf<<"\nThe minimum is "<<minimum<double>(af,bf)<<endl;
}
