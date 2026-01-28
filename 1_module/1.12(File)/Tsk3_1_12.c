//
// Created by NandanRaj on 26-01-2026.
//
#include <stdio.h>
#include <time.h>
// Function to append attendance data to the file
void appendAttendence(int empID, char * timeStamp)
{
    // Open file in append mode
    FILE *fw = fopen("attendance.txt","a");
    // Check if file opened successfully
    if(fw==NULL) {
        printf("File could not be opened\n");
        return;
    }
    // Write employee ID and timestamp to the file
    fprintf(fw, "EmpID: %d, Time: %s\n", empID, timeStamp);
    fclose(fw);// Close the file
    printf("Data added for this employee\n");
}
// Function to display the attendance log from the file
void displayAttendenceLog() {
    //Open file in read mode
    FILE *fr = fopen("attendance.txt","r");
    if(fr==NULL) {// Check if file opened successfully
        printf("File could not be opened\n");
        return;
    }
    printf("Attendance Log:\n");
    char buffer[50];
    // Read and print each line from the file
    while (fgets(buffer,sizeof(buffer),fr)) {
        printf("%s",buffer);// Print the line
    }
    fclose(fr);// Close the file
    printf("Logs displayed Succesfully\n");
}

int main() {
    // Input number of employees
    int No_of_Employees;
    printf("Enter No. of employees: ");
    scanf("%d",&No_of_Employees);
    // Loop to input data for each employee
    for(int i=0;i<No_of_Employees;i++) {
        int empID = 0;
        char timeStamp[50];
        // Input employee ID and timestamp
        printf("Enter Data of Emp%d.\n",i+1);
        printf("Enter Employee ID : ");
        scanf("%d",&empID);
        getchar();// to consume newline character after integer input
        printf("Enter Timestamp (e.g., 2025-09-20 09:30 AM): ");
        fgets(timeStamp,50,stdin); // reading from standard input

        appendAttendence(empID,timeStamp);// Append data to the file
    }
    displayAttendenceLog();// Display the attendance log
    return 0;
}
