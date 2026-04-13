//
// Created by NandanRaj on 09-04-2026.
//
#include<iostream>
#include <set>

void populateAndDemonstrateUniqueness(std::set<int>&studentID) {
    std::cout<<"Set Size before insertion: "<<studentID.size()<<std::endl;
    studentID.insert({101, 105, 103, 102});
    std::cout<<"Set Size after insertion: "<<studentID.size()<<std::endl;
    std::cout<<"Trying to insert 105 again\n";
    studentID.insert(105);
    std::cout<<"Set size after duplicate id insertion attempt: "<<studentID.size()
    <<", size is same as before so not duplicate insertion\n";
}

void printSetContents(std::set<int>&studentID, const std::string& title) {
    std::cout<<title<<std::endl;
    for (const auto &id:studentID) {
        std::cout<<id<<" ";
    }
    std::cout<<"\n";
}
void checkStudentExistence(std::set<int>&studentID,int id) {
    if (studentID.find(id)!=studentID.end()) {
        std::cout<<"Yes! this student ID exists\n";
    }
    else {
        std::cout<<"No! this student ID do not exist\n";
    }
}

void removeElements(std::set<int>& studentID)
{
    // Remove existing student
    std::cout << "Attempting to remove student ID 102\n";

    size_t removed = studentID.erase(102);

    if(removed == 1)
        std::cout << "Student ID 102 removed successfully.\n";
    else
        std::cout << "Student ID 102 not found.\n";

    std::cout << "Set size after removal: " << studentID.size() << std::endl;


    // Remove non-existing student
    std::cout << "\nAttempting to remove student ID 108\n";

    removed = studentID.erase(108);

    std::cout << "Number of elements removed: " << removed << std::endl;

    if(removed == 0)
        std::cout << "Student ID 108 does not exist in the set.\n";

    std::cout << "Set size after removal attempt: " << studentID.size() << std::endl;
}
int main(int argc, char *argv[]) {
    std::cout << "\n--- Step 1: Setup and Initialization: ---\n";
    std::set<int> studentID;
    std::cout<<"SET has been declared\n";

    std::cout << "\n--- Step 2: Populate with initial values and Uniqueness Demonstration ---\n";
    populateAndDemonstrateUniqueness(studentID);

    std::cout << "\n--- Step 3: Displaying the Current Roster ---\n";

    printSetContents(studentID, "Student IDs in the set (initial roster):");

    std::cout << "\n--- Step 4: Checking for Student Existence ---\n";
    checkStudentExistence(studentID, 103); // Check for an existing ID
    checkStudentExistence(studentID, 999); // Check for a non-existent ID std::cout << "\n";

    std::cout << "\n--- Step 5: Element Removal ---\n";
    removeElements(studentID);

    std::cout<<"\n--- Final Roster Review ---\n";
    printSetContents(studentID, "Final Student IDs in the set:");




}
