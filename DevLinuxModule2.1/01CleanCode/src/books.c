#include "books.h"


void addBooksToLib(books** bookList, char newbookTitle[BOOK_TITLE_MAX_LENGHT], char newbookAuthor[BOOK_AUTHOR_MAX_LENGHT], char newbookID[BOOK_ID_LENGHT])
{
    if (checkDuplicateBook(*bookList, newbookID))
    {
        printf("Duplicate Book ID %s in warehouse \n", newbookID);
        return;
    }
     
    books* newBook = (books*)malloc(sizeof(books));
    if (newBook == NULL)
    {
        printf("Allocation newBook Fail \n");
        return;
    }

    strcpy(newBook->bookTitle,newbookTitle);
    strcpy(newBook->bookAuthor,newbookAuthor);
    strcpy(newBook->bookID,newbookID);
    newBook->bookStatus=BOOK_AVAILABLE;
    newBook->nextBook=*bookList;
    *bookList=newBook;
}

void removeBooksFromLib(books **bookList, char* bookRemoveID)
{

    if (*bookList==NULL)
    {
        printf("Book Lib is empty, please check again \n");
        return;
    }

    books *currentBook = *bookList;
    books *previousBook = NULL;
    /*Process to remove first book*/
    if (strcmp(currentBook->bookID, bookRemoveID) == 0) 
    {
        *bookList = currentBook->nextBook;
        free(currentBook);
        printf("Book with ID %s removed from the list.\n", bookRemoveID);
        return;
    }

    /*Finding book*/
    while (currentBook != NULL && strcmp(currentBook->bookID, bookRemoveID) != 0) 
    {
        previousBook = currentBook;
        currentBook = currentBook->nextBook;
    }
    if (currentBook == NULL)
    {
        printf("Book ID %s not found in the list.\n", bookRemoveID);
        return;
    }

    /*Remove Book*/
    previousBook->nextBook = currentBook->nextBook;
    free(currentBook);
    printf("Book with ID %s removed from the list.\n", bookRemoveID);
    
}

void searchBook(books *bookList, char* bookSearchTitle)
{
    if (bookList == NULL)
    {
        printf("Book Lib is empty, please check again \n");
        return;
    }
    
    int foundBook = 0;
    while (bookList != NULL)
    {
        if(strcmp(bookList->bookTitle, bookSearchTitle) == 0)
        {
            printf ("Found Book\n");
            printf("  Title: %s\n", bookList->bookTitle);
            printf("  Author : %s\n", bookList->bookAuthor);
            printf("  BookID : %s\n", bookList->bookID);
            printf("  Book Status : %s\n", bookList->bookStatus == BOOK_AVAILABLE ? "Available" : "Borrowed");
            printf("-----------------------------------\n");
            foundBook++;
        }
        bookList = bookList->nextBook;
    }
    if (foundBook == 0)
    {
        printf("Don't have anybook with Title %s in Library, please check again \n", bookSearchTitle);
    }
    
}

books* findBookById(books* bookList, char targetBookID[BOOK_ID_LENGHT])
{
    if (bookList == NULL)
    {
        printf("Book Lib is empty, please check again \n");
        return NULL;
    }

    books* currentBook = bookList;
    while (currentBook != NULL)
    {
        if (strcmp(currentBook->bookID, targetBookID) == 0)
        {
            return currentBook;
        }
        currentBook = currentBook->nextBook;
    }
    
    printf("Can't find the BookId in Lib, please check again.\n");
    return NULL;
}

void showBookList(books *bookList)
{
    if (bookList==NULL)
    {
        printf("Book Lib is empty, please check again \n");
        return;
    }
    
    printf("==========BOOK LIST==========\n");
    while (bookList!=NULL)
    {
        printf("  Title: %s\n", bookList->bookTitle);
        printf("  Author : %s\n", bookList->bookAuthor);
        printf("  BookID : %s\n", bookList->bookID);
        printf("  Book Status : %s\n", bookList->bookStatus == BOOK_AVAILABLE ? "Available" : "Borrowed");
        printf("-----------------------------------\n");

        bookList = bookList->nextBook;
    }
    
}

void showBookWithStatus(books *bookList, bool bookStatus)
{
    if (bookList==NULL)
    {
        printf("Book Lib is empty, please check again \n");
        return;
    }
    
    printf("==========AVAILABLE BOOK==========\n");
    while (bookList!=NULL && bookList->bookStatus == bookStatus)
    {
        printf("  Title: %s\n", bookList->bookTitle);
        printf("  Author : %s\n", bookList->bookAuthor);
        printf("  BookID : %s\n", bookList->bookID);
        printf("  Book Status : %s\n", bookList->bookStatus == BOOK_AVAILABLE ? "Available" : "Borrowed");
        printf("-----------------------------------\n");

        bookList = bookList->nextBook;
    }
}

int checkDuplicateBook(books* list, char* bookID) {
    books* temp = list;
    while(temp != NULL) 
    {
        if(strcmp(temp->bookID, bookID) == 0) {
            return 1; //Duplicate ID
        }
        temp = temp->nextBook;
    }
    return 0; 
}
