#include <iostream>
#include <string>
using namespace std;

class shape{
    public:
    virtual double area()=0;
};
class rectangle:public shape{
    protected:
    int width;
    int height;
    public:
    rectangle(int w,int h){
        width=w;
        height=h;
    }
    double area() override {
        return width*height;
    }
};
class circle :public shape{
    protected:
    double radius;
    public:
    circle(int r){
        radius=r;
    }
    double area() override{
        return 3.142*radius*radius;
    }
};

int main(){
    rectangle r1(10,20);
    cout<<"Area of rectangle :"<<r1.area()<<endl;
    circle c1(12);
    cout<<"Area of circle :"<<c1.area();
    return 0;
}