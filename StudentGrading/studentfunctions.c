#include <stdio.h>
#include "studentfunctions.h"

void getStudentDetails(char names[][50], int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter student %d number: ", i + 1);
        scanf("%d", &numbers[i]);
        printf("Enter student %d name: ", i + 1);
        scanf("%s", names[i]);
    }
}

void enterMarks(char names[][50], char subjects[][50], float marks[][6][4], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter ISA and ESA marks for student %s for each subject:\n", names[i]);
        for (int j = 0; j < 6; j++) {
            printf("Subject %s: \n", subjects[j]);
			printf("ISA 1 Marks: ");
            scanf("%f", &marks[i][j][0]);
			printf("ISA 2 Marks: ");
            scanf("%f", &marks[i][j][1]);
			printf("ESA Marks: ");
            scanf("%f", &marks[i][j][2]);
        }
    }
}

void calculateGrades(float marks[][6][4], char final_grades[][6][1], int size) {
    for (int i = 0; i < size; i++) {
		for (int j = 0; j < 6; j++) {
			marks[i][j][3] = ((marks[i][j][0] + marks[i][j][1]) / 2.0 )*0.4+marks[i][j][2]*0.6;
			final_grades[i][j][0] = assignGrade(marks[i][j][3]);
    }
	}
}

char assignGrade(int mark)
{
	char g;
	if(mark>90)
		g='S';
	else if(mark>80 && mark<=90)
		g='A';
	else if(mark>70 && mark<=80)
		g='B';
	else if(mark>60 && mark<=70)
		g='C';
	else if(mark>50 && mark<=60)
		g='D';
	else if(mark>40 && mark<=50)
		g='E';
	else
		g='F';	
	return g;
}


void printGradeCard(char names[][50], char subjects[][50], int numbers[], float marks[][6][4],  char final_grades[][6][1], int size) {
	printf("Total students: %d\n",size);
	for(int i=0; i<size; i++) {
		printf("\nGrade Card for %d\t%s:\n",numbers[i],names[i]);
		printf("------------------------------------------------------------------------\n");
		printf("Number\tSubject\t\tISA1\tISA2\tESA\tFinalMarks\tGrade\n");
		printf("------------------------------------------------------------------------\n");
   
        for (int j = 0; j < 6; j++) {
			printf("%d\t%s\t", j+1,subjects[j]);
            printf("%0.0f\t%0.0f\t%0.0f\t   %0.0f\t\t%c\n", marks[i][j][0],marks[i][j][1],marks[i][j][2],marks[i][j][3],final_grades[i][j][0]);
        }

     printf("------------------------------------------------------------------------\n");
}
}
