#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Book.h"
#include <limits>
#include <fstream>
#include <stdexcept>

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
	vector<Book *> getBorrowedBooks() { return borrowedBooks; }
	float getFine() { return fine; }

	// Setters
	void setStudentId(string id);
	void setStudentClass(string studentClass);
	void setStudentSchool(string school);
	void addBorrowedBook(Book *book) { borrowedBooks.push_back(book); }
	void setFine(float f) { fine = f; }

	void registerUser() override
	{
		// Call the base class registerUser to get the basic information
		User::registerUser();

		// Additional information for the Student class
		string id, studentClass, school;
		cout << "Enter your student ID: ";
		getline(cin, id);
		fstream file;
		file.open("C:/Users/PC/Desktop/testprj-code./LibrarianAccount.txt", ios::out | ios::app);
		if (file.is_open())
		{
			file << "{" << getUsername() << "," << hashPassword(getPassword()) << ";" << id << "};" << endl;
			file.close();
		}
		else
		{
			cerr << "Error opening file." << endl;
		}
		cout << "Enter your class: ";
		getline(cin, studentClass);
		cout << "Enter your school: ";
		getline(cin, school);

		// Set the additional information for the Student
		studentId = id;
		this->studentClass = studentClass;
		studentSchool = school;
	}

	void StudentLogin()
	{
		string s_username, s_password;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
		cout << "Enter your username: ";
		getline(cin, s_username);
		cout << "Enter your password: ";
		getline(cin, s_password);
		ifstream file("C:/Users/PC/Desktop/testprj-code./StudentAccount.txt");
		if (file.is_open())
		{
			string usrname, passw, line;
			while (getline(file, line))
			{
				size_t pos = line.find(",");
				usrname = line.substr(1, pos - 1);
				size_t pos2 = line.find(";");
				passw = line.substr(pos + 1, pos2 - pos - 1);
				// cerr << usrname << ";" << passw << endl;
				if (usrname == s_username && passw == hashPassword(s_password))
				{
					cout << "Login successfully!" << endl;
					return;
				}
			}
			cout << "Wrong username or account not exist!" << endl;
			cout << "Please register first if youn don't have an account!" << endl;
			file.close();
		}
		else
		{
			cerr << "Error opening file." << endl;
		}
	}
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

		// Write to file
		ofstream file("C:/Users/PC/Desktop/testprj-code./LibrarianAccount.txt");
		if (file.is_open())
		{
			file << "{" << getUsername() << "," << hashPassword(getPassword()) << ";" << endl;
			// file << id << ".";
			file.close();
		}
		else
		{
			cerr << "Error opening file." << endl;
		}

		// Set the additional information for the Librarian
		employeeId = id;
	}
};

#endif // !USER_H