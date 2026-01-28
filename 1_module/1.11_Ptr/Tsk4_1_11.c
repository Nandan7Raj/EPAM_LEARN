//
// Created by NandanRaj on 25-01-2026.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a structure to hold employee details
struct Employee{
    int id;
    char name[50];
    float salary;
};

void printEmployee(struct Employee *emp)
{
    printf("Employee ID: %d\n", emp->id);
    printf("Employee Name: %s\n", emp->name);
    printf("Employee Salary: %.2f\n", emp->salary);
}

int main()
{

    struct Employee *empPtr = malloc(sizeof *empPtr);// Dynamically allocate memory for an Employee structure
    // Check if memory allocation was successful
    if(empPtr== NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    // Input employee details from the user
    printf("Enter Employee ID: ");
    scanf("%d",&empPtr->id);
    printf("Enter Employee Name: ");
    scanf(" %99[^\n]",empPtr->name);
    printf("Enter Employee salary: ");
    scanf("%f",&empPtr->salary);
    // Display the entered employee details
    printf("Employee details before salary update.\n");
    printEmployee(empPtr);
    float newSalary;
    printf("Enter new salary : ");
    scanf("%f",&newSalary);
    empPtr->salary=newSalary;
    printf("Employee details after salary update \n ");
    printEmployee(empPtr);
    free(empPtr);
    empPtr=0;

}