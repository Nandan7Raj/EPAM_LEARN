//
// Created by NandanRaj on 03-04-2026.
//

#include<iostream>
#include <limits>
#include<list>


int main() {
    std::list<int> lst{2,7,2,6,1,7,9,8,4,1};
    std::cout<<"Displaying elements of list \n";
    for (const auto &x:lst)
        std::cout<<x<<" ";

    int value;
    std::cout<<"\nEnter a value to be removed from the list: ";
    std::cin>>value;
    while (std::cin.fail()) {
        std::cout<<"You entered invalid value.Enter again\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin>>value;
    }

    auto it=std::ranges::find(lst,value);
    if (it!=lst.end()) {
        // Using remove() - removes all occurrences in one call
        lst.remove(value);
        std::cout<<value<<" is removed from list\n";
    }
    else {
        std::cout<<value<<" is not present in the list\n";
    }

    if (lst.empty()) {
        std::cout << "List is now empty. No further operations possible.\n";
        return 0;
    }
    std::cout<<"Displaying elements of list after remove operation\n";
    for (const auto &x:lst)
        std::cout<<x<<" ";

    std::cout<<"\nEnter a value to be erased from the list: ";
    std::cin>>value;
    while (std::cin.fail()) {
        std::cout<<"You entered invalid value.Enter again\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin>>value;
    }

    it=std::ranges::find(lst,value);
    if (it!=lst.end()) {
        for (auto itr=lst.begin();itr!=lst.end();) {
            if (*itr==value) {
                itr=lst.erase(itr);
            }
            else
                ++itr;
        }
        std::cout<<value<<" is removed from list using erase method of std::list\n";
    }
    else {
        std::cout<<value<<" is not in the list\n";
    }

    std::cout<<"Displaying elements of list after erase operation\n";
    for (const auto &x:lst)
        std::cout<<x<<" ";


}
