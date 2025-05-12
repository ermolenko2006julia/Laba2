#pragma once
#include <iostream>
using namespace std;

class teacher
{
private:
	string m_name;
	string m_surname;
	string m_middle_name;
	string m_subject;
	string m_group;
	string m_login;
	string m_password;

public:
	teacher(string name, string surname, string middle_name, string subject, string group, string login, string password);

	string get_name() const;
	string get_surname() const;
	string get_middle_name() const;
	string get_subject() const;
	string get_group() const;
	string get_login() const;
	string get_password() const;

};

