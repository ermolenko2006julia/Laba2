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
