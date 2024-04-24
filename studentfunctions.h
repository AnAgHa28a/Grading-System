#define STUDENTFUNCTIONS_H



void getStudentDetails(GradeCard cards[], int size);
void enterMarks(GradeCard cards[], char subjects[][MAX_NAME_LENGTH], int size);
void calculateGrades(GradeCard cards[], int size);
void printGradeCard(GradeCard cards[], char subjects[][MAX_NAME_LENGTH], int size);
char assignGrade(float mark);


