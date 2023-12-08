#include"User.h"
#include"Book.h"
#include"Library.h" // Include the Student header file
#include<iostream>
#include<string.h>

using namespace std;

void Menu()
{
	cout << "Welcome to the Library Management System" << endl;
	cout << "1. Register" << endl;
	cout << "2. Login" << endl;
	cout << "3. Exit" << endl;
}

int main()
{
	Student s("username", "password", "name", Date(1, 1, 2000), "id");
	s.displayInfo();
	Menu();
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	switch(choice)
	{
		case 1:
			cout << "Hello" << endl;
			break;
		default:
			cout << "Invalid choice!" << endl;
			break;
	}
	
}
