//
// Created by NandanRaj on 02-04-2026.
//
#include<iostream>
#include<list>
#include<string>
void display(const std::list<std::string>& lst) {
    if (lst.empty()) {
        std::cout<<"List is empty\n";
        return;
    }
    for (auto&w:lst) {
        std::cout<<w<<" ";
    }
    std::cout<<"\n";
}
int main() {
    std::list<std::string> Warehouse1={"A100", "A200", "A300"};
    std::list<std::string> Warehouse2 = {"A150", "A250", "A350"};

    std::cout<<"Displaying Warehouse1\n";
    display(Warehouse1);
    std::cout<<"Displaying Warehouse2\n";
    display(Warehouse2);

    Warehouse1.sort();
    Warehouse2.sort();

    Warehouse1.merge(Warehouse2);

    std::cout<<"Display the merged inventory list\n";
    display(Warehouse1);

    if (Warehouse2.empty()) {
        std::cout<<"Merge Successful\n";
    }
    else {
        std::cout<<"Merge Unsuccessful\n";
    }

}