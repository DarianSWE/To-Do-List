#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task class to represent each task in the to-do list
class Task {
public:
	string name;
	bool isComplete;

	// Constructor to initialize a task with a name and set its completion status to false
	Task(string name) {
		this->name = name;
		this->isComplete = false;
	}

	// Method to mark the task as completed
	void markCompleted() {
		this->isComplete = true;
	}

	// Method to return the task as a formatted string, indicating its completion status
	string toString() {
		return name + (isComplete ? " [Completed]" : " ");
	}

};

// Display menu and options
 void displayMenu() {
	 cout << endl;
	cout << "To-Do List" << endl;
	cout << "1. Add Task" << endl;
	cout << "2. Delete Task" << endl;
	cout << "3. Mark Task Completed" << endl;
	cout << "4. Display List " << endl;
	cout << "5. Exit" << endl;
}

 // Add task to to-do list
 void addTask(vector<Task>& tasks) {
	 cout << "Enter Task Name: ";
	 cin.ignore(); 
	 string name;
	 getline(cin, name);
	 tasks.emplace_back(name);
	 cout << "Task added successfully.\n";
 }

 // Remove task from todo list
void removeTask(vector<Task>& tasks) {
	cout << "Enter a task number to remove: " << endl;
	int index;
	cin >> index;
	if (index > 0 && index <= tasks.size()) {
		tasks.erase(tasks.begin() + index - 1);
	}
	else {
		cout << "Invalid task number." << endl;
	}
}

// Mark task as complete
	void  markTaskComplete(vector<Task>& tasks) {
		cout << "Enter a task number to mark as complete" << endl;
		int index;
		cin >> index;
		if (index > 0 && index <= tasks.size()) {
			tasks[index - 1].markCompleted();
			cout << "Task marked as complete." << endl;
		}
		else {
			cout << "Invalid task number." << endl;
		}
	}
// Display list of tasks
	void displayTasks(vector<Task>& tasks) {
		cout << "\nTasks:" << endl;
		if (tasks.empty()) {
			cout << "No tasks available." << endl;
			return;
		}
		for (size_t i = 0; i < tasks.size(); ++i) {
			cout << (i + 1) << ". " << tasks[i].toString() << endl;
		}
	}

	// Main function 
	int main() {
		vector<Task> tasks;
		int choice;

		do {
			displayMenu();
			cout << endl;
			cout << "Enter your choice: " << endl;
			cin >> choice;

			// Switch case for menu options
			switch (choice) {
			case 1:
				addTask(tasks);
				break;
			case 2:
				removeTask(tasks);
				break;
			case 3:
				markTaskComplete(tasks);
				break;
			case 4:
				displayTasks(tasks);
				break;
			case 5:
				cout << "Exiting..." << endl;
				break;
			default:
				cout << "Not a valid choice." << endl;

			}

		} while (choice != 5);
		
		return 0;

}