#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "User.h"
#include <vector>

using namespace std;

class Student;
class Librarian;

class Library
{
public:
	vector<Book> library;
	vector<Student> users;
	vector<Librarian> librarians;

	Library() {}

	int getNumberOfBooks();
	int getNumberOfUsers();

	bool find_by_id(string id, Book *result);
	// bool find_by_author(string author, vector<Book> &result);
	// bool find_by_title(string title, vector<Book> &result);
	// bool find_by_genre(string genre, vector<Book> &result);

	void add_book(Book book)
	{
		library.push_back(book);
	}
	void remove_book(string id);
};
#endif // !LIBRARY_H
