#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "student.h"
#include "validation.h"
#include "utils.h"
#include "fileio.h"
#include "report.h"

int isValidStudentCount(const char *input) {
    int num = 0;
    if(sscanf(input, "%d", &num) != 1) {
        return 0;
    }
    return (num > 0 && num <= MAX_STUDENTS);
}

int isDuplicateID(Student students[], int count, const char *id) {
    for(int i = 0; i < count; i++) {
        if(strcmp(students[i].id, id) == 0) {
            return 1;
        }
    }
    return 0;
}

int isValidID(const char *id) {
    int len = strlen(id);
    if(len < 5 || len > 10) {
        return 0;
    }
    for(int i = 0; i < len; i++) {
        if(!isalnum(id[i])) {
            return 0;
        }
    }
    return 1;
}

int isValidName(const char *name) {
    int len = strlen(name);
    if(len < 1 || len > 50) {
        return 0;
    }
    for(int i = 0; i < len; i++) {
        if(!isalpha(name[i]) && name[i] != ' ') {
            return 0;
        }
    }
    return 1;
}
