#include <iostream>
#include <string>
using namespace std;

class Date {
    int day;
    int year;
    int month;
public:
    static const int months = 12;
    Date(int d, int y, int m) {
        year = (y > 2000 && y < 2050) ? y : 0;
        month = (m > 0 && m < 13) ? m : 0;
        day = checkday(d);
    }
    int checkday(int d) {
        int days[months + 1] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (d > 0 && d <= days[month]) {
            return d;
        } else {
            return 0;
        }
    }
    void showdate() {
        string name[months + 1] = {"ned", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        cout << day << "/" << name[month] << "/" << year << endl;
    }
};

class Employee {
    string name;
    int id;
    Date joiningdate;
    Date birthdate;
    string dept;
public:
    Employee(string n, int i, Date j, Date b, string d) : joiningdate(j), birthdate(b) {
        name = n;
        id = i;
        dept = d;
    }
    void showdata() {
        cout << "----------Employee details--------" << endl;
        cout << "Employee name : " << name << endl;
        cout << "Employee id : " << id << endl;
        cout << "Employee birthdate : ";
        birthdate.showdate();
        cout << "Employee dept : " << dept << endl;
        cout << "Employee joining date : ";
        joiningdate.showdate();
    }
};

int main() {
    Date join(12, 2022, 3);
    Date birth(2, 2001, 6);
    Employee e1("Ali", 10, join, birth, "IT");
    e1.showdata();
    return 0;
}
