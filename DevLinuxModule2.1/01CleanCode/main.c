
#include "inc/books.h"
#include "inc/students.h"

books* bookList = NULL;
students* studentList = NULL;

void showMenu();
void addBook(books **bookList);
void searchBookwithTitle(books *bookList);
void borrowBook(students** studentList, books* bookList);
void addStudent(students** studentList);

int main()
{

int choice;
    do 
    {
        showMenu();
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                borrowBook(&studentList, &bookList);
                break;
            case 2:
                showBookList(bookList);
                break;    
            case 3:
                showBookWithStatus(bookList, BOOK_AVAILABLE);
                break;
            case 4:
                showBookWithStatus(bookList, BOOK_BORROWED);
                break;
            case 5:
                addBook(&bookList);
                break;
            case 6:
                searchBookwithTitle(bookList);
                break;    
            case 7:
                
                break;
            case 8:
                showStudentList(studentList);
                break;
            case 9:
                addStudent(&studentList);
                break;
            case 10:
                
                break;
            case 11:
                listStudentWithBookStatus(studentList, BOOK_BORROWED);
                break;    
            case 12:
                
                break;
            case 0:
                printf("Goodbyte friend\n");
                break;   
            default:
                printf("Input Wrong Number\n");
        }
    } while (choice != 0);

    
    return 0;
   
}

void showMenu() 
{
    printf("\n====== LIBRARY MANAGEMENT MENU ======\n");

    printf("1. Processing Borrow book for Student \n");

    printf("2. Show Book List in Lib\n");
    printf("3. List down Available book list\n");
    printf("4. List down Borrowed book list\n");
    printf("5. Add new Book to Lib\n");
    printf("6. Search Book with Title \n");
    printf("7. Remove Book \n");
    
    printf("8. Show Student List \n");
    printf("9. Add new Student \n");
    printf("10. Search Student with name \n");
    printf("11. Show Students who borrowed books\n");
    printf("12. Remove student \n");
    
    printf("0. Exit\n");
    printf("Select: ");
}

void addBook(books **bookList)
{
    char bookTitle[BOOK_TITLE_MAX_LENGHT];
    char bookAuthor[BOOK_AUTHOR_MAX_LENGHT];
    char bookID[BOOK_ID_LENGHT];

    printf("Book Title: ");
    fgets(bookTitle, BOOK_TITLE_MAX_LENGHT, stdin);
    bookTitle[strcspn(bookTitle, "\n")] = 0;  

    printf("Book Author: ");
    fgets(bookAuthor, BOOK_AUTHOR_MAX_LENGHT, stdin);
    bookAuthor[strcspn(bookAuthor, "\n")] = 0;

    printf("Book ID: ");
    fgets(bookID, BOOK_ID_LENGHT, stdin);
    bookID[strcspn(bookID, "\n")] = 0;

    addBooksToLib(bookList, bookTitle, bookAuthor, bookID);
}

void searchBookwithTitle(books *bookList)
{
    char bookSearchTitle[BOOK_TITLE_MAX_LENGHT];

    printf("Please input Book Title: ");
    scanf("%50s", bookSearchTitle); 
    getchar(); 

    searchBook(bookList, bookSearchTitle);
}

void borrowBook(students** studentList, books* bookList)
{
    char inputBookID[BOOK_ID_LENGHT];
    int inputStudentId;

    printf("Student ID:");
    scanf("%d", &inputStudentId);
    getchar();

    printf("Book ID:");
    fgets(inputBookID, BOOK_ID_LENGHT, stdin);
    inputBookID[strcspn(inputBookID, "\n")] = 0; 
    
    addBookToStudentById(studentList, bookList, inputBookID, inputStudentId);
}

void addStudent(students** studentList)
{
    char newStudentName[MAX_NAME_LENGTH];
    int newStudentID;

    printf("Student ID:");
    scanf("%d", &newStudentID);
    getchar();

    printf("Student name:");
    fgets(newStudentName, MAX_NAME_LENGTH, stdin);
    newStudentName[strcspn(newStudentName, "\n")] = 0; 

    addNewStudent(studentList, newStudentName, newStudentID);
}
