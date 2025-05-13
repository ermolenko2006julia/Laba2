#pragma once
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class student
{
private:
	string m_name;
	string m_surname;
	string m_middle_name;
	string m_group;
	string m_login;
	string m_password;
	map<string, vector<int>> m_marks;

public:
	student(string name, string surname, string middle_name, string group, string login, string password);

	string get_name() const;
	string get_surname() const;
	string get_middle_name() const;
	string get_group() const;
	string get_login() const;
	string get_password() const;
	string get_full_name() const;
	void add_mark(string subject, int mark);
	map<string, vector<int>> get_marks() const;

	void set_name(string name);
	void set_surname(string surname);
	void set_middle_name(string middle_name);
	void set_group(string group);
	void set_login(string login);
	void set_password(string password);
};

