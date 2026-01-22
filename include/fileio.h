#ifndef FILEIO_H
#define FILEIO_H

#include "student.h"


// Input functions
void inputStudentID(Student students[], int count, char *id);
void inputStudentName(char *name);
void inputStudentMarks(int marks[]);
void readStudentsFromUserInput(Student students[], int *count);

// files functions
// int readStudentsFromFile(const char *filename, Student students[]);
void writeResultsToFile(const char *filename, Student students[], int count);

#endif
