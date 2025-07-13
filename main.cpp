#include "menu_operations.h"
#include "file_operations.h"

int main()
{
    Student* head=nullptr;
    const string filename="student_database.txt";
    
    loadFromFile(head, filename);
    
    processMenuChoice(head);
    
    return 0;
}
