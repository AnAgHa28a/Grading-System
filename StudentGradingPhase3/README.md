The program manages student data, including their details, marks, and grades for multiple subjects. It allows users to input new student data, enter marks, calculate final grades, print grade cards, search for students by name, and save the data to a file named "student_data.csv".

The program presents a menu with options to enter student details, enter marks, calculate final marks, print grade cards, search for a student, and exit the program.
The menu is displayed in a loop until the user chooses to exit.
Menu Options:
Enter Student Details (Case 1):
Collect details for new students and save the updated student data to the CSV file.
Enter Marks (Case 2):
Collect marks for new students and save the updated student data to the CSV file
Calculate Final Marks (Case 3):
Compute final marks and grades for all students and save the updated student data to the CSV file
Print Grade Card (Case 4):
Displays the grade cards for all students.
Search for Student (Case 5):
Prompts the user to enter a student's name. Searches for and displays the grade card of the specified student.
Exit Program (Case 0):

To execute, copy all files to the same folder and execute the command (pre-requisite gcc and make should be installed)
make -f makefile.mk
This will create an executable file grade_system.exe which can be executed.
