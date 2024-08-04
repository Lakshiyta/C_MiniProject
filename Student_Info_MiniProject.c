#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure to store student information
struct Student {
    int rollNumber;
    char name[50];
    char branch[50];
    int semester;
    char email[50];
    char phoneNumber[15];
};

// Function prototypes
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count, int rollNumber);

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice;
    int rollNumber;

    while (1) {
        printf("\nStudent Information System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                printf("Enter Roll Number to search: ");
                scanf("%d", &rollNumber);
                searchStudent(students, count, rollNumber);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addStudent(struct Student students[], int *count) {
    printf("Enter Roll Number: ");
    scanf("%d", &students[*count].rollNumber);
    printf("Enter Name: ");
    scanf("%s", students[*count].name);
    printf("Enter Branch: ");
    scanf("%s", students[*count].branch);
    printf("Enter Semester: ");
    scanf("%d", &students[*count].semester);
    printf("Enter Email ID: ");
    scanf("%s", students[*count].email);
    printf("Enter Phone Number: ");
    scanf("%s", students[*count].phoneNumber);
    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(struct Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nRoll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Branch: %s\n", students[i].branch);
        printf("Semester: %d\n", students[i].semester);
        printf("Email ID: %s\n", students[i].email);
        printf("Phone Number: %s\n", students[i].phoneNumber);
    }
}

void searchStudent(struct Student students[], int count, int rollNumber) {
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("\nRoll Number: %d\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Branch: %s\n", students[i].branch);
            printf("Semester: %d\n", students[i].semester);
            printf("Email ID: %s\n", students[i].email);
            printf("Phone Number: %s\n", students[i].phoneNumber);
            return;
        }
    }
    printf("Student with Roll Number %d not found!\n", rollNumber);
}
