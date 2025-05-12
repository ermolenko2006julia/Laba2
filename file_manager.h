#pragma once
#include "teacher.h"
#include <string>
#include "student.h"
#include <fstream>
#include <sstream>

void save_teachers(const vector<teacher*>& teachers);
vector<teacher*> read_teachers();
void save_students(const vector<student*>& students);
vector<student*> read_students();

