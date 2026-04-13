//
// Created by NandanRaj on 03-04-2026.
//
#include<iostream>
#include<string>
#include<list>
#include<algorithm>

struct Task {
    std::string name;
    int priority;
    int deadline;
public:
    Task(std::string name,int priority,int deadline):name(std::move(name)),priority(priority),deadline(deadline){};
    void print() const {
        std::cout<<"Name: "<<name
        <<" | Priority: "<<priority
        <<" | Deadline: "<<deadline<<std::endl;
    }
};

int main() {
    std::list<Task> tasks = {
        {"Sending the Mail", 2, 5},
        {"Fix Critical bug", 1, 1},
        {"Team meeting", 2, 1},
        {"Code review", 2, 3},
        {"Update docs", 3, 4}
    };
    for (auto &tsk:tasks) {
        tsk.print();
    }
    tasks.sort([](Task& a,Task&b) {
        if (a.priority==b.priority)
            return a.deadline<=b.deadline;
        return a.priority>b.priority;
    });
    std::cout<<" \n--------After sorting--------\n";
    for (auto &tsk:tasks) {
        tsk.print();
    }




}