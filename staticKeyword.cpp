#include <iostream>
using namespace std;

class MyClass {
    static int objectCount; // Static member variable
public:
    MyClass() {
        objectCount++; // Increment object count whenever an object is created
    }

    // Static member function
    static int getObjectCount() {
        return objectCount;
    }
};

// Define and initialize the static member variable outside the class
int MyClass::objectCount = 0;

int main() {
    MyClass obj1;
    cout<<obj1.getObjectCount()<<endl;
    MyClass obj2;
    cout<<obj2.getObjectCount()<<endl;
    MyClass obj3;
    cout<<obj3.getObjectCount()<<endl;

    // Call the static member function to get the count of objects
    cout << "Total objects created: " << MyClass::getObjectCount() << endl;

    return 0;
}
