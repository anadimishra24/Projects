## ToDo List

The "Todo List" project is a console-based application implemented in C++. It allows users to manage their tasks by providing functionalities to add tasks, mark tasks as completed, and view the current list of tasks. Let's break down the functionalities and the C++ concepts used in this project:

# Functionalities:

# Add Task:
Users can add tasks to their todo list. Each task typically consists of a description (a string).

# Mark Task as Completed:
Users can mark tasks as completed. This typically involves changing the status of a task from "incomplete" to "completed".

# View Tasks:
Users can view their current list of tasks. This displays all tasks, along with their completion status.
C++ 


## Concepts Used:

Classes and Objects:

The project could utilize classes to represent a Task and a TodoList. For example:
cpp
Copy code
class Task {
private:
    string description;
    bool completed;
public:
    Task(const string& desc) : description(desc), completed(false) {}
    // Methods to get/set task details
};

class TodoList {
private:
    vector<Task> tasks;
public:
    void addTask(const string& desc);
    void markTaskCompleted(int index);
    void displayTasks() const;
};
Task class represents an individual task with a description and completion status.
TodoList class manages a collection of tasks (vector<Task>). It provides methods to add tasks, mark tasks as completed, and display tasks.
Vectors (or Dynamic Arrays):

Vectors are used to store and manage a collection of tasks (vector<Task>). Vectors provide dynamic resizing and efficient access to elements.
Input/Output Handling:

Input/output operations are crucial for interacting with users via the console (cout for output, cin for input).
cpp
Copy code
cout << "Enter task description: ";
getline(cin, description);
Control Structures (Loops and Conditionals):

Loops (e.g., for or while loops) and conditionals (e.g., if statements) are used for task management and user interaction.
cpp
Copy code
void TodoList::displayTasks() const {
    for (int i = 0; i < tasks.size(); ++i) {
        cout << (i + 1) << ". ";
        cout << (tasks[i].isCompleted() ? "[X] " : "[ ] ");
        cout << tasks[i].getDescription() << endl;
    }
}
Error Handling:

Basic error handling can be implemented using conditionals (if statements) or exceptions (try-catch blocks) to manage unexpected user inputs or other errors.
String Manipulation:

String operations such as concatenation (+ operator) and input/output operations (getline) are used for task descriptions and user input handling.
Summary:
The "Simple Todo List" project in C++ leverages object-oriented programming concepts (classes, objects), dynamic data structures (vectors), input/output operations, control structures, error handling, and string manipulation. It provides a practical exercise in managing data and interactions within a console-based application, suitable for beginners to practice foundational concepts in C++ programming.