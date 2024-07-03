#include <iostream>
#include <string>
using namespace std;

class chair {
    string material;
    string color;
    float height;
public:
    chair(string m, string c, float h) : material(m), color(c), height(h) {}

    void showDetails() const {
        cout << "Chair Details: " << endl;
        cout << "Material: " << material << endl;
        cout << "Color: " << color << endl;
        cout << "Height: " << height << " cm" << endl;
    }
};

class table {
    string material;
    string color;
    float length;
    float width;
public:
    table(string m, string c, float l, float w) : material(m), color(c), length(l), width(w) {}

    void showDetails() const {
        cout << "Table Details: " << endl;
        cout << "Material: " << material << endl;
        cout << "Color: " << color << endl;
        cout << "Length: " << length << " cm" << endl;
        cout << "Width: " << width << " cm" << endl;
    }
};

class Classroom {
    chair* chairs[10];
    table* tb;
    float height;
    float width;
public:
    Classroom(float h, float w) : height(h), width(w), tb(nullptr) {
        for (int i = 0; i < 10; i++) {
            chairs[i] = nullptr;
        }
    }

    void addchair(chair* chair1, int chairno) {
        if (chairno > 0 && chairno <= 10) {
            chairs[chairno - 1] = chair1;
            cout << "The chair " << chairno << " is added at position " << static_cast<void*>(chair1) << endl;
        } else {
            cout << "Invalid chair number. Please enter a number between 1 and 10." << endl;
        }
    }

    void addtable(table* table1) {
        tb = table1;
        cout << "Table is added at position " << static_cast<void*>(table1) << endl;
    }

    void showClassroomDetails() const {
        cout << "Classroom Details: " << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Width: " << width << " cm" << endl;
        if (tb != nullptr) {
            tb->showDetails();
        } else {
            cout << "No table in the classroom." << endl;
        }
        for (int i = 0; i < 10; i++) {
            if (chairs[i] != nullptr) {
                cout << "Chair " << (i + 1) << ": ";
                chairs[i]->showDetails();
            }
        }
    }
};

int main() {
    Classroom c(300, 500);
    chair ch1("Wood", "Brown", 100);
    chair ch2("Metal", "Black", 120);
    table t1("Wood", "Brown", 200, 100);

    c.addchair(&ch1, 1);
    c.addchair(&ch2, 2);
    c.addtable(&t1);

    c.showClassroomDetails();

    return 0;
}
