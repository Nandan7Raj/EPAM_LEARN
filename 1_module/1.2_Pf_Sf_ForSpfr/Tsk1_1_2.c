#include <stdio.h>

int main() {
    // Declare variables for three students
    char name1[20], name2[20], name3[20];
    int age1, age2, age3;
    float gpa1, gpa2, gpa3;

    // Input data for Student 1
    printf("Enter name for Student 1: ");
    scanf("%19s", name1);
    printf("Enter age for Student 1: ");
    scanf("%d", &age1);
    printf("Enter GPA for Student 1: ");
    scanf("%f", &gpa1);

    // Input data for Student 2
    printf("Enter name for Student 2: ");
    scanf("%19s", name2);
    printf("Enter age for Student 2: ");
    scanf("%d", &age2);
    printf("Enter GPA for Student 2: ");
    scanf("%f", &gpa2);

    // Input data for Student 3
    printf("Enter name for Student 3: ");
    scanf("%19s", name3);
    printf("Enter age for Student 3: ");
    scanf("%d", &age3);
    printf("Enter GPA for Student 3: ");
    scanf("%f", &gpa3);

    // Display table header
    printf("\n|---------------|-----|-------|\n");
    printf("|%15s|%5s|%7s|\n", "Name", "Age", "GPA");
    printf("|---------------|-----|-------|\n");

    // Display student data
    printf("|%15s|%5d|%7.2f|\n", name1, age1, gpa1);
    printf("|%15s|%5d|%7.2f|\n", name2, age2, gpa2);
    printf("|%15s|%5d|%7.2f|\n", name3, age3, gpa3);

    return 0;
}