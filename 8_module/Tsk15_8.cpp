//
// Created by NandanRaj on 13-04-2026.
//
#include<iostream>
#include<string>
#include<queue>
#include<vector>
struct Patient {
    std::string name;
    int severity;
    int arrivalTime;
    Patient(std::string n, int s, int t) : name(std::move(n)), severity(s), arrivalTime(t) {}
};
// custom comparator
struct ComparePatient {
    bool operator()(const Patient& p1, const Patient&p2) const{
        if (p1.severity==p2.severity) {
            return p1.arrivalTime>p2.arrivalTime;
        }
        return p1.severity>p2.severity;
    }
};

int main(int argc, char *argv[]) {
    std::priority_queue<Patient, std::vector<Patient>,ComparePatient> erQueue;
    erQueue.emplace("Alice Smith", 3, 10);
    erQueue.emplace("Bob", 1, 5);
    erQueue.emplace("Charlie", 3, 8);
    erQueue.emplace("David",2,12);
    erQueue.emplace("Eve",1,7);
    erQueue.emplace("Frank",5,2);

    while (!erQueue.empty()) {
        auto p=erQueue.top();
        erQueue.pop();
        std::cout<<"Processing patient [ "<<p.name<<" ]: Severity [ "
        <<p.severity<<" ], Arrived at [ "<<p.arrivalTime<<" ]\n";
    }
}

