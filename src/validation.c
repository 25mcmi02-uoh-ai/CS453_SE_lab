#include <stdio.h>

#include "validation.h"

int isValidStudentCount(const char *input) {
    // check that it is a number
    int num = 0;
    if(sscanf(input, "%d", &num) != 1) {
        return 0;
    }
    return (num > 0 && num <= MAX_STUDENTS);
}