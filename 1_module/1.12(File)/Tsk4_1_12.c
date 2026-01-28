//
// Created by NandanRaj on 26-01-2026.
//

#include <stdio.h>

// Structure to store student data
struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    struct Student student;

    // Open file in read + write binary mode
    FILE *fp = fopen("students.txt", "r+b");
    if (fp == NULL) {
        printf("File could not be opened");
        return 1;
    }

    int roll_no = 0;
    float new_marks;

    // Take valid roll number input
    while (roll_no <= 0 || roll_no > 100) {
        printf("Enter roll no (1-100) of student to update marks: ");
        scanf("%d", &roll_no);
    }

    int found = 0;    // Flag to check if record is found
    int isEmpty = 0;  // Flag to check if file has any records

    // Read each student record from file
    while (fread(&student, sizeof(struct Student), 1, fp) == 1) {
        isEmpty = 1;

        // Check if roll number matches
        if (student.rollNo == roll_no) {
            found = 1;

            // Move file pointer back to start of current record
            fseek(fp, -sizeof(struct Student), SEEK_CUR);

            // Store position before write
            long bfr = ftell(fp);

            // Take valid new marks input
            printf("Enter new marks (0-100): ");
            scanf("%f", &new_marks);
            while (new_marks < 0 || new_marks > 100) {
                printf("Enter valid new marks (0-100): ");
                scanf("%f", &new_marks);
            }

            // Update marks
            student.marks = new_marks;

            // Write updated record back to file
            fwrite(&student, sizeof(struct Student), 1, fp);

            // Store position after write
            long aft = ftell(fp);

            // Check if write was successful
            if (aft - bfr != sizeof(struct Student)) {
                printf("Write operation unsuccessful.\n");
            } else {
                printf("Record updated.\n");
            }
            break;
        }
    }

    // If file has no records
    if (!isEmpty) {
        printf("Your file is empty\n");
    }
    // If record not found
    else if (!found) {
        printf("Record not found.\n");
    }

    // Close file
    fclose(fp);
    return 0;
}
