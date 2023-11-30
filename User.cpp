#include "User.h"
#include "Library.h"

string User::getUsername() const
{
	return username;
}

string User::getPassword() const
{
	return password;
}

bool User::checkPassword(string attempt) const
{
	return password == attempt;
}

void User::displayInfo() const
{
	cout << "Username: " << username << endl;
	cout << "Password: " << password << endl;
	cout << "Name: " << name << endl;
	cout << "Date of Birth: " << birthDate << endl;
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

string Student::getStudentId() const
{
	return studentId;
}

void Student::borrowBook(Library* lib)
{
	string bookId;
	cout << "Enter book id: ";
	cin >> bookId;
	Book result;
	bool find_result = lib->find_by_id(bookId, result);
	if (find_result)
	{
		if (result.quantity > 0)
		{
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

void Librarian::addStudent(Library *lib)
{
	string name, username, password, studentId;
	Date birth;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	cout << "Enter date of birth: ";
	cin >> birth.date >> birth.month >> birth.year;
	cout << "Enter student ID: ";
	cin >> studentId;
	Student newStudent(username, password, name, birth, studentId);
	lib->users.push_back(newStudent);
}

void Librarian::addBookToLibrary(Library* lib)
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
