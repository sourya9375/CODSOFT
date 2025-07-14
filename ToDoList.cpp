#include <iostream>
#include <vector>
using namespace std;

// Structure to store task
struct Task {
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }
};

// Function to display menu
void displayMenu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "-------------------" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "\nTasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description;
        cout << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // To clear input buffer

        if (choice == 1) {
            string desc;
            cout << "Enter task description: ";
            getline(cin, desc);
            tasks.push_back(Task(desc));
            cout << "Task added successfully!" << endl;

        } else if (choice == 2) {
            viewTasks(tasks);

        } else if (choice == 3) {
            viewTasks(tasks);
            int index;
            cout << "Enter task number to mark as completed: ";
            cin >> index;

            if (index >= 1 && index <= tasks.size()) {
                tasks[index - 1].completed = true;
                cout << "Task marked as completed!" << endl;
            } else {
                cout << "Invalid task number." << endl;
            }

        } else if (choice == 4) {
            viewTasks(tasks);
            int index;
            cout << "Enter task number to remove: ";
            cin >> index;

            if (index >= 1 && index <= tasks.size()) {
                tasks.erase(tasks.begin() + index - 1);
                cout << "Task removed successfully!" << endl;
            } else {
                cout << "Invalid task number." << endl;
            }

        } else if (choice == 5) {
            cout << "Exiting To-Do List Manager. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }

    } while (choice != 5);

    return 0;
}