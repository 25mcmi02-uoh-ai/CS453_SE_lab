#include <stdio.h>

#include "validation.h"
#include "student.h"
#include "fileio.h"

void writeResultsToFile(const char *filename, Student students[], int count) {
    FILE *file = fopen(filename, "w");
    if(file == NULL) {
        printf("Error opening file %s for writing.\n", filename);
        return;
    }

    fprintf(file, "ID,Name,Total,Percentage,Grade,CGPA\n");
    for(int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%d,%.2f,%c,%.2f\n", 
                students[i].id, 
                students[i].name, 
                students[i].total, 
                students[i].percentage, 
                students[i].grade, 
                students[i].cgpa);
    }

    fclose(file);
    printf("Results successfully written to %s\n", filename);
}