#include <iostream>

using namespace std;

struct people
{
    string name;
    int age;
};

void init(people *p){
    p->name = "No Name";
    p->age = 0;
}


int main(){
    people p;
    p.age = -1;
    init(&p);
    cout<<p.age<<endl;

    return 0;
}