#include <iostream>
#include "admin_menu.h"
#include "teacher_menu.h"
#include "student_menu.h"
using namespace std;

int main()
{
	cout << "You must use only English" << endl;
	cout << ("---------------------------------------") << endl;
	cout << "Your choice:" << endl;
	cout << "1. Student " << endl;
	cout << "2. Teacher " << endl;
	cout << "3. Administrator " << endl;
	cout << ("---------------------------------------\n") << endl;
    int role;
    cin >> role;

    switch (role)
    {
    case 1:
    {
        string login, password;
        cout << "Enter login: ";
        cin >> login;

        cout << "Enter password: ";
        cin >> password;

        vector<student*> students = read_students();
        student* t = find_student(students, login, password);
        if (t != nullptr) {
            show_student_menu(t);
        }
        else {
            cout << "Invalid login or password!" << endl;
        }
    }
        break;
    case 2: {
        string login, password;
        cout << "Enter login: ";
        cin >> login;

        cout << "Enter password: ";
        cin >> password;

        vector<teacher*> teachers = read_teachers();
        teacher* t = find_teacher(teachers, login, password);
        if (t != nullptr) {
            show_teacher_menu(t);
        }
        else {
            cout << "Invalid login or password!" << endl;
        }
    }

        break;
    case 3: {
        string login, password;
        cout << "Enter login: ";
        cin >> login;

        cout << "Enter password: ";
        cin >> password;

        if (login == ADMIN_LOGIN && password == ADMIN_PASSWORD) {
            show_admin_menu();
        }
        else {
            cout << "Invalid login or password!" << endl;
        }
    }
        break;
    default:
        break;
    }
}

