#include <iostream>
// using namespace std;

class Stock{
    public:
    Stock();
    Stock(const std::string &co,long n = 0,double pr = 0.0);
    ~Stock();
};

int main(){
    Stock st1;
    // Stock st2("MSFT",3,2.0f);
    // Stock st3 = Stock("MSFT",3,2.0f);
    // Stock st4 = Stock("MSFT", ,2.0f);
}