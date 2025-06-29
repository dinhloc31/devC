# 📚 Library Management System in C

A simple command-line library management program written in C to manage students and books. The program allows adding/searching/removing books and students, borrowing books, and displaying lists.

---

## 1. 📦 Requirement

### Book Management
- Each book has the following information: **title**, **author**, **ID**, and **borrow status**.
- Allow adding, editing, and deleting books in the library.

### User Management
- Each user has the following information: **name**, **ID**, and a list of borrowed books.
- Allow adding, editing, and deleting user information.

### Borrow and Return Management
- Allow users to borrow books if the book is available in the library.
- Track the number of books borrowed and returned.

### Search and Display Information
- Search for books by title or author.
- Display the list of available books in the library.
- Display user information and the list of borrowed books.

### Error Handling
- Validate input data.
- Handle error cases such as out-of-stock books, non-existent users, etc.

---

## 2. 📁 Folder Structure

```
01CleanCode/
├── inc/
│   ├── books.h
│   └── students.h
├── src/
│   ├── books.c
│   ├── students.c
│   └── main.c
├── Makefile
└── readme.md
```

---

## 3. 🔧 Build & Run

### Option 1: build

make all

### Option 2: clean 

make clean

### Option 3: run

./main

---

## 4. 🧠 Features

- ✅ Borrow books by Student ID
- ✅ Add/search/remove books
- ✅ Add/search/remove students
- ✅ Show full/available/borrowed books
- ✅ Show list of students who borrowed books

---

## 5. 🧭 Menu Flow (main.c)

```text
====== LIBRARY MANAGEMENT MENU ======
1. Borrow book for student
2. Show book list
3. Show available books
4. Show borrowed books
5. Add new book
6. Search book by title
7. Remove book
8. Show student list
9. Add new student
10. Search student by name
11. Show students who borrowed books
12. Remove student
0. Exit
```

---

## 6. 🔍 Core Functions Overview

| Function                         | Description                                  |
|----------------------------------|----------------------------------------------|
| `addBook()`                      | Add new book to library                      |
| `searchBookwithTitle()`          | Search for book by title                     |
| `borrowBook()`                   | Assign a book to a student                   |
| `addStudent()`                   | Add a new student                            |
| `showBookList()`                 | Print all books                              |
| `showStudentList()`              | Print all students                           |
| `listStudentWithBookStatus()`    | List students by borrowed book status        |

---

## 7. 🧼 Notes

- Book and Student data are stored in linked lists
- Input is handled via `stdin`
- Code is modular and organized in `src` and `inc`

---

## 8. 📌 To-do / Improvements

- [ ] Add persistence (save/load from file)
- [ ] Implement remove/search student
- [ ] Improve input validation
- [ ] Add UI colors or menu cleanup

---

