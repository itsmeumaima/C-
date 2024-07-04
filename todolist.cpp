#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Task {
    char tasks[50];
public:
    Task() {
        strcpy(tasks, "");
    }
    void setTask(const char* t) {
        strcpy(tasks, t);
    }
    const char* getTask() const {
        return tasks;
    }
    void showTask() const {
        cout << tasks << endl;
    }
};

class TodoList {
    vector<Task> tasks;
public:
    void addTask(const char* t) {
        for (const auto& task : tasks) {
            if (strcmp(task.getTask(), t) == 0) {
                cout << "Task already present" << endl;
                return;
            }
        }
        Task newTask;
        newTask.setTask(t);
        tasks.push_back(newTask);
        cout << "Task added" << endl;
    }

    void view() const {
        cout << "-----Tasks-----" << endl;
        for (const auto& task : tasks) {
            task.showTask();
            cout << "--------------------------" << endl;
        }
    }

    void markDone(const char* t) {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (strcmp(it->getTask(), t) == 0) {
                tasks.erase(it);
                cout << "Task marked as done successfully." << endl;
                return;
            }
        }
        cout << "Task not found." << endl;
    }
};

int main() {
    TodoList l;
    int choice;
    char t2[50];

    while (true) {
        cout << "-----To do list-------" << endl;
        cout << "1. Add new task" << endl;
        cout << "2. Mark as done" << endl;
        cout << "3. View all tasks" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after the choice input

        switch (choice) {
            case 1:
                cout << "Enter task you want to add: ";
                cin.getline(t2, 50);
                l.addTask(t2);
                break;
            case 2:
                cout << "Enter task you want to mark as done: ";
                cin.getline(t2, 50);
                l.markDone(t2);
                break;
            case 3:
                l.view();
                break;
            default:
                cout << "Please enter the right value" << endl;
                break;
        }
    }

    return 0;
}
