#include <iostream>
#include <string>
using namespace std;

class person{
    string name;
    int age;
    public:
    person(string n,int a){
        name=n;
        age=a;
    }
    friend class student;
};

class student{
    int roll;
    public:
    student(int r){
        roll=r;
    }
    void display(person p1){
        cout<<"Student detail :"<<endl;
        cout<<"Student name :"<<p1.name<<endl;
        cout<<"roll number: "<<roll<<endl;
        cout<<"age : "<<p1.age<<endl;
    }
};
int main(){
    person p1("Umaima",18);
    student s1(10);
    s1.display(p1);
}