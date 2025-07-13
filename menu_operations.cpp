#include "menu_operations.h"

void displayMenu()
{
    cout<<"\n------------------MENU--------------------------\n";
    cout<<"a/A  : Add a new student record\n";
    cout<<"p/P  : Print the records from database\n";
    cout<<"s/S  : Save the database in a file\n";
    cout<<"d/D  : Delete a record\n";
    cout<<"e/E  : Edit a record\n";
    cout<<"f/F  : Find a student\n";
    cout<<"r/R  : Reverse the records of current display\n";
    cout<<"q/Q  : Quit from app\n";
    cout<<"--------------------------------------------------\n";
    cout<<"Enter your choice: ";
}

void processMenuChoice(Student*& head)
{
    char choice;
    string id;
    const string filename="student_database.txt";
    
    do
    {
        displayMenu();
        cin>>choice;
        cin.ignore();
        
        switch(tolower(choice))
       	{
            case 'a':
                addStudentRecord(head);
                break;
            case 'p':
                printStudentRecords(head);
                break;
            case 's':
                saveToFile(head, filename);
                break;
            case 'd':
                cout<<"Enter Student ID to delete: ";
                cin>>id;
                deleteStudentRecord(head, id);
                break;
            case 'e':
                cout<<"Enter Student ID to edit: ";
                cin>>id;
                editStudentRecord(head, id);
                break;
            case 'f':
                cout<<"Enter Student ID to find: ";
                cin>>id;
                {
                    Student* found=findStudentRecord(head, id);
                    if(found!=nullptr)
		    {
                        cout<<"\nStudent Found:\n";
                        cout<<"ID: "<<found->studentId<<"\n";
                        cout<<"Name: "<<found->name<<"\n";
                        cout<<"DOB: "<<found->dob<<"\n";
                        cout<<"Matriculation %: "<<found->marks.matriculation<<"\n";
                        cout<<"Intermediate %: "<<found->marks.intermediate<<"\n";
                        cout<<"Graduation %: "<<found->marks.graduation<<"\n";
                        cout<<"Contact: "<<found->contact<<"\n";
                        cout<<"Email: "<<found->email<<"\n";
                    }
		    else 
		    {
                        cout<<"Student not found!\n";
                    }
                }
                break;
            case 'r':
                reverseStudentRecords(head);
                break;
            case 'q':
                cout<<"Exiting program...\n";
                saveToFile(head, filename);
                freeStudentList(head);
                break;
            default:
                cout<<"Invalid choice! Please try again.\n";
        }
    }while(tolower(choice)!='q');
}
