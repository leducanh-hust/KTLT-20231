#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include<vector>

using namespace std;

enum Genre { Fiction, Science, History, Novel, Oneshot, Series };
enum BookStatus { Available, Returned, Lost };

//A single book item
class Book
{
public:
	string ISBN; //International Standard Book Number
	string bookID;
	string title;
	string author;
	Date datePublished;
	string publisher;
	int quantity;
	vector<BookStatus> status;
	vector<Genre> genre;

	//Methods
	Book() = default;

	Book(string title, string author, string bookId, int quant)
		: title(title), author(author), bookID(bookId), quantity(quant)
	{
		status.push_back(Available);
	}
	
};

#endif // !BOOK_H

