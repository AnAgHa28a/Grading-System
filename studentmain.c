#include <stdio.h>
#include "studentfunctions.h"

//#define MAX_STUDENTS 10

int main() {
   GradeCard cards[MAX_STUDENTS];
    char subjects[MAX_SUBJECTS][MAX_NAME_LENGTH] = {"UE23CS151B", "UE23EE141B", "UE23EV111B", "UE23MA141B", "UE23ME131B", "UE23PH151B"};
    int size;

    printf("Enter the number of students: ");
    scanf("%d", &size);
	
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
                getStudentDetails(cards, size);
                break;
            case 2:
                enterMarks(cards, subjects, size);
                break;
            case 3:
                calculateGrades(cards, size);
                printf("Final marks calculated successfully.\n");
                break;
            case 4:
                printGradeCard(cards, subjects, size);
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


