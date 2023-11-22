#include "User.h"
#include "Library.h"

User::User(string, string, string, Date)
{
}

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

void Student::borrowBook()
{

}
