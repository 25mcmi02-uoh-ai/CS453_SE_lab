#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "validation.h"
#include "utils.h"
#include "fileio.h"
#include "report.h"

void calculateGradeAndCGPA(Student *student) {
    // Calculate percentage
    student->percentage = (student->total / (float)(SUBJECTS * 100)) * 100.0f;

    // Assign grade based on percentage
    if(student->percentage >= 90) {
        snprintf(student->grade, sizeof(student->grade), "A+");
        student->cgpa = 4.0f;
    } else if(student->percentage >= 80) {
        snprintf(student->grade, sizeof(student->grade), "A");
        student->cgpa = 3.7f;
    } else if(student->percentage >= 70) {
        snprintf(student->grade, sizeof(student->grade), "B+");
        student->cgpa = 3.3f;
    } else if(student->percentage >= 60) {
        snprintf(student->grade, sizeof(student->grade), "B");
        student->cgpa = 3.0f;
    } else if(student->percentage >= 50) {
        snprintf(student->grade, sizeof(student->grade), "C");
        student->cgpa = 2.0f;
    } else {
        snprintf(student->grade, sizeof(student->grade), "F");
        student->cgpa = 0.0f;
    }
}
