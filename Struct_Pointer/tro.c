#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[20];
    char studentID[10];
    float gpa;
} Student;

typedef Student* Student_t;

typedef enum{TRUE,FALSE} Boolean;

void addStudent(Student_t Studentlist[], int *numStudents, char *name, char *studentID, float GPA)
{
    Student_t newStudent = malloc(sizeof(Student));

    strcpy(newStudent->name,name);
    strcpy(newStudent->studentID,studentID);
    newStudent->gpa = GPA;

    Studentlist[*numStudents] = newStudent;
    (*numStudents)++;
}

void printStudent(Student_t student){
    printf("Name: %s\n",student->name);
    printf("StudenID: %s\n",student->studentID);
    printf("GPA: %.2f\n\n",student->gpa);
}

void printAllStudents(Student_t Studentlist[], int numStudents)
{
    printf("List of %d students:\n\n",numStudents);
    for(int i = 0; i < numStudents; ++i)
    {
        printStudent(Studentlist[i]);
    }
}

void findStudentByID(Student_t Studentlist[], int numStudents,char *studenID)
{
    for(int i = 0; i < numStudents; ++i)
    {
        if(strcmp(Studentlist[i]->studentID,studenID) == 0)
        {
            printStudent(Studentlist[i]);
            return;
        }
    }
}

void updateGPA(Student_t Studentlist[], int numStudents, char *studentID, float newGPA)
{
    for(int i = 0; i < numStudents; ++i)
    {
        if(strcmp(Studentlist[i]->studentID,studentID) == 0)
       { Studentlist[i]->gpa = newGPA;
       return;
    }}
        printf("Can not find studentID: %s",studentID);
}

int deleteStudent(Student_t Studentlist[], int *numStudent, char *studentID)
{
    for(int i = 0; i < *numStudent; ++i)
    {
        if(strcmp(Studentlist[i]->studentID,studentID) == 0)
        {
            free(Studentlist[i]);
            for(int j = i; j < *numStudent - 1; ++j)
            {
                Studentlist[j] = Studentlist[j+1];
            }
            (*numStudent)--;
            return 0;
        }
        return 1;
    }
}

int main() {
    Student_t students[100];
    int numStudents = 0;

    Boolean isTrue = TRUE;
    Boolean isFalse = FALSE;

    addStudent(students, &numStudents, "John Doe", "12345", 3.5);
    addStudent(students, &numStudents, "Jane Smith", "67890", 3.8);
    addStudent(students, &numStudents, "Foungth", "221242", 3.9);
    printAllStudents(students,numStudents);
    printf("Then we find student by ID\n");
    findStudentByID(students,numStudents,"221242");
    deleteStudent(students,&numStudents,"12345");
    updateGPA(students,numStudents,"221242",4.0);
    printf("After deleting\n");
    printAllStudents(students,numStudents);

}