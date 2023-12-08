#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Book.h"
#include "Library.h"

using namespace std;

class User
{
private:
	string name;
	string username;
	string password;
	Date birthDate;

public:
	User() {}

	User(string name, string username, string password, Date birthDate)
		: name(name), username(username), password(password), birthDate(birthDate) {}

	string getUsername();
	string getPassword();

	bool checkPassword(std::string attempt);
	virtual void displayInfo()
	{
		cout << "Username: " << username << endl;
		cout << "Password: " << password << endl;
		cout << "Name: " << name << endl;
		cout << "Date of Birth: " << birthDate << endl;
	}
	void changePassword();
	virtual void registerUser()
	{
		cout << "Enter your name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter your username: ";
		getline(cin, username);
		cout << "Enter your password: ";
		getline(cin, password);
		cout << "Enter your birth date: ";
		cin >> birthDate.date >> birthDate.month >> birthDate.year;
	}
};

class Student : public User
{
private:
	string studentId;
	string studentClass;
	string studentSchool;
	vector<Book> borrowedBooks;

public:
	Student(string username, string password, string name, Date birth, string studentId)
		: User(username, password, name, birth), studentId(studentId) {}

	Student() {}

	void addToBookRecord(Book book);

	string getStudentId();

	void registerUser() override
	{
		// Call the base class registerUser to get the basic information
		User::registerUser();

		// Additional information for the Student class
		string id, studentClass, school;

		cout << "Enter your student ID: ";
		cin.ignore();
		getline(cin, id);
		cout << "Enter your class: ";
		getline(cin, studentClass);
		cout << "Enter your school: ";
		getline(cin, school);

		// Set the additional information for the Student
		studentId = id;
		studentClass = studentClass;
		studentSchool = school;
	}

	void borrowBook(Library *lib);
	void returnBook(Library *lib);
};

class Librarian : public User
{
private:
	string employeeId;

public:
	Librarian(string name, string username, string password, Date birth, string employeeId)
		: User(name, username, password, birth), employeeId(employeeId) {}

	Librarian() {}

	void registerUser() override
	{
		// Call the base class registerUser to get the basic information
		User::registerUser();

		// Additional information for the Librarian class
		string id;

		cout << "Enter your employee ID: ";
		cin.ignore();
		getline(cin, id);

		// Set the additional information for the Librarian
		employeeId = id;
	}

	void addStudent(Student st, Library *lib);
	void deleteStudent(Library *lib);

	void addBookToLibrary(Library *lib);
	void removeBookFromLibrary(Library *lib);
};

#endif // !USER_H