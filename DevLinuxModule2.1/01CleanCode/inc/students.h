#ifndef STUDENTS_H
#define STUDENTS_H

#include "books.h"

#define MAX_NAME_LENGTH 10

typedef struct students
{
    char studentName[MAX_NAME_LENGTH];
    int studentID;
    books* bookList;
    struct students* nextStudent;
}students;

void addNewStudent(students** studentList, char newStudentName[MAX_NAME_LENGTH], int newStudentID);
void removeStudentFromList(students** studentList, int StudentIdRemove);
void addBookToStudentById(students** studentList, books** bookList, char bookID[BOOK_ID_LENGHT], int studentID);
void listStudentWithBookStatus(students** studentList, bool bookStatus);
void showStudentList(students* studentList);
students* findStudentByiD(students* studentList, int targetStudentID);

#endif