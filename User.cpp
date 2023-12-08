#include "User.h"

string User::getUsername() 
{
	return username;
}

string User::getPassword()
{
	return password;
}

bool User::checkPassword(string attempt)
{
	return password == attempt;
}



void User::changePassword()
{
	string newpassword;
	cout << "Enter new password: ";
	cin >> newpassword;
	password = newpassword;
	cout << "Password changed successfully!" << endl;
}

void Student::addToBookRecord(Book book)
{
	borrowedBooks.push_back(book);
}

string Student::getStudentId()
{
	return studentId;
}



void Student::borrowBook(Library *lib)
{
	string bookId;
	cout << "Enter book id: ";
	cin >> bookId;
	Book result;
	bool find_result = lib->find_by_id(bookId, &result);
	if (find_result)
	{
		if (result.available_copies > 0)
		{
			cout << "Enter date borrow(dd mm yy): ";
			cin >> result.borrowedDate.date >> result.borrowedDate.month >> result.borrowedDate.year;
			result.dueDate.date = result.borrowedDate.date;
			if(result.borrowedDate.month > 9)
			{
				result.dueDate.year = result.borrowedDate.year + 1;
				result.dueDate.month = result.borrowedDate.month - 9;
			}
			else
			{
				result.dueDate.month = result.borrowedDate.month + 3;
				result.dueDate.year = result.borrowedDate.year;
			} 
			addToBookRecord(result);
			result.check_out();
			cout << "Book borrowed successfully!" << endl;
		}
		else
		{
			cout << "Book not available!" << endl;
		}
	}
	else
	{
		cout << "Book not found!" << endl;
	}
}

void Student::returnBook(Library *lib)
{
string bookId;
	cout << "Enter book id: ";
	cin >> bookId;
	Book result;
	bool find_result = lib->find_by_id(bookId, &result);
	if(find_result)
	{
		for (int i = 0; i < borrowedBooks.size(); i++)
		{
			if (borrowedBooks[i].bookID == bookId)
			{
				Date today;
				cout << "Enter date return(dd mm yy): ";
				cin >> today.date >> today.month >> today.year;
				if (today.cmp(today, result.dueDate))
				{
					cout << "You are late!" << endl;
					cout << "You have to pay " << (result.dueDate.month - result.dueDate.month) * 50000 << " VND" << endl;
				}
				borrowedBooks.erase(borrowedBooks.begin() + i);
				result.borrowedDate = Date(0, 0, 0);
				result.dueDate = Date(0, 0, 0);
				result.check_in();
				cout << "Book returned successfully!" << endl;
				return;
			}
		}
		cout << "You didn't borrow this book!" << endl;
	}
	else
	{
		cout << "Book not found!" << endl;
	}
}

void Librarian::addBookToLibrary(Library *lib)
{
	string title, author, bookId;
	int quant = 0;
	cout << "Enter title: ";
	cin >> title;
	cout << "Enter author: ";
	cin >> author;
	cout << "Enter book id: ";
	getline(cin, bookId);
	cout << "Enter quantity: ";
	cin >> quant;
	Book newBook(title, author, bookId, quant);
	lib->add_book(newBook);
}

void Librarian::removeBookFromLibrary(Library *lib)
{
	string bookId;
	cout << "Enter book id: ";
	cin >> bookId;
	lib->remove_book(bookId);
}

void Librarian::deleteStudent(Library* lib)
{
	string studentId;
	cout << "Enter student id: ";
	cin >> studentId;
	for (int i = 0; i < lib->users.size(); i++)
	{
		if (lib->users[i].getStudentId() == studentId)
		{
			lib->users.erase(lib->users.begin() + i);
			cout << "Student removed successfully!" << endl;
			return;
		}
	}
	cout << "Student not found!" << endl;
}

void Librarian::addStudent(Student st, Library * lib)
{
	Student newStudent;
	newStudent.registerUser();
	lib->users.push_back(newStudent);
}