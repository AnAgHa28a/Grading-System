#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "studentfunctions.h"

char assignGrade(float mark) {
    if (mark > 90) return 'S';
    if (mark > 80) return 'A';
    if (mark > 70) return 'B';
    if (mark > 60) return 'C';
    if (mark > 50) return 'D';
    if (mark > 40) return 'E';
    return 'F';
}

void getStudentDetails(GradeCard cards[], int size, int existingSize) {
    int studentNumber;
    for (int i = existingSize; i < existingSize + size; i++) {
        printf("Enter student %d number: ", i + 1);
        scanf("%d", &studentNumber);
        while (studentExist(cards, existingSize + size, studentNumber)) {
            printf("Student with Student Number %d already exists. Enter student %d number: ", studentNumber, i + 1);
            scanf("%d", &studentNumber);
        }
        cards[i].student.studentNumber = studentNumber;
        printf("Enter student %d name: ", i + 1);
        getchar(); // Consume the newline character left by the previous scanf
        fgets(cards[i].student.name, MAX_NAME_LENGTH, stdin);
        // Remove the trailing newline character if it exists
        size_t len = strlen(cards[i].student.name);
        if (len > 0 && cards[i].student.name[len - 1] == '\n') {
            cards[i].student.name[len - 1] = '\0';
        }
    }
}

void enterMarks(GradeCard cards[], char subjects[][MAX_NAME_LENGTH], int size, int existingSize) {
    for (int i = existingSize; i < existingSize + size; i++) {
        printf("Enter ISA and ESA marks for student %s for each subject:\n", cards[i].student.name);
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("Subject %s:\n", subjects[j]);
            printf("ISA 1 Marks: ");
            scanf("%f", &cards[i].grades[j].ISA1);
            printf("ISA 2 Marks: ");
            scanf("%f", &cards[i].grades[j].ISA2);
            printf("ESA Marks: ");
            scanf("%f", &cards[i].grades[j].ESA);
        }
    }
}

void calculateGrades(GradeCard cards[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            cards[i].grades[j].finalMark = (cards[i].grades[j].ISA1 + cards[i].grades[j].ISA2) / 2 * 0.4 + cards[i].grades[j].ESA * 0.6;
            cards[i].grades[j].grade = assignGrade(cards[i].grades[j].finalMark);
        }
    }
}

void printGradeCard(GradeCard cards[], char subjects[][MAX_NAME_LENGTH], int size) {
    printf("Total students: %d\n", size);
    for (int i = 0; i < size; i++) {
        printf("\nGrade Card for %d\t%s:\n", cards[i].student.studentNumber, cards[i].student.name);
        printf("----------------------------------------------------------------------------\n");
        printf("Number\tSubject\t\t\tISA1\tISA2\tESA\tFinalMarks\tGrade\n");
        printf("----------------------------------------------------------------------------\n");

        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("%d\t%s\t\t%.0f\t%.0f\t%.0f\t   %.0f\t\t%c\n",
                   j + 1, subjects[j], cards[i].grades[j].ISA1, cards[i].grades[j].ISA2,
                   cards[i].grades[j].ESA, cards[i].grades[j].finalMark, cards[i].grades[j].grade);
        }
        printf("----------------------------------------------------------------------------\n");
    }
}

void saveToFile(GradeCard cards[], int size,char subjects[][MAX_NAME_LENGTH]) {
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Write the CSV header
    fprintf(fp, "StudentNumber,StudentName,Subject,ISA1,ISA2,ESA,FinalMark,Grade\n");

    // Write the student data
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            fprintf(fp, "%d,%s,%s,%.2f,%.2f,%.2f,%.2f,%c\n",
                    cards[i].student.studentNumber, cards[i].student.name, subjects[j],
                    cards[i].grades[j].ISA1, cards[i].grades[j].ISA2,
                    cards[i].grades[j].ESA, cards[i].grades[j].finalMark,
                    cards[i].grades[j].grade);
        }
    }

    fclose(fp);
}

void readFromFile(GradeCard cards[], int *size) {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("No existing students.\n");
        return;
    }

    // Read the header line
    char header[256];
    fgets(header, sizeof(header), fp);

    *size = 0;
    while (fscanf(fp, "%d,%[^,],%*[^,],%f,%f,%f,%f,%c\n",
                  &cards[*size].student.studentNumber, cards[*size].student.name,
                  &cards[*size].grades[0].ISA1, &cards[*size].grades[0].ISA2,
                  &cards[*size].grades[0].ESA, &cards[*size].grades[0].finalMark,
                  &cards[*size].grades[0].grade) == 7) {
        for (int j = 1; j < MAX_SUBJECTS; j++) {
            fscanf(fp, "%*d,%*[^,],%*[^,],%f,%f,%f,%f,%c\n",
                   &cards[*size].grades[j].ISA1, &cards[*size].grades[j].ISA2,
                   &cards[*size].grades[j].ESA, &cards[*size].grades[j].finalMark,
                   &cards[*size].grades[j].grade);
        }
        (*size)++;
    }

    fclose(fp);
}

int studentExist(GradeCard cards[], int size, int studentNumber) {
    for (int i = 0; i < size; i++) {
        if (cards[i].student.studentNumber == studentNumber) {
            return 1;
        }
    }
    return 0;
}

void searchStudent(GradeCard cards[], char subjects[][MAX_NAME_LENGTH], int size, const char* studentName) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(cards[i].student.name, studentName) == 0) {
            printf("\nGrade Card for %d\t%s:\n", cards[i].student.studentNumber, cards[i].student.name);
            printf("----------------------------------------------------------------------------\n");
            printf("Number\tSubject\t\t\tISA1\tISA2\tESA\tFinalMarks\tGrade\n");
            printf("----------------------------------------------------------------------------\n");

            for (int j = 0; j < MAX_SUBJECTS; j++) {
                printf("%d\t%s\t\t%.0f\t%.0f\t%.0f\t   %.0f\t\t%c\n",
                       j + 1, subjects[j], cards[i].grades[j].ISA1, cards[i].grades[j].ISA2,
                       cards[i].grades[j].ESA, cards[i].grades[j].finalMark, cards[i].grades[j].grade);
            }
            printf("----------------------------------------------------------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Student with name %s not found.\n", studentName);
    }
}
