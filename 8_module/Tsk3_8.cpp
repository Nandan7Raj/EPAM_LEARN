//
// Created by NandanRaj on 02-04-2026.
//

#include<iostream>
#include<list>
#include<string>
#include<algorithm>
int main() {
    std::list<int> grade;
    if (grade.empty())
        std::cout << "Is the list empty? Yes\n";

    // adding six integer
    grade.push_back(80);
    grade.push_back(90);
    grade.push_back(75);
    grade.push_back(98);
    grade.push_back(89);
    grade.push_back(85);


    for (const auto& g : grade) {
        std::cout << g << " ";
    }

    std::cout<<"\nCurrent size: "<<grade.size()<<std::endl;
    if (!grade.empty()) {
        std::cout<<"First grade in list: "<<grade.front()<<std::endl;
        std::cout<<"Last grade in list: "<<grade.back()<<std::endl;
    }

    auto it=grade.begin();
    if (grade.size() >= 2) {
        std::advance(it,2);
        std::cout<<"Grade at third position is :"<<*it<<std::endl;
        // modifying  third grade
        *it=99;
        std::cout<<"Grade at third index after modification: "<<*it<<std::endl;
    }

    //Attempt to access an out-of-bounds position
    auto test_it = it;
    std::advance(test_it, 10);
    if (test_it == grade.end()) {
        std::cout << "Note: std::advance moved iterator to end(). "
                  << "No exception thrown - this is expected behavior for std::list.\n"
                  << "Dereferencing would cause Undefined Behavior.\n";
    }

    grade.push_front(34);
    it=grade.end();
    auto itr=std::prev(it);
    grade.insert(itr,26);

    for (const auto& g : grade) {
        std::cout << g << " ";
    }

    std::cout<<"\nUpdated size: "<<grade.size()<<std::endl;

    if (!grade.empty()) {
        grade.pop_back();
    }
    if (grade.size() >= 2) {
        it = grade.begin();
        std::advance(it, 1);
        grade.erase(it);
    }

    for (const auto& g : grade) {
        std::cout << g << " ";
    }

    std::cout<<"\nUpdated size: "<<grade.size()<<std::endl;

    grade.clear();
    std::cout<<"Size of list after clear: "<<grade.size()<<std::endl;
    std::cout<<"Is the list empty? "<<(grade.empty()?"Yes":"No")<<std::endl;




}

