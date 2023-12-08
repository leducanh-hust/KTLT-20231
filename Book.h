#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include<vector>

using namespace std;

class Date
{
public:
	int date;
	int month;
	int year;
	
	//Compare dates: 1 if x is the day before, 0 if y is the day before 
	Date() = default;
	Date(int d, int m, int y) : date(d), month(m), year(y) {}
	bool cmp(Date x, Date y)
	{
		if(x.year < y.year)
			return 1;
		else if(x.year == y.year)
		{
			if(x.month < y.month)
				return 1;
			else if(x.month == y.month)
			{
				if(x.date < y.date)
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	friend ostream& operator<<(ostream& out, const Date& date)
	{
		out << date.date << "/" << date.month << "/" << date.year;
		return out;
	}
};

string Genre[] =  { "Fiction" , "Science", "History", "Novel", "Oneshot", "Series" };
string Status[] = { "Available" , "Checkin", "Checkout" };


//A single book item
class Book
{
public:
	string bookID; // key, unique
	string ISBN; // International Standard Book Number
	string title;
	string author;
	Date datePublished;
	Date borrowedDate;
	Date dueDate;
	string publisher;
	int quantity;
	int available_copies; // quantity - number of books not checked out
	vector<string> status;
	vector<string> genre;
	//Methods
	Book() {}
	// Copy constructor 
	Book(Book &book)
	{
		bookID = book.bookID;
		ISBN = book.ISBN;
		title = book.title;
		author = book.author;
		datePublished = book.datePublished;
		borrowedDate = book.borrowedDate;
		dueDate = book.dueDate;
		publisher = book.publisher;
		quantity = book.quantity;
		available_copies = book.available_copies;
		status = book.status;
		genre = book.genre;
	}

	Book(string title, string author, string bookId, int quant)
		: title(title), author(author), bookID(bookId), quantity(quant), available_copies(quant)
	{
		status.push_back("Available");
		status.push_back("Checkin");
		borrowedDate = Date(0, 0, 0);
		dueDate = Date(0, 0, 0);
		available_copies = quantity;
	}



	void check_in();

	void check_out();
	
};

#endif // !BOOK_H

