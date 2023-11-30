#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include<vector>

using namespace std;

enum Genre { Fiction, Science, History, Novel, Oneshot, Series };
enum BookStatus { Available, Checkin, Checkout };

//A single book item
class Book
{
public:
	string bookID; // key, unique
	string ISBN; // International Standard Book Number
	string title;
	string author;
	Date datePublished;
	string publisher;
	int quantity;
	int available_copies; // quantity - number of books not checked out
	vector<BookStatus> status;
	vector<Genre> genre;
	//Methods
	Book() = default;

	Book(string title, string author, string bookId, int quant)
		: title(title), author(author), bookID(bookId), quantity(quant), available_copies(quant)
	{
		status.push_back(Available);
		status.push_back(Checkin);
	}

	void check_in();

	void check_out();
	
};

#endif // !BOOK_H

