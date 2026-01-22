#ifndef FILEIO_H
#define FILEIO_H

#include "student.h"


// int readStudentsFromFile(const char *filename, Student students[]);
void readStudentsFromUserInput(Student students[], int *count);
void writeResultsToFile(const char *filename, Student students[], int count);

#endif
