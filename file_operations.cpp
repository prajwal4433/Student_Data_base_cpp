#include "file_operations.h"

void saveToFile(Student* head, const string& filename)
{
    ofstream outFile(filename);
    if(!outFile){
        cerr<<"Error opening file for writing!\n";
        return;
    }
    
    Student* current=head;
    while(current!=nullptr) 
    {
        outFile<<current->studentId<<","
                <<current->name<<","
                <<current->dob<<","
                <<current->marks.matriculation<<","
                <<current->marks.intermediate<<","
                <<current->marks.graduation<<","
                <<current->contact<<","
                <<current->email<<"\n";
        current=current->next;
    }
    
    outFile.close();
    cout<<"Database saved to file successfully!\n";
}

void loadFromFile(Student*& head, const string& filename)
{
    ifstream inFile(filename);
    if(!inFile)
    {
        cout<<"No existing database file found. Starting with empty database.\n";
        return;
    }
    
    string line;
    while(getline(inFile, line)) 
    {
        stringstream ss(line);
        string id, name, dob, contact, email;
        float matric, inter, grad;
        
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, dob, ',');
        ss>>matric;
        ss.ignore();
        ss>>inter;
        ss.ignore();
        ss>>grad;
        ss.ignore();
        getline(ss, contact, ',');
        getline(ss, email);
        
        Student* newStudent=createStudentNode(id, name, dob, matric, inter, grad, contact, email);
        
        if(head==nullptr)
	{
            head = newStudent;
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
    }
    
    inFile.close();
    cout << "Database loaded from file successfully!\n";
}
