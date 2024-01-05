#include "User.cpp"
#include "Book.cpp"
#include "Library.cpp"
#include <iostream>
#include <string>
#include <stdint.h>
#include <ctime>
#include <conio.h>
using namespace std;

void Menu();
void StudentMenu();
void LibrarianMenu();

void Delay(int sec)
{
	time_t start = time(0);
	time_t end = start + sec;
	while (start < end)
	{
		start = time(0);
	}
}

void checkInputIsNumber(int &choice)
{
	string UserInput = "";
	while (true)
	{
		getline(cin, UserInput);
		if (UserInput.length() == 1 && isdigit(UserInput[0]))
		{
			choice = stoi(UserInput);
			break;
		}
		cout << "Invalid input, please enter again: ";
	}
}

int main()
{
	Library Time;

	Book *book1 = new Book("Lord of The Ring", "J.R.R Tolkien", "1001", 14);
	Book *book2 = new Book("Harry Potter", "J.K Rowling", "1002", 14);
	Book *book3 = new Book("The Hobbit", "J.R.R Tolkien", "1003", 14);
	Book *book4 = new Book("The Silmarillion", "J.R.R Tolkien", "1004", 14);
	Book *book5 = new Book("The Hunger Games", "Suzanne Collins", "1005", 14);
	Time.addBook(book1);
	Time.addBook(book2);
	Time.addBook(book3);
	Time.addBook(book4);
	Time.addBook(book5);
	// Student *student = new Student("1001");
	// Time.addStudent(student);
	// cout << "Book 1 available 5: " << book1->getAvailableCopies() << std::endl;
	// Time.borrowBook("1001", "1001");
	// cout << "Book 1 available : " << book1->getAvailableCopies() << std::endl;
	// vector<Book*> booksborrow = student->getBorrowedBooks();
	// for (auto book : booksborrow)
	// {
	// 	std::cout << book->getTitle() << std::endl;
	// }
	// std::cout << book1->getAvailableCopies() << std::endl;
	// Time.returnBook("1001", "1001");
	// cout << "Book 1 available : " << book1->getAvailableCopies() << std::endl;
	// std::cout << book1->getAvailableCopies() << std::endl;
	while (true)
	{
		Menu();
		int choice = 0;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{

		case 1:
		{
			cout << "You want to register as: " << endl;
			cout << "1. Student" << endl;
			cout << "2. Librarian" << endl;
			int second_choice = 0;
			cout << "Enter your choice: ";
			cin >> second_choice;
			system("cls");
			switch (second_choice)
			{
			case 1:
			{
				system("cls");
				Student *student = new Student();
				student->registerUser();
				Time.addStudent(student);
				cout << "Register successfully!" << endl;
				cout << "Back to main menu in 3 seconds" << endl;
				Delay(3);
				system("cls");
			}
			break;

			case 2:
			{
				system("cls");
				Librarian *librarian = new Librarian();
				librarian->registerUser();
				Time.addLibrarian(librarian);
				cout << "Register successfully!" << endl;
				cout << "Back to main menu in 3 seconds" << endl;
				Delay(3);
				system("cls");
			}
			break;

			default:
				cout << "Invalid choice!" << endl;
				break;
			}
		}
		break;

		case 2:
		{
			system("cls");
			cout << "-------------------Login------------------" << endl;
			Student *new_student = new Student();
			bool statusLogIn = false;
			new_student->StudentLogin();
			system("cls");
			while (true)
			{
				StudentMenu();
				int ch = 0;
				cout << "Enter your choice: ";
				cin >> ch;
				switch (ch)
				{

				case 0:
				{
					system("cls");
					Time.displayAllBooks();
					Delay(5);
					cout << endl;
					cout << "Press any key to back to student menu" << endl;
					getch();
					system("cls");
				}
				break;

				case 1:
				{
					system("cls");
					cout << "-------------------Borrow Book------------------" << endl;
					string book_id = "";
					string student_id = "";
					cin.ignore();
					cout << "Enter student id: ";
					cin >> student_id;
					cout << "Enter book id: ";
					cin >> book_id;
					bool returned;
					Time.borrowBook(student_id, book_id, &returned);
					Delay(2);
					cout << endl;
					cout << "Press any key to back to student menu" << endl;
					getch();
					system("cls");
				}
				break;

				case 2:
				{
					system("cls");
					cout << "-------------------Return Book------------------" << endl;
					string book_id = "";
					string student_id = "";
					cin.ignore();
					cout << "Enter student id: ";
					cin >> student_id;
					cout << "Enter book id: ";
					cin >> book_id;
					bool borrowed;
					Time.returnBook(student_id, book_id, &borrowed);
					Delay(2);
					cout << endl;
					cout << "Press any key to back to student menu" << endl;
					getch();
					system("cls");
				}
				break;

				case 3:
				{
					system("cls");
					cout << "-------------------Search Book------------------" << endl;
					string book_id = "";
					cin.ignore();
					cout << "Enter book id: ";
					cin >> book_id;
					Book *book = Time.findByBookID(book_id);
					if (book != nullptr)
					{
						cout << "Book found!" << endl;
						cout << "Book title: " << book->getTitle() << endl;
						cout << "Book author: " << book->getAuthor() << endl;
						cout << "Book available quantity: " << book->getAvailableCopies() << endl;
					}
					else
					{
						cout << "Book not found!" << endl;
					}
					Delay(2);
					cout << endl;
					cout << "Press any key to back to student menu" << endl;
					getch();
					system("cls");
				}
				break;

				case 4:
				{
					system("cls");
					cout << "-------------------View Borrowed Books------------------" << endl;
					string student_id = "";
					cin.ignore();
					cout << "Enter student id: ";
					cin >> student_id;
					Student *student = Time.findByStudentId(student_id);
					if (student != nullptr)
					{
						cout << "Student found!" << endl;
						vector<Book*> booksborrow = student->getBorrowedBooks();
						for (auto book : booksborrow)
						{
							cout << "Book title: " << book->getTitle() << endl;
							cout << "Book author: " << book->getAuthor() << endl;
						}
					}
					else
					{
						cout << "Student not found!" << endl;
					}
					Delay(2);
					cout << endl;
					cout << "Press any key to back to student menu" << endl;
					getch();
					system("cls");
				}
				break;
				
				case 5:
				{
					system("cls");
					cout << "-------------------Logout------------------" << endl;
					cout << "Logout successfully!" << endl;
					cout << "Back to main menu in 3 seconds" << endl;
					Delay(3);
					system("cls");
				}
				break;

				default:
					cout << "Invalid choice!" << endl;
					system("cls");
					break;
				}
			}
		}
		break;

		case 3:
			cout << "Thank you for using our system!" << endl;
			cout << "Leaving the system in 5 seconds" << endl;
			Delay(5);
			return 0;
			break;
		}
	}
}

void Menu()
{
	cout << "Welcome to the Library Management System" << endl;
	cout << "1. Register" << endl;
	cout << "2. Login" << endl;
	cout << "3. Exit" << endl;
}

void StudentMenu()
{
	cout << "0. View all books" << endl;
	cout << "1. Borrow book" << endl;
	cout << "2. Return book" << endl;
	cout << "3. Search book" << endl;
	cout << "4. View borrowed books" << endl;
	cout << "5. Logout" << endl;
}

void LibrarianMenu()
{
	cout << "0. View all books" << endl;
	cout << "1. Add book" << endl;
	cout << "2. Remove book" << endl;
	cout << "3. Search book" << endl;
	cout << "4. View borrowed books" << endl;
	cout << "5. Logout" << endl;
}