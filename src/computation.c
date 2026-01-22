#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "computation.h"


void calculateTotal(Student *s) {
    int total = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        total += s->marks[i];
    }
    s->total = total;
}

void calculatePercentage(Student *s) {
    s->percentage = (float)s->total / SUBJECTS;
}

void assignGrade(Student *s) {
    if (s->percentage >= 90) {
        strcpy(s->grade, "O");
    } else if (s->percentage >= 85) {
        strcpy(s->grade, "A+");
    } else if (s->percentage >= 75) {
        strcpy(s->grade, "A");
    } else if (s->percentage >= 65) {
        strcpy(s->grade, "B+");
    } else if (s->percentage >= 60) {
        strcpy(s->grade, "B");
    } else if (s->percentage >= 55) {
        strcpy(s->grade, "C");
    } else if (s->percentage >= 50) {
        strcpy(s->grade, "D");
    } else {
        strcpy(s->grade, "F");
    }
}

float calculateCGPA(const char *grade) {
    switch (grade[0]) {
        case 'O': return 10.0;
        case 'A': return (grade[1] == '+') ? 9.0 : 8.5;
        case 'B': return (grade[1] == '+') ? 7.5 : 7.0;
        case 'C': return 6.0;
        case 'D': return 5.0;
        default: return 0.0;
    }
}

void processStudent(Student *s) {
    calculateTotal(s);
    calculatePercentage(s);
    assignGrade(s);
}