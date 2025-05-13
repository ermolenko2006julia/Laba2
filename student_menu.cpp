#include "student_menu.h"

student* find_student(const vector<student*>& students, string login, string password)
{
    for (student* stud : students) {
        if (stud->get_login() == login && stud->get_password() == password) {
            return stud;
        }
    }
    return nullptr;
}

void show_student_menu(student* stud)
{
    int choice;
    do
    {
		cout << ("---------------------------------------") << endl;
        cout << "1. Show academic performance" << endl;
        cout << "2. Output grades for a given subject" << endl;
        cout << "0. Exit" << endl;
		cout << ("---------------------------------------\n") << endl;

        cin >> choice;
        if (choice == 1) {
            show_all_marks(stud);
        }
        else if (choice == 2) {
            string subj;
            cout << "Enter name name of the school subject: ";
            cin >> subj;

            show_marks_by_subject(stud, subj);
        }
    } 
    while (choice != 0);
}

void show_all_marks(student* stud)
{
    map<string, vector<int>> marks = stud->get_marks();
    for (auto p : marks) {
        cout << p.first << ": ";
        for (int mark : p.second) {
            cout << mark << " ";
        }
        cout << endl;
    }
}

void show_marks_by_subject(student* stud, string subject)
{
    auto marks = stud->get_marks();
    auto res = marks.find(subject);
    if (res != marks.end()) {
        for (int mark : res->second) {
            cout << mark << " ";
        }
        cout << endl;
    }
    else {
        cout << "Nothing was found" << endl;
    }
}
