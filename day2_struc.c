#include <stdio.h>
#include <string.h>

// Define a structure for student information
struct Student {
    int id;
    char name[50];
    float grade;
};

// Function to input student details
void inputStudentDetails(struct Student *s) {
    printf("Enter Student ID: ");
    scanf("%d", &s->id);
    printf("Enter Student Name: ");
    scanf("%s", s->name);
    printf("Enter Student Grade: ");
    scanf("%f", &s->grade);
}

// Function to display student details
void displayStudentDetails(struct Student s) {
    printf("\nStudent ID: %d\n", s.id);
    printf("Student Name: %s\n", s.name);
    printf("Student Grade: %.2f\n", s.grade);
}

int main() {
    struct Student student;

    // Input student details
    inputStudentDetails(&student);

    // Display student details
    displayStudentDetails(student);

    return 0;
}

/*
PS>.\day2_struc.exe
Enter Student ID: 1
Enter Student Name: Luis
Enter Student Grade: 100  

Student ID: 1
Student Name: Luis
Student Grade: 100.00
*/