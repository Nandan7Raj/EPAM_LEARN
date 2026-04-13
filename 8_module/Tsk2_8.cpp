#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printTodoList(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        cout << "The list is currently empty." << endl;
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
    cout << endl;
}

string toUpperString(string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::toupper(c);
    });
    return s;
}

string toLowerString(string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return s;
}

class TodoList {
private:
    std::vector<std::string> tasks;

public:
    void initializeTodoList() {
        tasks = {
            "SendingStatusUpdateMail",
            "PrepareForMeeting",
            "CompletingTrainings",
            "UrgentCriticalBugFix",
            "KnowledgeTransferNotes"
        };
        cout << "List initialized." << endl;
    }

    void displayInitialList() const {
        printTodoList(this->tasks);
    }

    void addNewTask() {
        string task;
        cout << "Enter new task: ";
        getline(cin >> ws, task);
        tasks.push_back(std::move(task));
        printTodoList(this->tasks);
    }

    void insertHighPriorityTask() {
        unsigned int pos;
        string task;

        cout << "Enter position to insert at (1-" << tasks.size() + 1 << "): ";
        cin >> pos;

        if (cin.fail() || pos < 1 || pos > tasks.size() + 1) {
            clearInputBuffer();
            cout << "Invalid position. Adding to the end of the list instead." << endl;
            cout << "Enter high-priority task: ";
            getline(cin >> ws, task);
            tasks.push_back(std::move(task));
        } else {
            cout << "Enter high-priority task: ";
            getline(cin >> ws, task);
            tasks.insert(tasks.begin() + (pos - 1), std::move(task));
        }
        printTodoList(this->tasks);
    }

    void viewFirstAndLastTasks() const {
        if (tasks.empty()) {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "First Task : " << this->tasks.front() << endl;
        cout << "Last Task  : " << this->tasks.back() << endl;
    }

    void removeLastTask() {
        if (!tasks.empty()) {
            tasks.pop_back();
            printTodoList(tasks);
        } else {
            cout << "List is already empty." << endl;
        }
    }

    void markTaskComplete() {
        if (tasks.empty()) {
            cout << "The list is already empty." << endl;
            return;
        }

        unsigned int pos;
        cout << "Enter index of task to mark complete (1-" << tasks.size() << "): ";
        cin >> pos;

        if (cin.fail() || pos < 1 || pos > tasks.size()) {
            clearInputBuffer();
            cout << "Invalid index! Please enter a valid task number." << endl;
            return;
        }

        tasks.erase(tasks.begin() + (pos - 1));
        printTodoList(tasks);
        clearInputBuffer();
    }

    void sortTasksAlphabetically() {
        if (tasks.empty()) {
            cout << "The list is empty. No tasks to sort." << endl;
            return;
        }
        std::sort(tasks.begin(), tasks.end());
        printTodoList(tasks);
    }

    void reverseTaskOrder() {
        std::cout << "\n--- Reverse Task Order ---\n";
        if (tasks.empty()) {
            std::cout << "The list is empty. No tasks to reverse.\n";
        } else {
            std::cout << "Reversing task order...\n";
            std::reverse(tasks.begin(), tasks.end());
            printTodoList(tasks);
        }
    }

    void searchAndCountTasks() {
        if (tasks.empty()) {
            cout << "The list is empty." << endl;
            return;
        }

        string keyword;
        cout << "Enter search keyword: ";
        getline(cin >> ws, keyword);

        string lowerKeyword = toLowerString(keyword);
        int count = 0;
        int firstIndex = -1;

        for (size_t i = 0; i < tasks.size(); ++i) {
            if (toLowerString(tasks[i]).find(lowerKeyword) != string::npos) {
                if (firstIndex == -1) firstIndex = i + 1;
                count++;
            }
        }

        if (count > 0) {
            cout << "First occurrence found at position: " << firstIndex << endl;
            cout << "Total occurrences: " << count << endl;
        } else {
            cout << "Task containing '" << keyword << "' not found." << endl;
        }
    }

    void transformToUppercase() {
        if (tasks.empty()) {
            cout << "The list is empty." << endl;
            return;
        }
        for (auto& task : tasks) {
            task = toUpperString(task);
        }
        printTodoList(tasks);
    }

    void checkKeywordContainingTasks() const {
        if (tasks.empty()) {
            cout << "The list is empty." << endl;
            return;
        }

        string userKeyword;
        cout << "Enter additional keyword to search (or press enter to skip): ";
        string input;
        getline(cin >> ws, userKeyword);
        string upperUserKeyword = toUpperString(userKeyword);

        bool found = false;
        cout << "\n--- Keyword Matches ---\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            string upperTask = toUpperString(tasks[i]);
            if (upperTask.find("URGENT") != string::npos ||
                upperTask.find("DEADLINE") != string::npos ||
                (!upperUserKeyword.empty() && upperTask.find(upperUserKeyword) != string::npos)) {

                cout << (i + 1) << ". " << tasks[i] << " - Contains keyword\n";
                found = true;
            }
        }

        if (!found) {
            cout << "No urgent, deadline, or matching tasks found." << endl;
        }
    }

