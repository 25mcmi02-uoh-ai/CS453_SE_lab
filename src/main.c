#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "utils.h"
#include "fileio.h"
#include "report.h"

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <max-number-of-students>\n", argv[0]);
        return 1;
    }
    if(!isValidStudentCount(argv[1])) {
        printf("Invalid number of students. Please enter a positive integer. Range: 1 to %d\n", MAX_STUDENTS);
        return 1;
    }

    int num_students = atoi(argv[1]);
    printf("Number of students: %d\n", num_students);
    Student students[num_students];
    // createStudentArray(num_students, students);
    num_students = 0;
    int choice = -1;
    while(1) {
        displayUserMenu();
        choice = readUserChoice();
        switch(choice) {
            case 1:
                addStudent(students, &num_students);
                break;
            case 2:
                displayReport(students, num_students);
                break;
            case 3:
                writeResultsToFile("students.txt", students, num_students);
                break;
            case 4:
                writeResultsToFile("students.txt", students, num_students);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;

}