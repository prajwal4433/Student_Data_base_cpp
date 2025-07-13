#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

struct Marks
{
    float matriculation;
    float intermediate;
    float graduation;
};

struct Student
{
    string studentId;
    string name;
    string dob;
    Marks marks;
    string contact;
    string email;
    Student* next;
};

// Function declarations
Student* createStudentNode(const string& id, const string& name, const string& dob, float matric, float inter, float grad, const string& contact, const string& email);
bool isIdUnique(Student* head, const string& id);
void addStudentRecord(Student*& head);
void printStudentRecords(Student* head);
void deleteStudentRecord(Student*& head, const string& id);
Student* findStudentRecord(Student* head, const string& id);
void editStudentRecord(Student* head, const string& id);
void reverseStudentRecords(Student*& head);
void freeStudentList(Student*& head);

#endif
