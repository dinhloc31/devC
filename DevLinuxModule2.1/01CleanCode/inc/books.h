#include "stdbool.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BOOKS_H
#define BOOKS_H

#define BOOK_TITLE_MAX_LENGHT 50
#define BOOK_AUTHOR_MAX_LENGHT 100
#define BOOK_ID_LENGHT 4

#define BOOK_BORROWED 1
#define BOOK_AVAILABLE 0

typedef struct books
{
    char bookTitle[BOOK_TITLE_MAX_LENGHT];
    char bookAuthor[BOOK_AUTHOR_MAX_LENGHT];
    char bookID[BOOK_ID_LENGHT];
    bool bookStatus;
    struct books* nextBook;

}books;

void addBooksToLib(books** bookList, char newbookTitle[BOOK_TITLE_MAX_LENGHT], char newbookAuthor[BOOK_AUTHOR_MAX_LENGHT], char newbookID[BOOK_ID_LENGHT]);
void removeBooksFromLib(books** bookList, char* bookRemoveID);
void searchBook(books* bookList, char* bookSearchTitle);
books* findBookById(books* bookList, char targetBookID[BOOK_ID_LENGHT]);
void showBookList(books* bookList);
void showBookWithStatus(books* bookList, bool bookStatus);
int checkDuplicateBook(books* list, char* bookID) ;

#endif