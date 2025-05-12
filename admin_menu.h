#pragma once
#include <iostream>
#include <iomanip>
#include "file_manager.h"
using namespace std;

#define ADMIN_LOGIN "admin"
#define ADMIN_PASSWORD "1234"

void show_admin_menu();
void show_teachers_menu();
teacher* create_teacher();
void show_teachers(const vector<teacher*>& teachers);
void remove_teacher(vector<teacher*>& teachers);
void edit_teacher(vector<teacher*>& teachers);

void show_students_menu();
student* create_student();
void show_students(const vector<student*>& students);
void remove_student(vector<student*>& students);
void edit_student(vector<student*>& students);