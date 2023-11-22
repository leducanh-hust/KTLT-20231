#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string> 
#include "Source.cpp"
#include "Book.h"
using namespace std;

class User
{
private:
	string name;
	string username;
	string password;
	Date birthDate;
public:
	User() = default;
	User(string, string, string, Date);
	string getUsername() const;
	string getPassword() const;
	bool checkPassword(std::string attempt) const;
	virtual void displayInfo() const;
	void changePassword();
};

class Student : public User
{
private:
	string studentId;
	string studentClass;
	string studentSchool;
public:
	Student(string username, string password,string name, Date birth, string studentId)
		: User(username, password, name, birth), studentId(studentId) {}
	void borrowBook();
	void returnBook();
};

class Librarian : public User
{
private:
	string employeeId;
	int floor;
public:
	Librarian(string name, string username, string password, Date birth, string employeeId, int floor)
		: User(name, username, password, birth), employeeId(employeeId), floor(floor) {}
	void addStudent();
	void deleteStudent();
	void addBook();
	void removeBook();
};

#endif // !USER_H