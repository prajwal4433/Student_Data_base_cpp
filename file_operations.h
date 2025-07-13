#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "student.h"

void saveToFile(Student* head, const string& filename);
void loadFromFile(Student*& head, const string& filename);

#endif
