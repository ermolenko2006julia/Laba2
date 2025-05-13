#include "file_manager.h"

void save_teachers(const vector<teacher*>& teachers)
{
    ofstream file("teachers.txt");
    int i = 0;
    for (const teacher* t : teachers) {
        file << t->get_surname() << ";" << t->get_name() << ";" << t->get_middle_name() << ";" << t->get_group() << ";" <<
            t->get_subject() << ";" << t->get_login() << ";" << t->get_password();
        if (i < teachers.size() - 1) {
            file << endl;
        }
        i++;
    }
    file.close();
}

vector<teacher*> read_teachers()
{
    vector<teacher*> teachers;

    ifstream file("teachers.txt");
    if (!file.is_open()) {
        return teachers;
    }

    while (!file.eof())
    {
        string name, surname, middle_name, subject, group, login, password;
        getline(file, surname, ';');
        getline(file, name, ';');
        getline(file, middle_name, ';');
        getline(file, group, ';');
        getline(file, subject, ';');
        getline(file, login, ';');
        getline(file, password);

        teacher* t = new teacher(name, surname, middle_name, subject, group, login, password);
        teachers.push_back(t);
    }
    file.close();

    return teachers;
}

void save_students(const vector<student*>& students)
{
    ofstream file("students.txt");

    for (student* s : students) {
        file << s->get_name() << ";" << s->get_surname() << ";" << s->get_middle_name() << ";" << s->get_group() << ";" <<
            s->get_login() << ";" << s->get_password() << ";" << s->get_marks().size() << endl;
        map<string, vector<int>> marks = s->get_marks();
        for (auto p : marks) {
            file << p.first << ";";
            for (int mark : p.second) {
                file << mark << ";";
            }
            file << endl;
        }
    }
    file.close();
}

vector<student*> read_students()
{
    ifstream file("students.txt");

    vector<student*> students;
    if (!file.is_open()) {
        return students;
    }

    while (!file.eof())
    {
        string name, surname, middle_name, group, login, password, count_subjects;
        if (!getline(file, name, ';'))
            break;
        getline(file, surname, ';');
        getline(file, middle_name, ';');
        getline(file, group, ';');
        getline(file, login, ';');
        getline(file, password, ';');
        getline(file, count_subjects);

        student* stud = new student(name, surname, middle_name, group, login, password);
        int count = stoi(count_subjects);
        for (int i = 0; i < count; i++)
        {
            string line;
            getline(file, line);
            stringstream stream(line);
            string subj;
            getline(stream, subj, ';');
            string m;
            while (getline(stream, m, ';'))
            {
                int mark = stoi(m);
                stud->add_mark(subj, mark);
            }
        }
        students.push_back(stud);
    }
    file.close();

    return students;
}
