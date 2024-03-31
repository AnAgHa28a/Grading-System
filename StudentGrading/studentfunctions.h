#define STUDENTFUNCTIONS_H

void getStudentDetails(char names[][50], int numbers[], int size);
void enterMarks(char names[][50],char subjects[][50], float marks[][6][4],  int size);
void calculateGrades(float marks[][6][4], char final_grades[][6][1], int size);
void printGradeCard(char names[][50], char subjects[][50], int numbers[], float marks[][6][4],  char final_grades[][6][1], int size);
char assignGrade(int mark);


