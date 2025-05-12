#pragma once
#include "teacher.h"
#include "file_manager.h"
#include "admin_menu.h"
#include <vector>

teacher* find_teacher(const vector<teacher*>& teachers, string login, string password);
void show_teacher_menu(teacher* t);
void add_mark(string subject, const vector<student*>& students);
void show_marks(string subject, const vector<student*>& students);