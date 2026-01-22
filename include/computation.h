#ifndef COMPUTATION_H
#define COMPUTATION_H

#include "student.h"

void calculateTotal(Student *s);
void calculatePercentage(Student *s);
void assignGrade(Student *s);
float calculateCGPA(const char *grade);

// // to calculate all computations for a student
void processStudent(Student *s);


#endif
