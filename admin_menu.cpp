#include "admin_menu.h"

void show_admin_menu()
{
	int choice;

	do
	{
		cout << ("---------------------------------------") << endl;
		cout << "1. Workplace teachers" << endl;
		cout << "2. Workplace students" << endl;
		cout << "0. Exit" << endl;
		cout << ("---------------------------------------\n") << endl;

		cin >> choice;

		if (choice == 1) {
			show_teachers_menu();
		}
		else if (choice == 2) {
			show_students_menu();
		}
	} 
	while (choice != 0);
}

void show_teachers_menu()
{
	vector<teacher*> teachers = read_teachers();

	int choice;

	do
	{
		cout << ("---------------------------------------") << endl;
		cout << "1. Add" << endl;
		cout << "2. Show" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Edit" << endl;
		cout << "0. Exit" << endl;
		cout << ("---------------------------------------\n") << endl;

		cin >> choice;

		if (choice == 1) {
			teacher* t = create_teacher();
			teachers.push_back(t);
			save_teachers(teachers);
		}
		else if (choice == 2) {
			show_teachers(teachers);
		} 
		else if (choice == 3) {
			show_teachers(teachers);
			remove_teacher(teachers);
			save_teachers(teachers);
		}
		else if (choice == 4) {
			show_teachers(teachers);
			edit_teacher(teachers);
			save_teachers(teachers);
		}
	} while (choice != 0);
}

teacher* create_teacher()
{
	string name, surname, middle_name, subject, group, login, password;

	cout << "Enter name: ";
	cin >> name;

	cout << "Enter surname: ";
	cin >> surname;

	cout << "Enter middle name: ";
	cin >> middle_name;

	cout << "Enter subject: ";
	cin >> subject;

	cout << "Enter group: ";
	cin >> group;

	cout << "Enter login: ";
	cin >> login;

	cout << "Enter password: ";
	cin >> password;


	return new teacher(name, surname, middle_name, subject, group, login, password);
}

void show_teachers(const vector<teacher*>& teachers)
{
	cout << left;
	cout << setw(10) << "Number " << setw(35) << "Full name " << setw(15) << "Subject " << setw(15) << "Group " << setw(15) << "Login " << setw(15) << "Password " << endl;
	int i = 1;
	for (teacher* t : teachers) {
		cout << setw(10) << i << setw(35) << t->get_full_name() << setw(15) << t->get_subject() << setw(15) << t->get_group() << setw(15) <<
			t->get_login() << setw(15) << t->get_password() << endl;
		i++;
	}
	cout << endl;
}

void remove_teacher(vector<teacher*>& teachers)
{
	size_t index;
	cout << "Enter number: ";
	cin >> index;

	if (index > 0 && index <= teachers.size()) {
		teachers.erase(teachers.begin() + (index - 1));
	}
	else {
		cout << "Invalid number!" << endl;
	}
}

void edit_teacher(vector<teacher*>& teachers)
{
	size_t index;
	cout << "Enter number: ";
	cin >> index;

	if (index > 0 && index <= teachers.size()) {
		teacher* t = teachers[index - 1];

		int choice;
		do
		{
			cout << ("---------------------------------------") << endl;
			cout << "What should I edit?" << endl;
			cout << "1. Name" << endl;
			cout << "2. Surname" << endl;
			cout << "3. Middle name" << endl;
			cout << "4. Group" << endl;
			cout << "5. Subject" << endl;
			cout << "6. Login" << endl;
			cout << "7. Password" << endl;
			cout << "0. Exit" << endl;
			cout << ("---------------------------------------\n") << endl;

			cin >> choice;

			if (choice == 1) {
				string name;
				cout << "Enter new name: ";
				cin >> name;

				t->set_name(name);
			}
			else if (choice == 2) {
				string surname;
				cout << "Enter new surname: ";
				cin >> surname;

				t->set_surname(surname);
			}
			else if (choice == 3) {
				string middle_name;
				cout << "Enter new middle name: ";
				cin >> middle_name;

				t->set_middle_name(middle_name);
			}
			else if (choice == 4) {
				string group;
				cout << "Enter new group: ";
				cin >> group;

				t->set_group(group);
			}
			else if (choice == 5) {
				string subject;
				cout << "Enter new subject: ";
				cin >> subject;

				t->set_subject(subject);
			}
			else if (choice == 6) {
				string login;
				cout << "Enter new login: ";
				cin >> login;

				t->set_login(login);
			}
			else if (choice == 7) {
				string password;
				cout << "Enter new password: ";
				cin >> password;

				t->set_password(password);
			}
		} 
		while (choice != 0);
	}
	else {
		cout << "Invalid number!" << endl;
	}
}

