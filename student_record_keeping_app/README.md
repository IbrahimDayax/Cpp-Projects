# Student Record Keeping System

This is a simple command-line application that allows you to create, view, sort, modify, search and delete student records using a linked list and file storage.

## Getting Started

To use the app, simply clone or download the repository, and run the program in your C++ compiler.

## Prerequisites

    C++ compiler (e.g. GCC, Visual Studio)

## Installing

To run the program, open the .cpp file in your C++ compiler and build the program.

## Using the App

When the program is run, it will display a menu with the following options:

    Enter a New Record: Allows you to create a new student record by entering the student's first name, last name, ID number, course ID, and total score.
    Display Record: Allows you to view all student records in the system.
    Sort using total score: Allows you to sort the student records by total score.
    Modify a record: Allows you to modify a student record by searching for it using the student's ID number.
    Search for a record: Allows you to search for a student record by searching for it using the student's ID number or course ID.
    Delete a record: Allows you to delete a student record by searching for it using the student's ID number.
    Exit: Exits the program.

The student records are stored in a linked list and also in a file named "records.txt". When a new record is added or an existing record is modified or deleted, the linked list is updated and the new data is written to the file.

## How to use the program

Upon running the program, the user will be presented with a menu of options. The user can select any option by inputting the corresponding number. Once an option has been selected, the program will prompt the user for any additional information needed to complete the operation.

### 1. Enter a new student record

This option allows the user to enter a new student record. The user will be prompted to enter the student's first name, last name, ID number, course ID and total score. The record will be added to the end of the "database.txt" file.

### 2. Display existing student records

This option allows the user to display all existing student records. The records will be displayed in the order they were added to the "database.txt" file.

### 3. Sort student records by total score

This option allows the user to sort the student records by total score. The records will be sorted in ascending order.

### 4. Modify a student record

This option allows the user to modify a student record by searching for it using the student's ID number. The user will be prompted to enter the new first name, last name, course ID, and total score of the student.

### 5. Search for a student record

This option allows the user to search for a student record by entering the student's ID number. The program will display the student's record if it is found.

### 6. Delete a student record

This option allows the user to delete a student record by searching for it using the student's ID number. The program will delete the student's record if it is found.

### 7. Exit
This option allows the user to exit the program.

## Note
This program is designed to handle the basic functionality of student record keeping, but it can be enhanced by adding more functionality such as a graphical user interface, validating input, and handling edge cases.

## Conclusion
This is a simple program that demonstrates the use of a LinkedList data structure to store and manipulate student records. It can be used as a starting point for more advanced student record keeping applications.
