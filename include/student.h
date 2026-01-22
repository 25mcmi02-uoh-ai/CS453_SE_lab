#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define SUBJECTS 5
#define MAX_ID_LEN 10
#define MAX_NAME_LEN 50

typedef struct {
    char id[MAX_ID_LEN];
    char name[MAX_NAME_LEN];
    int marks[SUBJECTS];
    int total;
    float percentage;
    char grade[3];
    float cgpa;
} Student;

// void createStudentArray(int num_students, Student students[]);
void addStudent(Student students[], int *count);
// void displayStudent(const Student *s);

#endif
