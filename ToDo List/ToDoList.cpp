#include <bits/stdc++.h>
using namespace std;

class Task {
private:
    string description;
    bool status;
    int index; // Index of the task in the ToDo list

public:
    Task(string& des, bool sts) : description(des), status(sts) {}

    void display() {
        cout << "S.No: " << index << endl;
        cout << "Description: " << description << endl;
        cout << "Status: " << (status ? "Completed" : "Incomplete") << endl;
        cout << "---------------------------" << endl;
    }

    void updateDescription(const string& newDesc) {
        description = newDesc;
    }

    void updateStatus(bool st) {
        status = st;
    }

    // Getter for index
    int getIndex() const {
        return index;
    }

    // Setter for index
    void setIndex(int idx) {
        index = idx;
    }
};


class ToDo {
public:
    string description;
    vector<Task> newLoad;
    int nextIndex; // Index counter for new tasks

    ToDo() : nextIndex(1) {} // Initialize nextIndex to 1

    void createTask() {
        cout << "Enter your task: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        getline(cin, description);

        Task newTask(description, false);
        newTask.setIndex(nextIndex); // Set index for the new task
        newLoad.push_back(newTask);
        nextIndex++; // Increment nextIndex for the next task

        newTask.display();
    }

    void updateToDoList() {
        int idx;
        int choice;

        cout << "Enter S.No of the task you want to update: ";
        cin >> idx;

        if (idx >= 1 && idx <= newLoad.size()) {
            cout << "1. Update Description" << endl;
            cout << "2. Update Status" << endl;
            cout << "3. Update Both" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter updated description for task " << idx << ": ";
                    string newDesc;
                    getline(cin, newDesc);

                    newLoad[idx - 1].updateDescription(newDesc);
                    cout << "Task " << idx << " description updated successfully." << endl;
                    break;
                }
                case 2: {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    string stat;
                    cout << "Enter updated status for task " << idx << " (Completed/Incomplete): ";
                    getline(cin, stat);

                    // Convert string input to boolean
                    if (stat == "Completed") {
                        newLoad[idx - 1].updateStatus(true);
                        cout << "Task " << idx << " status updated to Completed." << endl;
                    } else if (stat == "Incomplete") {
                        newLoad[idx - 1].updateStatus(false);
                        cout << "Task " << idx << " status updated to Incomplete." << endl;
                    } else {
                        cout << "Invalid input. Please enter 'Completed' or 'Incomplete'." << endl;
                    }
                    break;
                }
                case 3: {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter updated description for task " << idx << ": ";
                    string newDesc;
                    getline(cin, newDesc);

                    newLoad[idx - 1].updateDescription(newDesc);
                    cout << "Task " << idx << " description updated successfully." << endl;

                    cout << "Enter updated status for task " << idx << " (Completed/Incomplete): ";
                    string stat;
                    getline(cin, stat);

                    // Convert string input to boolean
                    if (stat == "Completed") {
                        newLoad[idx - 1].updateStatus(true);
                        cout << "Task " << idx << " status updated to Completed." << endl;
                    } else if (stat == "Incomplete") {
                        newLoad[idx - 1].updateStatus(false);
                        cout << "Task " << idx << " status updated to Incomplete." << endl;
                    } else {
                        cout << "Invalid input. Please enter 'Completed' or 'Incomplete'." << endl;
                    }
                    break;
                }
                default:
                    cout << "Invalid choice." << endl;
                    break;
            }
        } else {
            cout << "Invalid task number. Please enter a valid S.No." << endl;
        }
    }

    void displayAllTasks() {
        cout << "\n\t________________________________________________\n";
        cout << "\t|               TODO LIST                        |";
        cout << "\n\t________________________________________________\n";

        for (auto& task : newLoad) {
            task.display();
        }
    }
};


int main(){

    ToDo todo;
    

     int choice = -1; 

    while (choice != 0) {
        cout <<
            "\n\t################## MENU #################\n"
            "\t# 1. Select 1 for Create new Task         #\n"
            "\t# 2. Select 2 for Update your Task        #\n"
            "\t# 3. Select 3 for Display all Task        #\n"
            "\t# 4. Select 0 to Close the ToDo List      #\n"
            "\t###########################################\n"

            "\nEnter your choice: ";
        
        cin >> choice; // User Input
        
        switch (choice) {
            case 1:
                cout << "Create new Task" << endl;
                todo.createTask();
                break;
            case 2:
                cout << "Update your task" << endl;
                todo.updateToDoList();
                break;
            case 3:
                todo.displayAllTasks();
                break;
            case 0:
                cout << "Close the ToDo List. Keep Wokr HARD!!" << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    }


    return 0;

}