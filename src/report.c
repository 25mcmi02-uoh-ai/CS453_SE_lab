#include <stdio.h>

#include "validation.h"
#include "student.h"
#include "report.h"

void displayReport(Student students[], int count) {
    if(count == 0) {
        printf("No student records to display.\n");
        return;
    }

    printf("===== Students Report =====\n");
    printf("ID\tName\tTotal\tPercentage\tGrade\tCGPA\n");
    for(int i = 0; i < count; i++) {
        printf("%s\t%s\t%d\t%.2f\t\t%c\t%.2f\n", 
               students[i].id, 
               students[i].name, 
               students[i].total, 
               students[i].percentage, 
               students[i].grade, 
               students[i].cgpa);
    }
    displayStatistics(students, count);
}