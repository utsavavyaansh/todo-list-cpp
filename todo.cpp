#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

const string FILE_NAME = "tasks.txt";

vector<string> loadTasks() {
    vector<string> tasks;
    ifstream file(FILE_NAME);
    string line;
    while (getline(file, line)) {
        tasks.push_back(line);
    }
    file.close();
    return tasks;
}

void saveTasks(const vector<string>& tasks) {
    ofstream file(FILE_NAME);
    for (const auto& task : tasks) {
        file << task << endl;
    }
    file.close();
}

void showTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "\nYour To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
    cout << endl;
}

int main() {
    vector<string> tasks = loadTasks();
    int choice;

    while (true) {
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            showTasks(tasks);

        } else if (choice == 2) {
            cout << "Enter new task: ";
            string newTask;
            getline(cin, newTask);
            tasks.push_back(newTask);
            saveTasks(tasks);
            cout << "Task added!\n\n";

        } else if (choice == 3) {
            showTasks(tasks);
            cout << "Enter task number to mark as done: ";
            int taskNo;
            cin >> taskNo;
            if (taskNo > 0 && taskNo <= (int)tasks.size()) {
                tasks[taskNo - 1] += " (Done)";
                saveTasks(tasks);
                cout << "Task marked as done!\n\n";
            }

        } else if (choice == 4) {
            showTasks(tasks);
            cout << "Enter task number to delete: ";
            int taskNo;
            cin >> taskNo;
            if (taskNo > 0 && taskNo <= (int)tasks.size()) {
                tasks.erase(tasks.begin() + taskNo - 1);
                saveTasks(tasks);
                cout << "Task deleted!\n\n";
            }

        } else if (choice == 5) {
            cout << "Goodbye!\n";
            break;

        } else {
            cout << "Invalid choice, try again.\n\n";
        }
    }

    return 0;
}
