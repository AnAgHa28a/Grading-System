#define STUDENTFUNCTIONS_H

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 6
#define MAX_NAME_LENGTH 50
#define FILENAME "student_data.csv"


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

void getStudentDetails(GradeCard cards[], int size,int existingSize);
void enterMarks(GradeCard cards[], char subjects[][MAX_NAME_LENGTH], int size, int existingSize);
void calculateGrades(GradeCard cards[], int size);
void printGradeCard(GradeCard cards[], char subjects[][MAX_NAME_LENGTH], int size);
char assignGrade(float mark);
void saveToFile(GradeCard cards[], int size,char subjects[][MAX_NAME_LENGTH]);
void readFromFile(GradeCard cards[], int *size);
int studentExist(GradeCard cards[], int size, int studentNumber);
void searchStudent(GradeCard cards[], char subjects[][MAX_NAME_LENGTH], int size, const char* studentName);

	

