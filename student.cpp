#include "student.h"

student::student(string name, string surname, string middle_name, string group, string login, string password)
{
	m_name = name;
	m_surname = surname;
	m_middle_name = middle_name;
	m_group = group;
	m_login = login;
	m_password = password;
}

string student::get_name() const
{
	return m_name;
}

string student::get_surname() const
{
	return m_surname;
}

string student::get_middle_name() const
{
	return m_middle_name;
}

string student::get_group() const
{
	return m_group;
}

string student::get_login() const
{
	return m_login;
}

string student::get_password() const
{
	return m_password;
}

string student::get_full_name() const
{
	return get_surname() + " " + get_name() + " " + get_middle_name();
}

void student::add_mark(string subject, int mark)
{
	m_marks[subject].push_back(mark);
}

map<string, vector<int>> student::get_marks() const
{
	return m_marks;
}

void student::set_name(string name)
{
	m_name = name;
}

void student::set_surname(string surname)
{
	m_surname = surname;
}

void student::set_middle_name(string middle_name)
{
	m_middle_name = middle_name;
}

void student::set_group(string group)
{
	m_group = group;
}

void student::set_login(string login)
{
	m_login = login;
}

void student::set_password(string password)
{
	m_password = password;
}
