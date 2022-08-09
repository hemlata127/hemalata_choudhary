PROJECT NAME`
Virtual Student Database

INTERFACE TYPE
Command User Interface

PROJECT DESCRIPTION
This project creates a data base of student records in memory. 
Student details are stored in a struct object created in memory.
Following details are stored
1. Roll Number
2. Student Name
3. Student year (FE, SE, TE, BE)
4. Department
5. Percentage in recent exams
The information is stored and managed using the data Structure - Doubly circular linked list.
Each node of a doubly circular linked list stores:
1. Pointer to object storing student details
2. Forward Pointer
3. Backward Pointer

Student roll number is assigned using a global variable whose value is incremented each time a new record is created.
Roll Numbers of records deleted are not assigned again.

OPERATIONS SUPPORTED
Following operations are supported
1. Insert new student record
This operation inserts a new record with student details at the end of an existing list
2. Remove last student record
Deletes the last record in the list
3. Remove first student record
Deletes the first record in the list
4. Remove student record
Deletes the student record with specified roll number
5. Read first student record
Fetches the first student record in the list and displays the details
6. Read last student record
Fetches the last student record from the list and displays the details of that record
7. Search if student record exists
Searches and displays a student record with matching roll number
8. Show all student records
Displays the entire list
9. Count records
Finds and displays the total number of records
