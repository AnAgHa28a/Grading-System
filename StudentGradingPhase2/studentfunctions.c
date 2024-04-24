#include <stdio.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 6
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int studentNumber;
} Student;

typedef struct {
    float ISA1;
    float ISA2;
    float ESA;
    float finalMark;
    char grade;
} SubjectGrades;

typedef struct {
    Student student;
    SubjectGrades grades[MAX_SUBJECTS];
} GradeCard;

char assignGrade(float mark) {
    if (mark > 90) return 'S';
    if (mark > 80) return 'A';
    if (mark > 70) return 'B';
    if (mark > 60) return 'C';
    if (mark > 50) return 'D';
    if (mark > 40) return 'E';
    return 'F';
}

void getStudentDetails(GradeCard cards[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter student %d number: ", i + 1);
        scanf("%d", &cards[i].student.studentNumber);
        printf("Enter student %d name: ", i + 1);
        scanf("%s", cards[i].student.name);
    }
}

void enterMarks(GradeCard cards[], char subjects[][MAX_NAME_LENGTH], int size) {
    for (int i = 0; i < size; i++) {
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
                   j+1, subjects[j], cards[i].grades[j].ISA1, cards[i].grades[j].ISA2,
                   cards[i].grades[j].ESA, cards[i].grades[j].finalMark, cards[i].grades[j].grade);
        }
        printf("----------------------------------------------------------------------------\n");
    }
}


