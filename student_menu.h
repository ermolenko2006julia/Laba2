#pragma once
#include "student.h"
#include "file_manager.h"
#include "admin_menu.h"
#include <vector>

student* find_student(const vector<student*>& students, string login, string password);
void show_student_menu(student* stud);
void show_all_marks(student* stud);
void show_marks_by_subject(student* stud, string subject);
