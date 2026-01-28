//
// Created by NandanRaj on 27-01-2026.
//
#include<stdio.h>
// Program to delete a record from a binary file
// Here we are deleting employee record based on empID
struct Employee {
    int empID;
    char name[50];
    float basicSalary;
};
int main () {
    struct Employee emp;// to read from file
    // opening file in read binary mode
FILE *fr = fopen("employee.dat","rb");
    if (fr==NULL) {// file open error
        printf("Cannot open \"employee.dat\" file.\n");
        return 1;
    }
    // creating temp file to copy data
    FILE *fw = fopen("temp.dat","wb");
    if (fw==NULL) {// file open error
        printf("can't create temp file.\n");
        return 1;
    }
    // asking user to input emp id whose data he/she want to delete
    int empID=0;
    while (empID<=0 || empID>100) {
        printf("Enter empId(1-100) whose data you want to delete: ");
        scanf("%d",&empID);
    }

    // reading each record and searching required empId
    // And coping other empId to temp file
    int found=0,isEmpty=0;
    while (fread(&emp,sizeof(struct Employee),1,fr)==1) {
        isEmpty=1;// file is not empty
        if (emp.empID==empID) {
            found=1;// record found
            printf("Record of employee %s(Emp id. %d) found in the file\n",emp.name,emp.empID);
        }
        else
            fwrite(&emp,sizeof(struct Employee),1,fw);// copying record to temp file
    }
    if (isEmpty==0) {// file is empty
        printf("Your file is empty.There is nothing to search\n");
    }
    else if (found==0) {// record not found
        printf("There is no employee with Emp ID: %d\n",empID);
    }
    else {
        if (ftell(fr)-ftell(fw)==sizeof(struct Employee)) {// record deleted successfully
            printf("Data deleted successfully\n");
        }
        else{// some issue in deleting record
            printf("There is some issue and data is not delete\n");
        }
    }
    fclose(fw);// closing temp file
    fclose(fr);// closing employee.dat file
    // removing original file and renaming temp file to original file name
    // Step 1: Rename original file to backup
    if (rename("employee.dat", "employee.bak") != 0) {
        perror("Backup rename failed");
        return 1;
    }

    // Step 2: Rename temp file to original name
    if (rename("temp.dat", "employee.dat") != 0) {
        perror("Final rename failed");

        // Restore original file
        rename("employee.bak", "employee.dat");
        return 1;
    }

    // Step 3: Remove backup only after success
    remove("employee.bak");

    printf("File replaced safely.\n");
}