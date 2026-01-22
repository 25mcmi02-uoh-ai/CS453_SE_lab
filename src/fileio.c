#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "validation.h"
#include "utils.h"
#include "fileio.h"
#include "report.h"

void writeResultsToFile(const char *filename, Student students[], int count) {
    FILE *file = fopen(filename, "w");
    if(file == NULL) {
        printf("Error opening file %s for writing.\n", filename);
        return;
    }

    fprintf(file, "ID,Name,Total,Percentage,Grade,CGPA\n");
    for(int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%d,%.2f,%s,%.2f\n", 
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