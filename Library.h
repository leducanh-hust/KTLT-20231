#pragma once
#include"Book.h"
#include<vector>
class Library
{
public:
	vector<Book> library;
	Library() = default;
	void find_by_id(string id, Book &result);
	void find_by_author(string author, vector<Book> &result);
	void find_by_title(string title, vector<Book> &result);
	void find_by_genre(Genre genre, vector<Book> &result);
	void find_by_year(int year, vector<Book> &result);
};

