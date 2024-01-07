#pragma once
#include <iostream>
#include "User.h"
#include "Book.h"
#include <string>
#include <fstream>


void updateStudentAccount(vector<Student*> &_student)
{
    // Open file to write
    fstream file;
    file.open("C:\\Users\\PC\\Desktop\\testprj-code\\StudentAccount.csv", ios::out);
    if (!file.is_open())
    {
        cerr << "File cannot open!";
        return;
    }
    file << "ID" << "," << "Username" << "," << "Password" << "," << "Fine money" << "," << "Hashed Password" << "," << "Full Name" << "," << "Class" 
        << "," << "School" << "," << "Book borrowed" << "\n";
    file << endl;
    for (auto &ite : _student)
    {
        string _hashPass = hashPassword(ite->getPassword());
        file << ite->getStudentId() << "," << ite->getUsername() << "," << ite->getPassword() << "," << ite->getFine() << ","
         << _hashPass << "," << ite->getFullName() << "," << ite->getStudentClass() << "," << ite->getStudentSchool() << "\n";
    }
    file.close();
}

void updateBookList(vector<Book*> &_book)
{
    fstream file;
    file.open("C:\\Users\\PC\\Desktop\\testprj-code\\BookList.csv", ios::out);
    if(!file.is_open())
    {
        cerr << "File cannot open";
        return;
    }

    for(auto &ite:_book)
    {
        vector<string> _genre = ite->getGenre(); 
        vector<string> _status = ite->getStatus();
        Date _dateBorrowed = ite->getBorrowedDate();
        Date _due = ite->getDueDate();
        file << ite->getBookID() << "," << ite->getTitle() << "," << ite->getAuthor() << "," << ite->getQuantity()
         << "," << ite->convertToString(_genre) << "," << ite->convertDate(_dateBorrowed) << "," << ite->convertDate(_due) << "\n";
    }
    file.close();
}

void updateLibrarianAccount(vector<Librarian*> &_librarian)
{
    fstream file;
    file.open("C:\\Users\\PC\\Desktop\\testprj-code\\LibrarianAccount.csv", ios::out);

    if(!file.is_open())
    {
        cerr << "File cannot open";
        return;
    }

    for(auto &ite : _librarian)
    {
        file << ite->getEmployeeId() << "," << ite->getUsername() << "," << ite->getPassword() << "," << ite->getFullName() << "\n";
    }
}

void readStudentFile(vector<Student*> &_student)
{
    fstream file;
    file.open("C:\\Users\\PC\\Desktop\\testprj-code\\StudentAccount.csv", ios::in);
    if(!file.is_open())
    {
        cerr << "File cannot open";
        return;
    }

    //Ignore 2 first lines
    file.ignore(); 
    file.ignore();

    string _id, _username, _password,_hashPass, _fullName, _class, _school, _borrowed;
    float _fine;
    while(file.peek() != EOF) //while file is not end
    {
        getline(file >> ws, _id, ',');
        getline(file >> ws, _username, ',');
        getline(file >> ws, _password, ',');
        file >> _fine;
        getline(file >> ws, _hashPass, ',');
        getline(file >> ws, _fullName, ',');
        getline(file >> ws, _class, ',');
        getline(file >> ws, _school, ',');
        getline(file >> ws, _borrowed, '\n');

        Student *student = new Student;
        student->setStudentId(_id);
        student->setUsername(_username);
        student->setPassword(_password);
        student->setFine(_fine);
        student->setName(_fullName);
        student->setStudentClass(_class);
        student->setStudentSchool(_school);
        
        _student.push_back(student);
    }
    file.close();
}
