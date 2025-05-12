#include "teacher_menu.h"

teacher* find_teacher(const vector<teacher*>& teachers, string login, string password)
{
    for (teacher* t : teachers) {
        if (t->get_login() == login && t->get_password() == password) {
            return t;
        }
    }
    return nullptr;
}

void show_teacher_menu(teacher* t)
{
    vector<student*> all_students = read_students();
    vector <student*> students;
    for (student* stud : all_students) {
        if (stud->get_group() == t->get_group()) {
            students.push_back(stud);
        }
    }

    int choice;

    do
    {
		cout << ("---------------------------------------") << endl;
        cout << "1. Show all students" << endl;
        cout << "2. Add grade" << endl;
        cout << "3. Show all grades" << endl;
        cout << "0. Exit" << endl;
		cout << ("---------------------------------------\n") << endl;

        cin >> choice;

        if (choice == 1) {
            show_students(students);
        }
        else if (choice == 2) {
            show_students(students);
            add_mark(t->get_subject(), students);
            save_students(all_students);
        }
        else if (choice == 3) {
            show_students(students);
            show_marks(t->get_subject(), students);
        }

    } while (choice != 0);
}

void add_mark(string subject, const vector<student*>& students)
{
    int index;
    cout << "Enter the student's number: ";
    cin >> index;

    if (index >= 1 && index <= students.size()) {
        student* stud = students[index - 1];
        int mark;
        cout << "Enter grade: ";
        cin >> mark;

        stud->add_mark(subject, mark);
    }
    else {
        cout << "Invalid number!" << endl;
    }
}

void show_marks(string subject, const vector<student*>& students)
{
    int index;
    cout << "Enter the student's number: ";
    cin >> index;

    if (index >= 1 && index <= students.size()) {
        student* stud = students[index - 1];
        map<string, vector<int>> marks = stud->get_marks();
        auto p = marks.find(subject);
        if (p != marks.end()) {
            vector<int> v = marks[subject];
            cout << "Grades: ";
            for (int mark : v) {
                cout << mark << " ";
            }
            cout << endl;
        }
        else {
            cout << "Nothing was found" << endl;
        }

    }
    else {
        cout << "Invalid number!" << endl;
    }
}
