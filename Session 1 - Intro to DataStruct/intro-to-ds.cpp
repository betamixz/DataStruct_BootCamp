#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Course
{
    char ID[10];
    int score; 

};

struct Student
{
    char name[255];
    double GPA;
    Course c;

};

Student *createStudent(const char *name, double gpa, const char *ID, int score)
{
    // Alokasi Memori
    Student *newStudent = (Student*)malloc(sizeof(Student));

    strcpy(newStudent -> name, name); // strcpy((*newStudent).name, name)
    newStudent-> GPA = gpa;
    strcpy(newStudent->c.ID, ID);
    newStudent->c.score = score;

    return newStudent;
}

void removeStudent(Student *s)
{
    free(s); // Buang memori s
    s = NULL; // kosongkan nilai
}

void printStudent(Student *s)  
{
    printf("Name: %s\n", s->name);
    printf("GPA: %.2lf\n", s->GPA);
    printf("Course ID: %s\n", s->c.ID);
    printf("Score: %d\n", s->c.score);

}

int main()
{
    Student students[10];

    // s1 mengarah ke student yand direturn oleh createStudent
    Student *s1 = createStudent("Budi", 4.00, "COMP6069", 85);
    Student *s2 = createStudent("Melati", 3.89, "COMP6054", 100);
  //  Student *s2 = createStudent(name, gpa, id, score);

    printf("BEFORE REMOVE\n");
    printStudent(s1);
    removeStudent(s1);

    printf("AFTER REMOVE\n");
    printStudent(s1);
    // printStudent(s1);

    return 0;
}