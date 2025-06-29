#include "students.h"

void addNewStudent(students **studentList, char newStudentName[MAX_NAME_LENGTH], int newStudentID)
{
    students *newstudent = (students*)malloc(sizeof(students));
    if (newstudent == NULL)
    {
        printf("Fail Allocation\n");
        return;
    }
    strcpy(newstudent->studentName, newStudentName);
    newstudent->studentID = newStudentID;
    newstudent->bookList = NULL;
    newstudent->nextStudent=*studentList;
    *studentList=newstudent;
}

void removeStudentFromList(students **studentList, int StudentIdRemove)
{
    if (*studentList==NULL)
    {
        printf("Student List is empty, please check again \n");
        return;
    }

    students *currentStudent = *studentList;
    students *previousStudent = NULL;
    /*Process to remove first Student*/
    if (currentStudent->studentID == StudentIdRemove) 
    {
        *studentList = currentStudent->nextStudent;
        free(currentStudent);
        printf("Student with ID %s removed from the list.\n", StudentIdRemove);
        return;
    }

    /*Finding Student*/
    while (currentStudent != NULL && (currentStudent->studentID != StudentIdRemove)) 
    {
        previousStudent = currentStudent;
        currentStudent = currentStudent->nextStudent;
    }
    if (currentStudent == NULL)
    {
        printf("Student ID %s not found in the list.\n", StudentIdRemove);
        return;
    }

    /*Remove Book*/
    previousStudent->nextStudent = currentStudent->nextStudent;
    free(currentStudent);
    printf("Student with ID %s removed from the list.\n", StudentIdRemove);
}

void addBookToStudentById(students** studentList, books** bookList, char bookID[BOOK_ID_LENGHT], int targetStudentID)
{
    students* targetStudent = findStudentByiD(*studentList, targetStudentID);
    books* targetBook = findBookById(*bookList, bookID);
    if (targetStudent&&targetBook)
    {
        if (targetBook->bookStatus == BOOK_BORROWED) {
        printf("This book is already borrowed.\n");
        return;
}
        targetStudent->bookList = targetBook;
        targetBook->bookStatus = BOOK_BORROWED;

        printf("Student ID %d borrowed book ID %s\n", targetStudentID, targetBook->bookID);
    }
    else
    {
        printf("Student or Book not found.\n");
    }
    
}

void listStudentWithBookStatus(students **studentList, bool bookStatus)
{
}

void showStudentList(students *studentList)
{
    if (studentList == NULL)
    {
        printf("Student List is empty, please check again \n");
        return;
    }
    
    printf("==========STUDENT LIST==========\n");
    while (studentList != NULL)
    {
        printf("  Name: %s\n", studentList->studentName);
        printf("  ID : %d\n", studentList->studentID);
        //printf("  Borrowed Book : %s\n", bookList->bookID);
        printf("-----------------------------------\n");

        studentList = studentList->nextStudent;
    }
}

students* findStudentByiD(students* studentList, int targetStudentID)
{
    if (studentList == NULL)
    {
        printf("Student list is empty, please check again.\n");
        return NULL;
    }

    students* currentStudent = studentList;
    while (currentStudent != NULL)
    {
        if (currentStudent->studentID == targetStudentID)
        {
            return currentStudent; 
        }
        currentStudent = currentStudent->nextStudent;
    }

    printf("Student ID %d not found in the list.\n", targetStudentID);
    return NULL;
}