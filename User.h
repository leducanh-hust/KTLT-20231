#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Book.h"
#include <limits>
#include <fstream>
#include <stdexcept>
//#include "FileHandling.cpp"

class Library;

using namespace std;

string hashPassword(const string &password)
{
	string hashedPassword = password;
	for (int i = 0; i < password.length(); i++)
	{
		hashedPassword[i] = password[i] + 5;
	}
	return hashedPassword;
}

class User
{
private:
	string name;
	string username;
	string password;

public:
	User() {}

	User(string name, string username, string password)
		: name(name), username(username), password(password) {}

	string getUsername();
	string getPassword();
	string getFullName() {return name;}

	void setUsername(string username);
	void setPassword(string password);
	void setName(string name) { this->name = name; }

	bool checkPassword(std::string attempt);
	virtual void displayInfo()
	{
		cout << "Username: " << username << endl;
		cout << "Password: " << password << endl;
		cout << "Name: " << name << endl;
	}
	virtual void registerUser()
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

		cout << "Enter your name: ";
		if (!getline(cin, name))
		{
			cerr << "Error reading name." << endl;
		}

		cout << "Enter your username: ";
		if (!getline(cin, username))
		{
			cerr << "Error reading username." << endl;
		}

		cout << "Enter your password: ";
		if (!getline(cin, password))
		{
			cerr << "Error reading password." << endl;
		}
	}
};

class Student : public User
{
private:
	string studentId;
	string studentClass;
	string studentSchool;
	vector<Book *> borrowedBooks;
	float fine = 0;

public:
	Student(string username, string password, string name, string studentId)
		: User(username, password, name), studentId(studentId) {}

	Student() {}

	Student(string id) : studentId(id) {}

	// Getters
	string getStudentId();
	string getStudentClass();
	string getStudentSchool();
	vector<Book *> getBorrowedBooks()
	{
		return borrowedBooks;
	}
	float getFine() { return fine; }

	// Setters
	void setStudentId(string id);
	void setStudentClass(string studentClass);
	void setStudentSchool(string school);
	void addBorrowedBook(Book *book); 
	void setFine(float f) { fine = f; }

	void registerUser() override;

	void StudentLogin();
};

class Librarian : public User
{
private:
	string employeeId;

public:
	Librarian(string name, string username, string password, string employeeId)
		: User(name, username, password), employeeId(employeeId) {}

	Librarian() {}

	// Getters
	string getEmployeeId();

	void registerUser() override
	{
		// Call the base class registerUser to get the basic information
		User::registerUser();

		// Additional information for the Librarian class
		string id;
		cout << "Enter your employee ID: ";
		getline(cin, id);
		employeeId = id;
	}
};

#endif // !USER_H