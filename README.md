# Student_Data_base_cpp

Objective:
Develop a menu-driven application to manage student records with functionalities like add, delete, display, edit, search, save, and reverse records.

## User Interface:
The program should display a menu with these options:
-  a/A: Add a record
-  p/P: Print records
-  s/S: Save to file
-  d/D: Delete a record
-  e/E: Edit a record (with sub-options for name, DOB, marks, contact, email)
-  f/F: Find a student
-  r/R: Reverse display order
-  q/Q: Quit  

Student Record Structure:
Each record must include:
 - Student ID (e.g., V24HE6A1 → Vector2024HyderabadEmbeddedSeq7Akash1)
 - Name, Date of Birth (DOB)
 - Marks (Matriculation, Intermediate, Graduation percentages)
 - Contact number, Email ID

Key Requirements:
 - Prevent duplicate Student IDs.
 - Persistent storage: Data must be saved to a file and reloaded when the program restarts.
 - Dynamic Memory Allocation (DMA): Use structure pointers and a Singly Linked List (SLL) to manage records.
 - File Handling: Implement save() and load() functions to maintain data between sessions.

Project Structure:
- Separate files for each functionality (student.h, student.cpp, file_operations.h/cpp, menu_operations.h/cpp, main.cpp).
- Makefile for compilation.
- README.txt explaining usage, compilation, and execution.

Deliverables:
 - A folder named with your Student ID containing:
 - Source files (*.cpp, *.h)
 - Makefile
 - README.txt

Advanced Requirements:
- Use typedef, enum, or union where applicable.
- Follow C++ concepts (classes, STL if needed) while maintaining a C-like structure-based approach.
