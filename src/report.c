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

    // AI was used in this function to format the report output neatly
    printf("===== Students Report =====\n");
    printf("%-12s %-20s %-8s %-12s %-8s %-8s\n", 
            "ID", "Name", "Total", "Percentage", "Grade", "CGPA");
    printf("%-12s %-20s %-8s %-12s %-8s %-8s\n", 
            "----------", "--------------------", "------", "----------", "------", "------");
    for(int i = 0; i < count; i++) {
        printf("%-12s %-20s %-8d %-12.2f %-8s %-8.2f\n", 
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