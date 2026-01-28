//
// Created by NandanRaj on 25-01-2026.
//
#include<stdio.h>
#include<string.h>
// Define a structure to hold employee details
struct Employee{
    char name[50];
    int employee_id;
    float salary;
};
// Function to display employee details
void displayEmployee(struct Employee emp){
    printf("Employee Name: %s\n Employee ID: %d\n Salary: %.2f\n\n", emp.name, emp.employee_id, emp.salary);
}
int main()
{
    struct Employee emp1;// Declare a variable of type Employee
    strcpy(emp1.name, "Nandan");
    emp1.employee_id = 12345;
    emp1.salary = 55000.50;
    // Display employee details
    printf("Employee Name: %s\n Employee ID: %d\n Salary: %.2f\n\n", emp1.name, emp1.employee_id, emp1.salary);

    // Create an array of Employee structures
    struct Employee staff[4];
    // Initialize employee details
    strcpy(staff[0].name,"Abhishek J");
    staff[0].employee_id=1001;
    staff[0].salary=60000.00;
    strcpy(staff[1].name,"Abhishek K");
    staff[1].employee_id=1002;
    staff[1].salary=62000.00;
    strcpy(staff[2].name,"Arnav G");
    staff[2].employee_id=1003;
    staff[2].salary=58000.00;

    // Display details of all employees in the array
    for(int i=0;i<3;i++){
        printf("Details of Employee %d:\n", i+1);
        displayEmployee(staff[i]);// Call the function to display employee details
        printf("\n");
    }

    return 0;
}
