#include "Library.h"
#include "User.h"

void Library::addBook(Book *book)
{
	library.push_back(book);
}

void Library::addStudent(Student *student)
{
	users.push_back(student);
}

void Library::addLibrarian(Librarian *librarian)
{
	librarians.push_back(librarian);
}

Book *Library::findByBookID(string bookID)
{
	for (auto book : library)
	{
		if (book->getBookID() == bookID)
			return book;
	}
	return nullptr;
}

Student *Library::findByStudentId(string id)
{
	for (auto student : users)
	{
		if (student->getStudentId() == id)
			return student;
	}
	return nullptr;
}

Librarian *Library::findByLibrarianId(string id)
{
	for (auto librarian : librarians)
	{
		if (librarian->getEmployeeId() == id)
			return librarian;
	}
	return nullptr;
}

void Library::displayAllBooks()
{
	cout << "All books in the library: " << endl;
	cout << "____________________________________________________" << endl;
	for (auto book : library)
	{
		cout << book->getBookID()<< " | "<<  book->getTitle() << " |Available quantity: " << book->getAvailableCopies()<< endl;
	}
	cout << "____________________________________________________" << endl;
}

void Library::borrowBook(string bookID, string studentID, bool *status)
{
	Book *book = findByBookID(bookID);
	Student *student = findByStudentId(studentID);
	if (book != nullptr && student != nullptr)
	{
		student->addBorrowedBook(book);
		checkOut(book);
		cout << "Enter borrow date(dd mm yy): ";
		int d, m, y;
		cin >> d >> m >> y;
		Date borrowDate(d, m, y); 
		book->setBorrowedDate(borrowDate);
		int due_d = d, due_m = m, due_y;
		if (due_m > 9)
		{
			due_m = m - 1;
			due_y = y + 1;
		}
		else
		{
			due_m = m + 3;
			due_y = y;
		}

		Date dueDate(due_d, due_m, due_y);
		book->setDueDate(dueDate);
		cout << "Borrowed successfully" << endl;
		*status = true;
	}
	else
	{
		cout << "Book or student not found" << endl;
		*status = false;
	}
}

void Library::returnBook(string bookID, string studentID, bool *status)
{
	Book *book = findByBookID(bookID);
	Student *student = findByStudentId(studentID);
	if (book != nullptr && student != nullptr)
	{
		checkIn(book);
		cout << "Enter return date(dd mm yy): ";
		int d, m, y;
		cin >> d >> m >> y;
		Date returnDate(d, m, y);
		bool fined = cmp(book->getDueDate(), returnDate);
		if (fined)
		{
			float fine = 50000 * (returnDate.month - book->getDueDate().month);
			student->setFine(fine);
			cout << "You are fined " << fine << " VND" << endl;
		}
		else
		{
			cout << "Thank you for returning the book on time" << endl;
			*status = true;
		}
		cout << "Returned successfully" << endl;
	}
	else
	{
		cout << "Book or student not found" << endl;
		*status = false;
	}
}


