#ifndef VALIDATION_H
#define VALIDATION_H

#include "student.h"

int isValidStudentCount(const char *input);
int isValidID(const char *id);
int isDuplicateID(Student students[], int count, const char *id);

int isValidName(const char *name);

int isValidMarks(int marks);

#endif
