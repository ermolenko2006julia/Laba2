#include "teacher.h"

teacher::teacher(string name, string surname, string middle_name, string subject, string group, string login, string password)
{
	m_name = name;
	m_surname = surname;
	m_middle_name = middle_name;
	m_subject = subject;
	m_group = group;
	m_login = login;
	m_password = password;
}

string teacher::get_name() const
{
	return m_name;
}

string teacher::get_surname() const
{
	return m_surname;
}

string teacher::get_middle_name() const
{
	return m_middle_name;
}

string teacher::get_subject() const
{
	return m_subject;
}

string teacher::get_group() const
{
	return m_group;
}

string teacher::get_login() const
{
	return m_login;
}

string teacher::get_password() const
{
	return m_password;
}

string teacher::get_full_name() const
{
	return get_surname() + " " + get_name() + " " + get_middle_name();
}

void teacher::set_name(string name)
{
	m_name = name;
}

void teacher::set_surname(string surname)
{
	m_surname = surname;
}

void teacher::set_middle_name(string middle_name)
{
	m_middle_name = middle_name;
}

void teacher::set_subject(string subject)
{
	m_subject = subject;
}

void teacher::set_group(string group)
{
	m_group = group;
}

void teacher::set_login(string login)
{
	m_login = login;
}

void teacher::set_password(string password)
{
	m_password = password;
}