void show_students_menu()
{
	vector<student*> students = read_students();

	int choice;

	do
	{
		cout << ("---------------------------------------") << endl;
		cout << "1. Add" << endl;
		cout << "2. Show" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Edit" << endl;
		cout << "0. Exit" << endl;
		cout << ("---------------------------------------\n") << endl;

		cin >> choice;

		if (choice == 1) {
			student* t = create_student();
			students.push_back(t);
			save_students(students);
		}
		else if (choice == 2) {
			show_students(students);
		}
		else if (choice == 3) {
			show_students(students);
			remove_student(students);
			save_students(students);
		}
		else if (choice == 4) {
			show_students(students);
			edit_student(students);
			save_students(students);
		}
	} while (choice != 0);
}

student* create_student()
{
	string name, surname, middle_name, group, login, password;

	cout << "Enter name: ";
	cin >> name;

	cout << "Enter surname: ";
	cin >> surname;

	cout << "Enter middle name: ";
	cin >> middle_name;

	cout << "Enter group: ";
	cin >> group;

	cout << "Enter login: ";
	cin >> login;

	cout << "Enter password: ";
	cin >> password;


	return new student(name, surname, middle_name, group, login, password);
}

void show_students(const vector<student*>& students)
{
	cout << left;
	cout << setw(10) << "Number" << setw(35) << "Full name" << setw(15) << setw(15) << "Group" << setw(15) << "Login" << setw(15) << "Password" << endl;
	int i = 1;
	for (student* t : students) {
		cout << setw(10) << i << setw(35) << t->get_full_name() << setw(15) << t->get_group() << setw(15) <<
			t->get_login() << setw(15) << t->get_password() << endl;
		i++;
	}
	cout << endl;
}

void remove_student(vector<student*>& students)
{
	size_t index;
	cout << "Enter number: ";
	cin >> index;

	if (index > 0 && index <= students.size()) {
		students.erase(students.begin() + (index - 1));
	}
	else {
		cout << "Invalid number!" << endl;
	}
}

void edit_student(vector<student*>& students)
{
	size_t index;
	cout << "Enter number: ";
	cin >> index;

	if (index > 0 && index <= students.size()) {
		student* t = students[index - 1];

		int choice;
		do
		{
			cout << ("---------------------------------------") << endl;
			cout << "What should I edit?" << endl;
			cout << "1. Name" << endl;
			cout << "2. Surname" << endl;
			cout << "3. Middle name" << endl;
			cout << "4. Group" << endl;
			cout << "5. Login" << endl;
			cout << "6. Password" << endl;
			cout << "0. Exit" << endl;
			cout << ("---------------------------------------\n") << endl;

			cin >> choice;

			if (choice == 1) {
				string name;
				cout << "Enter new name: ";
				cin >> name;

				t->set_name(name);
			}
			else if (choice == 2) {
				string surname;
				cout << "Enter new surname ";
				cin >> surname;

				t->set_surname(surname);
			}
			else if (choice == 3) {
				string middle_name;
				cout << "Enter new middle name: ";
				cin >> middle_name;

				t->set_middle_name(middle_name);
			}
			else if (choice == 4) {
				string group;
				cout << "Enter new group: ";
				cin >> group;

				t->set_group(group);
			}
			else if (choice == 5) {
				string login;
				cout << "Enter new login: ";
				cin >> login;

				t->set_login(login);
			}
			else if (choice == 6) {
				string password;
				cout << "Enter new password: ";
				cin >> password;

				t->set_password(password);
			}
		} while (choice != 0);
	}
	else {
		cout << "Invalid number!" << endl;
	}
}
