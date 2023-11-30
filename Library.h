#pragma once
#include"Book.h"
#include"User.h"
#include<vector>
class Library
{
public:
	vector<Book> library;
	vector<Student> users;
	Library() = default;

	int getNumebrOfBooks() const;
	int getNumberOfUsers() const;

	bool find_by_id(string id, Book &result);
	bool find_by_author(string author, vector<Book> &result);
	bool find_by_title(string title, vector<Book> &result);
	bool find_by_genre(Genre genre, vector<Book> &result);


	void add_book(Book book);
	void remove_book(string id);



};

