#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "User.h"
#include <vector>
#include<fstream>

using namespace std;

class Student;
class Librarian;

class Library
{
private:
	vector<Book*> library;
	vector<Student*> users;
	vector<Librarian*> librarians;
public:
	Library() {}

	void get()
	{
		int nite = 0;
	}

	void addBook(Book* book);
	void removeBook(Book *book)
	{
		for (int i = 0; i < library.size(); i++)
		{
			if (library[i] == book)
			{
				library.erase(library.begin() + i);
				break;
			}
		}
	}
	void addStudent(Student* student);
	void addLibrarian(Librarian* librarian);

	Book* findByBookID(string bookID);
	Student* findByStudentId(string id);
	Librarian* findByLibrarianId(string id);

	void displayAllBooks();

	void borrowBook(string bookID, string studentID, bool *status);
	void returnBook(string bookID, string studentID, bool *status);

};
#endif // !LIBRARY_H
