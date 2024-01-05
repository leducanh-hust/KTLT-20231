#include "User.h"

string Student::getStudentId()
{
    return studentId;
}

string Student::getStudentClass()
{
    return studentClass;
}

string Student::getStudentSchool()
{
	return studentSchool;
}

void Student::setStudentId(string id)
{
	studentId = id;
}

void Student::setStudentClass(string studentClass)
{
	studentClass = studentClass;
}

void Student::setStudentSchool(string school)
{
	studentSchool = school;
}

string Librarian::getEmployeeId()
{
	return employeeId;
}

string User::getUsername()
{
    return username;
}
string User::getPassword()
{
	return password;
}

bool User::checkPassword(std::string attempt)
{
    return attempt == password;
}
