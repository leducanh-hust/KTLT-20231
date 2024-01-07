#include "User.h"

string Student::getStudentId()
{
	return studentId;
}

string Student::getStudentClass()
{
	return studentClass;
}

string Student::getStudentSchool()
{
	return studentSchool;
}

void Student::setStudentId(string id)
{
	studentId = id;
}

void Student::setStudentClass(string studentClass)
{
	studentClass = studentClass;
}

void Student::setStudentSchool(string school)
{
	studentSchool = school;
}

string Librarian::getEmployeeId()
{
	return employeeId;
}

string User::getUsername()
{
	return username;
}
string User::getPassword()
{
	return password;
}

void User::setUsername(string username)
{
	this->username = username;
}

void User::setPassword(string password)
{
	this->password = password;
}

void Student::addBorrowedBook(Book *book) { borrowedBooks.push_back(book); }

bool User::checkPassword(std::string attempt)
{
	return attempt == password;
}

void Student::StudentLogin()
{
	string s_username, s_password;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
	cout << "Enter your username: ";
	getline(cin, s_username);
	cout << "Enter your password: ";
	getline(cin, s_password);
	ifstream file("C:/Users/PC/Desktop/testprj-code./StudentAccount.txt");
	if (file.is_open())
	{
		string usrname, passw, line;
		while (getline(file, line))
		{
			size_t pos = line.find(",");
			usrname = line.substr(1, pos - 1);
			size_t pos2 = line.find(";");
			passw = line.substr(pos + 1, pos2 - pos - 1);
			// cerr << usrname << ";" << passw << endl;
			if (usrname == s_username && passw == hashPassword(s_password))
			{
				cout << "Login successfully!" << endl;
				return;
			}
		}
		cout << "Wrong username or account not exist!" << endl;
		cout << "Please register first if youn don't have an account!" << endl;
		file.close();
	}
	else
	{
		cerr << "Error opening file." << endl;
	}
}

void Student::registerUser() 
{
	// Call the base class registerUser to get the basic information
	User::registerUser();

	// Additional information for the Student class
	string id, studentClass, school;
	cout << "Enter your student ID: ";
	getline(cin, id);
	cout << "Enter your class: ";
	getline(cin, studentClass);
	cout << "Enter your school: ";
	getline(cin, school);

	// Set the additional information for the Student
	studentId = id;
	this->studentClass = studentClass;
	studentSchool = school;
}