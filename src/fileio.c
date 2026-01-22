#include <stdio.h>

#include "student.h"
#include "validation.h"
#include "fileio.h"

static void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void inputStudentID(Student students[], int count, char *id) {
    while (1) {
        printf("Enter Student ID: ");
        scanf("%s", id);
        clearInputBuffer();

        if (!isValidID(id)) {
            printf("Invalid ID format. Please try again.\n");
            continue;
        }
        if (isDuplicateID(students, count, id)) {
            printf("Duplicate ID found. Please enter a unique ID.\n");
            continue;
        }
        break;
    }
}

void inputStudentName(char *name) {
    while (1) {
        printf("Enter Student Name: ");
        scanf("%[^\n]", name);

        if (!isValidName(name)) {
            printf("Invalid name format. Please try again.\n");
            continue;
        }
        break;
    }
}

void inputStudentMarks(int marks[]) {
    for (int i = 0; i < SUBJECTS; i++) {
        while (1) {
            printf("Enter marks for subject %d: ", i + 1);

            if (scanf("%d", &marks[i]) != 1 || marks[i] < 0 || marks[i] > 100) {
                printf("Invalid marks. Please enter a number between 0 and 100.\n");
                while (getchar() != '\n');
                continue;
            }
            break;
        }
    }
}


void writeResultsToFile(const char *filename, Student students[], int count) {
    FILE *file = fopen(filename, "w");
    if(file == NULL) {
        printf("Error opening file %s for writing.\n", filename);
        return;
    }

    fprintf(file, "ID,Name,course1,course2,course3,course4,course5,Total,Percentage,Grade,CGPA\n");
    for(int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%d,%d,%d,%d,%d,%d,%.2f,%s,%.2f\n", 
                students[i].id,
                students[i].name,
                students[i].marks[0],
                students[i].marks[1],
                students[i].marks[2],
                students[i].marks[3],
                students[i].marks[4],
                students[i].total,
                students[i].percentage,
                students[i].grade,
                students[i].cgpa);
    }

    fclose(file);
    printf("Results successfully written to %s\n", filename);
}