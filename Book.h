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
	Date() {}
	Date(int d, int m, int y) : date(d), month(m), year(y) {}
	friend bool cmp(Date x, Date y)
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
private:
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
public:

	//Methods

	// Default constructor
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

	//Getters
	string getBookID() { return bookID; }
	string getISBN() { return ISBN; }
	string getTitle() { return title; }
	string getAuthor() { return author; }
	Date getDatePublished() { return datePublished; }
	Date getBorrowedDate() { return borrowedDate; }
	Date getDueDate() { return dueDate; }
	string getPublisher() { return publisher; }
	int getQuantity() { return quantity; }
	int getAvailableCopies() { return available_copies; }
	vector<string> getStatus() { return status; }
	vector<string> getGenre() { return genre; }

	//Setters
	void setBookID(string id) { bookID = id; }
	void setISBN(string isbn) { ISBN = isbn; }
	void setTitle(string t) { title = t; }
	void setAuthor(string a) { author = a; }
	void setDatePublished(Date date) { datePublished = date; }
	void setBorrowedDate(Date date) { borrowedDate = date; }
	void setDueDate(Date date) { dueDate = date; }
	void setPublisher(string p) { publisher = p; }
	void setQuantity(int q) { quantity = q; }
	void setAvailableCopies(int a) { available_copies = a; }
	void setStatus(vector<string> s) { status = s; }
	void setGenre(vector<string> g) { genre = g; }


	Book(string title, string author, string bookId, int quant)
		: title(title), author(author), bookID(bookId), quantity(quant), available_copies(quant)
	{
		status.push_back("Available");
		borrowedDate = Date(0, 0, 0);
		dueDate = Date(0, 0, 0);
	}

	//Display info of a book
	void displayInfo()
	{
		cout << "Book ID: " << bookID << endl;
		cout << "Title: " << title << endl;
		cout << "Author: " << author << endl;
		cout << "Date Published: " << datePublished << endl;
		cout << "Publisher: " << publisher << endl;
		cout << "Quantity: " << quantity << endl;
		cout << "Available Copies: " << available_copies << endl;
		cout << "Status: " << status[0] << endl;
		cout << "Genre: ";
		for (auto g : genre)
			cout << g << " ";
		cout << endl;
	}

	friend void checkIn(Book *book)
	{
		book->available_copies++;
		book->status[0] = "Available";
	}
	friend void checkOut(Book *book)
	{
		book->available_copies--;
		book->status[0] = "CheckOut";
	}
	
};

#endif // !BOOK_H

