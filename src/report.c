#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "validation.h"
#include "utils.h"
#include "fileio.h"
#include "report.h"

void displayReport(Student students[], int count) {
    if(count == 0) {
        printf("No student records to display.\n");
        return;
    }

    printf("===== Students Report =====\n");
    printf("ID\tName\tTotal\tPercentage\tGrade\tCGPA\n");
    for(int i = 0; i < count; i++) {
        printf("%s\t%s\t%d\t%.2f\t\t%s\t%.2f\n", 
               students[i].id, 
               students[i].name, 
               students[i].total, 
               students[i].percentage, 
               students[i].grade, 
               students[i].cgpa);
    }
    displayStatistics(students, count);
}

void displayStatistics(Student students[], int count) {
    if(count == 0) {
        return;
    }

    float total_percentage = 0.0f;
    float total_cgpa = 0.0f;
    for(int i = 0; i < count; i++) {
        total_percentage += students[i].percentage;
        total_cgpa += students[i].cgpa;
    }

    float avg_percentage = total_percentage / count;
    float avg_cgpa = total_cgpa / count;

    printf("===== Statistics =====\n");
    printf("Average Percentage: %.2f\n", avg_percentage);
    printf("Average CGPA: %.2f\n", avg_cgpa);
}