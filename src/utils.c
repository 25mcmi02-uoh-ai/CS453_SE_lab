#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "validation.h"
#include "utils.h"
#include "fileio.h"
#include "report.h"

void displayUserMenu() {
    printf("===== Student Management System =====\n");
    printf("1. Add Student\n");
    printf("2. Display Students Report\n");
    printf("3. Save to File\n");
    printf("4. Save and Exit\n");
    printf("Please select an option (1-4): ");
}

int readUserChoice() {
    int choice;
    if(scanf("%d", &choice) != 1) {
        while(getchar() != '\n'); // clear input buffer
        return -1; // invalid input
    }
    return choice;
}