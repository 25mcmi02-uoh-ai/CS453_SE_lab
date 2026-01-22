#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "fileio.h"
#include "computation.h"

void addStudent(Student students[], int *count) {

    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    Student new_student;

    inputStudentID(students, *count, new_student.id);
    inputStudentName(new_student.name);
    inputStudentMarks(new_student.marks);

    processStudent(&new_student);

    students[*count] = new_student;
    (*count)++;
}