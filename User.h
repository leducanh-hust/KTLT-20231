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

	User (string name, string username, string password, Date birthDate)
		: name(name), username(username), password(password), birthDate(birthDate) {}

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
	vector<Book> borrowedBooks;
public:
	Student(string username, string password,string name, Date birth, string studentId)
		: User(username, password, name, birth), studentId(studentId) {}
	
	void addToBookRecord(Book book);

	string getStudentId() const;

	void borrowBook(Library *lib);
};

class Librarian : public User
{
private:
	string employeeId;
	int floor;
public:
	Librarian(string name, string username, string password, Date birth, string employeeId, int floor)
		: User(name, username, password, birth), employeeId(employeeId), floor(floor) {}

	void addStudent(Library *lib);
	void deleteStudent(Library * lib);

	void addBookToLibrary(Library *lib);
	void removeBookFromLibrary(Library *lib);
};

#endif // !USER_H