    void findLexicographicallyFirstLast() const {
        if (tasks.empty()) {
            cout << "List is empty." << endl;
            return;
        }
        auto minIt = std::min_element(tasks.begin(), tasks.end());
        auto maxIt = std::max_element(tasks.begin(), tasks.end());

        cout << "Lexicographically First: " << *minIt << endl;
        cout << "Lexicographically Last : " << *maxIt << endl;
    }

    void finalCleanup() {
        if (tasks.empty()) {
            cout << "List is already empty." << endl;
        } else {
            tasks.clear();
            cout << "All tasks cleared." << endl;
        }
    }
};

void displayMenu() {
    cout << "\n========== TO-DO LIST MENU ==========\n";
    cout << "1. Initialize/Reset To-Do List\n";
    cout << "2. Display Current To-Do List\n";
    cout << "3. Add New Task\n";
    cout << "4. Insert High-Priority Task\n";
    cout << "5. View First and Last Tasks\n";
    cout << "6. Remove Last Task\n";
    cout << "7. Mark Task as Complete (by index)\n";
    cout << "8. Sort Tasks Alphabetically\n";
    cout << "9. Reverse Task Order\n";
    cout << "10. Search for a Task & Count Occurrences\n";
    cout << "11. Transform All Tasks to UPPERCASE\n";
    cout << "12. Check for Keyword-Containing Tasks\n";
    cout << "13. Find Lexicographically First and Last Tasks\n";
    cout << "14. Clear All Tasks (Final Cleanup)\n";
    cout << "0. Exit\n";
    cout << "======================================\n";
    cout << "Enter your choice: ";
}

int main() {
    TodoList myTodoList;
    myTodoList.initializeTodoList();

    int choice = -1;

    do {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                myTodoList.finalCleanup();
                myTodoList.initializeTodoList();
                break;
            case 2:
                myTodoList.displayInitialList();
                break;
            case 3:
                myTodoList.addNewTask();
                break;
            case 4:
                myTodoList.insertHighPriorityTask();
                break;
            case 5:
                myTodoList.viewFirstAndLastTasks();
                break;
            case 6:
                myTodoList.removeLastTask();
                break;
            case 7:
                myTodoList.markTaskComplete();
                break;
            case 8:
                myTodoList.sortTasksAlphabetically();
                break;
            case 9:
                myTodoList.reverseTaskOrder();
                break;
            case 10:
                myTodoList.searchAndCountTasks();
                break;
            case 11:
                myTodoList.transformToUppercase();
                break;
            case 12:
                myTodoList.checkKeywordContainingTasks();
                break;
            case 13:
                myTodoList.findLexicographicallyFirstLast();
                break;
            case 14:
                myTodoList.finalCleanup();
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}