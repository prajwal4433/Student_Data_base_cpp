#include "student.h"

Student* createStudentNode(const string& id, const string& name, const string& dob, float matric, float inter, float grad, const string& contact, const string& email)
{
    Student* newStudent=new Student;
    newStudent->studentId=id;
    newStudent->name=name;
    newStudent->dob=dob;
    newStudent->marks.matriculation=matric;
    newStudent->marks.intermediate=inter;
    newStudent->marks.graduation=grad;
    newStudent->contact=contact;
    newStudent->email=email;
    newStudent->next=nullptr;
    return newStudent;
}

bool isIdUnique(Student* head, const string& id)
{
    Student* current=head;
    while(current!=nullptr)
    {
        if(current->studentId==id)
	{
            return false;
        }
        current=current->next;
    }
    return true;
}

void addStudentRecord(Student*& head)
{
    string id, name, dob, contact, email;
    float matric, inter, grad;
    
    cout<<"\nEnter Student ID (format V24HE6A1): ";
    cin>>id;
    
    if(!isIdUnique(head, id))
    {
        cout<<"Error: Student ID already exists!\n";
        return;
    }
    
    cin.ignore();
    cout<<"Enter Student Name: ";
    getline(cin, name);
    
    cout<<"Enter Date of Birth (DD-MM-YYYY): ";
    cin>>dob;
    
    cout<<"Enter Matriculation Percentage: ";
    cin>>matric;
    
    cout<<"Enter Intermediate/Diploma Percentage: ";
    cin>>inter;
    
    cout<<"Enter Graduation Percentage: ";
    cin>>grad;
    
    cout<<"Enter Contact Number: ";
    cin>>contact;
    
    cout<<"Enter Email ID: ";
    cin>>email;
    
    Student* newStudent=createStudentNode(id, name, dob, matric, inter, grad, contact, email);
    
    if(head==nullptr)
    {
        head=newStudent;
    } 
    else
    {
        Student* temp=head;
        while(temp->next!=nullptr)
	{
            temp=temp->next;
        }
        temp->next=newStudent;
    }
    
    cout<<"Student record added successfully!\n";
}

void printStudentRecords(Student* head)
{
    if(head==nullptr)
    {
        cout<<"No records to display!\n";
        return;
    }
    
    cout<<"\n\n";
    cout<<left<<setw(15)<<"Student ID"<<setw(25)<<"Name" 
              <<setw(15)<<"DOB"<<setw(10)<<"Matric%" 
              <<setw(10)<<"Inter%"<<setw(10)<<"Grad%" 
              <<setw(15)<<"Contact"<<setw(25)<<"Email"<<"\n";
    cout<<string(120, '-')<<"\n";
    
    Student* current=head;
    while(current!=nullptr) 
    {
        cout<<left<<setw(15)<<current->studentId 
                  <<setw(25)<<current->name 
                  <<setw(15)<<current->dob 
                  <<setw(10)<<current->marks.matriculation 
                  <<setw(10)<<current->marks.intermediate 
                  <<setw(10)<<current->marks.graduation 
                  <<setw(15)<<current->contact 
                  <<setw(25)<<current->email << "\n";
        current=current->next;
    }
}

void deleteStudentRecord(Student*& head, const string& id)
{
    if(head==nullptr)
    {
        cout<<"Database is empty!\n";
        return;
    }
    
    Student* current=head;
    Student* prev=nullptr;
    
    if(current!=nullptr && current->studentId==id)
    {
        head=current->next;
        delete current;
        cout<<"Record deleted successfully!\n";
        return;
    }
    
    while(current!=nullptr && current->studentId!=id)
    {
        prev=current;
        current=current->next;
    }
    
    if(current==nullptr)
    {
        cout<<"Record not found!\n";
        return;
    }
    
    prev->next=current->next;
    delete current;
    cout<<"Record deleted successfully!\n";
}

Student* findStudentRecord(Student* head, const string& id) 
{
    Student* current=head;
    while(current!=nullptr) 
    {
        if(current->studentId==id)
       	{
            return current;
        }
        current=current->next;
    }
    return nullptr;
}

void editStudentRecord(Student* head, const string& id)
{
    Student* student=findStudentRecord(head, id);
    if(student==nullptr) 
    {
        cout<<"Student not found!\n";
        return;
    }
    
    int choice;
    cout<<"\nEdit Menu:\n";
    cout<<"1) Edit name\n";
    cout<<"2) Edit DOB\n";
    cout<<"3) Edit percentages\n";
    cout<<"4) Edit contact\n";
    cout<<"5) Edit email\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    
    cin.ignore();
    switch(choice) 
    {
        case 1:
            cout<<"Enter new name: ";
            getline(cin, student->name);
            break;
        case 2:
            cout<<"Enter new DOB: ";
            cin>>student->dob;
            break;
        case 3:
            cout<<"Enter new matriculation percentage: ";
            cin>>student->marks.matriculation;
            cout<<"Enter new intermediate percentage: ";
            cin>>student->marks.intermediate;
            cout<<"Enter new graduation percentage: ";
            cin>>student->marks.graduation;
            break;
        case 4:
            cout<<"Enter new contact: ";
            cin>>student->contact;
            break;
        case 5:
            cout<<"Enter new email: ";
            cin>>student->email;
            break;
        default:
            cout<<"Invalid choice!\n";
            return;
    }
    
    cout<<"Record updated successfully!\n";
}

void reverseStudentRecords(Student*& head) 
{
    Student* prev=nullptr;
    Student* current=head;
    Student* next=nullptr;
    
    while(current!=nullptr) 
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    
    cout<<"Records reversed successfully!\n";
}

void freeStudentList(Student*& head)
{
    Student*current=head;
    while(current!=nullptr)
    {
        Student* next=current->next;
        delete current;
        current=next;
    }
    head=nullptr;
}

