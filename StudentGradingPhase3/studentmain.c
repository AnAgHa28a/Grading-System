#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "studentfunctions.h"



int main() {
   GradeCard cards[MAX_STUDENTS];
  // char subjects[MAX_SUBJECTS][MAX_NAME_LENGTH] = {"UE23CS151B", "UE23EE141B", "UE23EV111B", "UE23MA141B", "UE23ME131B", "UE23PH151B"};
   char subjects[MAX_SUBJECTS][MAX_NAME_LENGTH] = {"C Programming", "Electrical", "Mathematics", "Mechanical", "Physics   ", "EVS       "};
    int size, existingSize;
    char studentName[MAX_NAME_LENGTH];
	
	//load existing data for struct array
	readFromFile(cards, &existingSize);
	
    printf("There are %d students existing. Enter the number of additional students: ",existingSize);
    scanf("%d", &size);
	
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Enter student details\n");
        printf("2. Enter marks\n");
        printf("3. Calculate final marks\n");
        printf("4. Print grade card\n");
		printf("5. Search for Student\n");
		//printf("6. Save All Student Details along with Grades to file\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getStudentDetails(cards, size,existingSize);
				saveToFile(cards, existingSize+size,subjects);
                break;
            case 2:
                enterMarks(cards, subjects, size,existingSize);
				saveToFile(cards, existingSize+size,subjects);
                break;
            case 3:
                calculateGrades(cards, size+existingSize);
				saveToFile(cards, existingSize+size,subjects);
                printf("Final marks calculated successfully.\n");
                break;
            case 4:
                printGradeCard(cards, subjects, existingSize+size);
                break;
			case 5:
				printf("\nEnter student name to search: ");
				getchar(); // Consume the newline character left by the previous scanf
				fgets(studentName, MAX_NAME_LENGTH, stdin);
				// Remove the trailing newline character if it exists
				size_t len = strlen(studentName);
				if (len > 0 && studentName[len-1] == '\n') {
					studentName[len-1] = '\0';
				}
				
                searchStudent(cards, subjects,existingSize+size, studentName);
				
                break;
			/* case 6:
                saveToFile(cards, existingSize+size);
				printf("All details are saved to the file successfully.\n");
                break; */
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 0 and 4.\n");
        }
    } while (choice != 0);

    return 0;
}


