#include <stdio.h>
#include "studentfunctions.h"

#define MAX_STUDENTS 10

int main() {
    char stud_names[MAX_STUDENTS][50];
    int numbers[MAX_STUDENTS];
    float marks[MAX_STUDENTS][6][4];
	char subjects[6][50]= {"UE23CS151B", "UE23EE141B", "UE23EV111B", "UE23MA141B", "UE23ME131B", "UE23PH151B"};
	char final_grades[MAX_STUDENTS][6][1];
	
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Enter student details\n");
        printf("2. Enter marks\n");
        printf("3. Calculate final marks\n");
        printf("4. Print grade card\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getStudentDetails(stud_names, numbers, MAX_STUDENTS);
                break;
            case 2:
                enterMarks(stud_names, subjects, marks, MAX_STUDENTS);
                break;
            case 3:
                calculateGrades(marks, final_grades, MAX_STUDENTS);
                printf("Final marks calculated successfully.\n");
                break;
            case 4:
                printGradeCard(stud_names, subjects, numbers, marks, final_grades, MAX_STUDENTS);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 0 and 4.\n");
        }
    } while (choice != 0);

    return 0;
}


