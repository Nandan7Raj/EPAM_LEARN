//
// Created by NandanRaj on 26-01-2026.
//
#include<stdio.h>
struct Student {
    int rollNo;
    char name[50];
    float marks;
};
// func to write in file
void addStudentRecord() {
    struct Student student; // static memory allocation for student data
    // taking input from user
    printf("Enter student roll no(1-100). : ");
    scanf("%d",&student.rollNo);
    while (student.rollNo>100 || student.rollNo<=0) { // for input validation
        printf("Enter a valid number. Please try again\n");
        scanf("%d",&student.rollNo);
    }
    printf("Enter student name : ");
    scanf(" %[^\n]",student.name); // %[^\n] to get name with spaces
    printf("Enter student marks : ");
    scanf("%f",&student.marks);
    FILE *fw = fopen("students.txt","ab"); //"ab" opens a file in append + binary mode, writing data only at the end.
    if (fw==NULL) { // securing program from file not found error
        printf("Error opening file");
        return;
    }
    fwrite(&student,sizeof(struct Student),1,fw); // writing in the file
    fclose(fw);// closing the file
    printf("Student record added successfully and file is closed\n");

}
// func to read from file
void displayAllRecords() {
    struct Student student;
    FILE *fr = fopen("students.txt","rb"); //open the file to read in binary mode
    if (fr==NULL) {// error handling
        printf("Error opening file");
        return;
    }
    int i=1;
    // while fread() return value
    while (fread(&student,sizeof(struct Student),1,fr)==1) {
        printf("\nData of student %d:\n",i++);
        printf("RollNo: %d\n",student.rollNo);
        printf("Name: %s\n",student.name);
        printf("Marks: %.2f\n",student.marks);
    }

    fclose(fr);// closing of file
    if (i==1) // means fread() return not a single value
        printf("Your file is empty\n");
    else
    printf("All data readed successfully and file is closed\n");

}
int main() {
    int choice;
    // my menu to give choice to user
    while (choice!=3) {

        printf("Choose one of the following options:\n");
        printf("1. Add Student\n");
        printf("2. Display All Records\n");
        printf("3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:// user want to write
                addStudentRecord();
                break;
            case 2: // user want to read
                displayAllRecords();
                break;
            case 3: // user want to exit
                printf("Exiting...\n");
                break;
            default:// user typed invalid input
                printf("There is no such option\n");
        }

    }
    printf("Thank you\n");
}