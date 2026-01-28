//
// Created by NandanRaj on 26-01-2026.
//
#include<stdio.h>
#include<string.h>
// Structure defination
struct Employee {
    int empID;
    char name[50];
    float basicSalary;
};
// fun to add or write employee data in employee.dat file
void addEmployee() {
    struct Employee emp;
    printf("Enter employee ID : ");
    scanf("%d",&emp.empID);
    printf("Enter employee name : ");
    scanf(" %[^\n]",emp.name);
    printf("Enter employee Salary : ");
    scanf("%f",&emp.basicSalary);
    FILE *fw = fopen("employee.dat","ab");
    if(fw==NULL) {// handel error
        printf("Error opening file");
        return;
    }
    // writing data in file
    fwrite(&emp,sizeof(struct Employee),1,fw);
    fclose(fw);// closing file
    printf("Employee added successfully\n");
}
void generate_Salary_Slip(struct Employee*);   // implicit declaration

void processEmployeeRecords() {
    struct Employee emp;
    //opening file to read as binary
    FILE *fr = fopen("employee.dat","rb");
    if(fr==NULL) {// handling error of when file do not open
        printf("Error opening file");
        return;
    }
    // while fread() return some value
    while (fread(&emp,sizeof(struct Employee),1,fr)==1) {
     generate_Salary_Slip(&emp);
    }
    fclose(fr);// closing file
}
// func to generate salary slip
void generate_Salary_Slip(struct Employee *emp) {
    float basicSalary = emp->basicSalary;
    float DA = basicSalary * 0.2f;
    float HRA = basicSalary * 0.1f;
    float netSalary = basicSalary + DA + HRA;

    char fileName[50];
    // to name file accorf=ding to emp id
    sprintf(fileName, "emp%d_slip.txt", emp->empID);
    // openeing or creating required file
    FILE *fw = fopen(fileName, "w");
    if (fw == NULL) {// handling file opening error
        printf("Error opening file\n");
        return;
    }
    // writing in file using fwrite (line by line)
    fprintf(fw, "Salary Slip for Employee %s (ID: %d)\n", emp->name, emp->empID);
    fprintf(fw, "-----------------------------------------\n");
    fprintf(fw, "Basic Salary: %.2f\n", basicSalary);
    fprintf(fw, "Dearness Allowance (DA): %.2f\n", DA);
    fprintf(fw, "House Rent Allowance (HRA): %.2f\n", HRA);
    fprintf(fw, "Net Salary: %.2f\n", netSalary);
    fprintf(fw, "-----------------------------------------\n");

    fclose(fw);// file closed

    printf("Salary slip prepared for employee with id: %d\n", emp->empID);
}

int main() {
    int No_of_Employees;
    printf("Enter number of employees : ");
    scanf("%d",&No_of_Employees);
    // adding employee data
    for (int i=0;i<No_of_Employees;i++) {
        printf("Enter data of employee %d\n",i+1);
        addEmployee();
    }
    // it will process data of each and make salary slip for each
    processEmployeeRecords();
    printf("Thank You\n");




}
