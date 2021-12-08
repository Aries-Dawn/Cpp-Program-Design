#include <iostream>

using namespace std;

class CStereoShape
{
private:
    static int numberOfObject;
    /* data */
public:
    CStereoShape(/* args */);
    virtual double GetArea();
    virtual double GetVolume();
    virtual void show();
    int GetNumOfObject();
    ~CStereoShape();
};

int CStereoShape::numberOfObject = 0;

CStereoShape::CStereoShape(/* args */)
{
    this->numberOfObject += 1;
}

CStereoShape::~CStereoShape()
{
}
double CStereoShape::GetArea(){
    cout<<"CStereoShape::GetArea()"<<endl;
    return 0.0;
}
double CStereoShape::GetVolume(){
    cout<<"CStereoShape::GetVolume()"<<endl;
    return 0.0;
}
void CStereoShape::show(){
    cout<<"CStereoShape::Show()"<<endl;
}
int CStereoShape::GetNumOfObject(){
    return numberOfObject;
}

class CCube : public CStereoShape
{
private:
    double length;
    double width;
    double height;
public:
    CCube(/* args */);
    CCube(const CCube &that);
    CCube(double length,double width, double height);
    double GetArea();
    double GetVolume();
    void show();
    ~CCube();
};

CCube::CCube(/* args */):CStereoShape()
{
    this->length    = 2;
    this->width     = 2;
    this->height    = 2;
}
CCube::CCube(const CCube &that):CStereoShape()
{
    this->length = that.length;
    this->width = that.width;
    this->height = that.height;
}

CCube::CCube(double length,double width, double height)
{
    this->length = length;
    this->width = width;
    this->height = height;
}

CCube::~CCube()
{
}
double CCube::GetArea(){
    return length*height*2 + width*height*2 + length*width*2;
}
double CCube::GetVolume(){
    return length*height*width;
}
void CCube::show(){
    cout.precision(0);
    cout.setf(ios_base::fixed);
    cout<<"Cube length: " <<length<<"   width: "<<width<<"    height: "<<height<<endl;
    cout<<"Cube Area: "<<GetArea()<<"   Cube Volume: "<<GetVolume()<<endl;
}
class CSphere:CStereoShape
{
private:
    double radius;
public:
    CSphere(/* args */);
    CSphere(double radius);
    CSphere(const CSphere &that);
    double GetArea();
    double GetVolume();
    void show();
    ~CSphere();
};

CSphere::CSphere(/* args */):CStereoShape()
{
    radius = 3;
}
CSphere::CSphere(double r):CStereoShape()
{
    this->radius = r;
}
CSphere::CSphere(const CSphere &that)
{
    this->radius = that.radius;
}
double CSphere::GetArea()
{
    return 4*3.14*radius*radius;
}
double CSphere::GetVolume()
{
    return 4.0*3.14*radius*radius*radius/3;
}
void CSphere::show()
{
    cout.precision(2);
    cout.setf(ios_base::fixed);
    cout<<"Sphere radius: " <<radius<<endl;
    cout<<"Sphere Area: "<<GetArea()<<"   Sphere Volume: "<<GetVolume()<<endl;
}
CSphere::~CSphere()
{
}

int main(){
    CCube a_cube(4.0,5.0,6.0);
    CSphere c_sphere(7.9);
    CStereoShape *p = (CStereoShape *)&a_cube;
    p->show();
    p = (CStereoShape *)&c_sphere;
    p->show();
    cout<<p->GetNumOfObject()<<" objects are created."<<endl;
}