#include <iostream>


using namespace std;

struct point{
float x;
float y;

};

point setValuePassByValue(struct point p, float x, float y);
void calculateMidPoint(struct point &a,struct point &b);

int main(){
    point p;
    p = setValuePassByValue(p, 3.0, 4.0);
    cout<<"the x number is "<<p.x<<endl<<"the y number is "<<p.y<<endl;
    point pa,pb;
    pa.x = 2.0;
    pa.y = 2.0;
    pb.x = 4.0;
    pb.y = 4.0;
    calculateMidPoint(pa,pb);
}


point setValuePassByValue(struct point p, float x, float y){
    p.x = x;
    p.y = y;
    return p;
}
void calculateMidPoint(struct point &a,struct point &b){
    float mid_x,mid_y;
    mid_x = (a.x + b.x)/2;
    mid_y = (a.y + b.y)/2;
    cout<<"The middle point is : (x,y) - ("<<mid_x<<","<<mid_y<<")"<<endl;
}