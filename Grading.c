#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to hold student information
typedef struct {
    char name[50];
    int marks;
    char grade;
} Student;

// Function to capture marks for each student
void captureMarks(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", students[i].name); // Read a line of input to capture names with spaces
        printf("Enter marks for %s: ", students[i].name);
        scanf("%d", &students[i].marks);
    }
}

// Function to process marks and assign grades
void processGrades(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        if (students[i].marks >= 70) {
            students[i].grade = 'A';
        } else if (students[i].marks >= 60) {
            students[i].grade = 'B';
        } else if (students[i].marks >= 50) {
            students[i].grade = 'C';
        } else if (students[i].marks >= 40) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
    }
}

// Function to generate individual semester results
void generateIndividualResults(Student students[], int count) {
    printf("\nIndividual Semester Results:\n");
    printf("Name\t\tMarks\tGrade\n");
    printf("---------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s\t%d\t%c\n", students[i].name, students[i].marks, students[i].grade);
    }
}

// Function to generate class semester results
void generateClassResults(Student students[], int count) {
    int totalMarks = 0;
    printf("\nClass Semester Results:\n");
    printf("Total Students: %d\n", count);

    for (int i = 0; i < count; i++) {
        totalMarks += students[i].marks;
    }
    float averageMarks = (float)totalMarks / count;
    printf("Class Average Marks: %.2f\n", averageMarks);
}

// Main function
int main() {
    int studentCount;
    Student students[MAX_STUDENTS];

    printf("Enter the number of students: ");
    scanf("%d", &studentCount);

    if (studentCount > MAX_STUDENTS) {
        printf("Error: Maximum number of students is %d.\n", MAX_STUDENTS);
        return 1;
    }

    captureMarks(students, studentCount);
    processGrades(students, studentCount);
    generateIndividualResults(students, studentCount);
    generateClassResults(students, studentCount);

    return 0;
}
