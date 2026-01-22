#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "validation.h"
#include "utils.h"
#include "fileio.h"
#include "report.h"

void addStudent(Student students[], int *count) {
    // check if we exceed max students
    if(*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }
    
    Student new_student;
    // Input ID
    while(1) {
        printf("Enter Student ID: ");
        scanf("%s", new_student.id);
        if(!isValidID(new_student.id)) {
            printf("Invalid ID format. Please try again.\n");
            continue;
        }
        if(isDuplicateID(students, *count, new_student.id)) {
            printf("Duplicate ID found. Please enter a unique ID.\n");
            continue;
        }
        break;
    }

    // Input Name
    while(1) {
        printf("Enter Student Name: ");
        scanf(" %[^\n]", new_student.name);
        if(!isValidName(new_student.name)) {
            printf("Invalid name format. Please try again.\n");
            continue;
        }
        break;
    }

    // Input Marks
    for(int i = 0; i < SUBJECTS; i++) {
        while(1) {
            printf("Enter marks for subject %d: ", i + 1);
            if(scanf("%d", &new_student.marks[i]) != 1 || new_student.marks[i] < 0 || new_student.marks[i] > 100) {
                printf("Invalid marks. Please enter a number between 0 and 100.\n");
                while(getchar() != '\n'); // clear input buffer
                continue;
            }
            break;
        }
    }

    // Calculate total, percentage, grade, and cgpa
    new_student.total = 0;
    for(int i = 0; i < SUBJECTS; i++) {
        new_student.total += new_student.marks[i];
    }
    new_student.percentage = (float)new_student.total / SUBJECTS;
    calculateGradeAndCGPA(&new_student);
    // Add new student to array
    students[*count] = new_student;
    (*count)++;
}