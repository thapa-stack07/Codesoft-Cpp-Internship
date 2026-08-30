#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "To-Do List" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    Task newTask;
                    cout << "Enter task description: ";
                    cin.ignore(); // Clear the newline character from the input buffer
                    getline(cin, newTask.description);
                    newTask.completed = false;
                    tasks.push_back(newTask);
                    cout << "Task added." << endl;
                }
                break;
            case 2:
                cout << "Tasks:" << endl;
                for (size_t i = 0; i < tasks.size(); ++i) {
                    cout << (i + 1) << ". " << tasks[i].description;
                    if (tasks[i].completed) {
                        cout << " (Completed)";
                    }
                    cout << endl;
                }
                break;
            case 3:
                {
                    cout << "Enter the task number to mark as completed: ";
                    int taskNumber;
                    cin >> taskNumber;
                    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
                        tasks[taskNumber - 1].completed = true;
                        cout << "Task marked as completed." << endl;
                    } else {
                        cout << "Invalid task number." << endl;
                    }
                }
                break;
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}