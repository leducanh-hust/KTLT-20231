#include "Library.h"

int Library::getNumebrOfBooks() const
{
	return library.size();
}

int Library::getNumberOfUsers() const
{
	return users.size();
}

bool Library::find_by_id(string id, Book& result)
{
	for(auto &ite : library)
	{
		if(ite.bookID == id)
		{
			result = ite;
			return true;
		}
	}
	return false;
}

bool Library::find_by_author(string author, vector<Book>& result)
{
	for(auto &ite : library)
	{
		if(ite.author == author)
		{
			result.push_back(ite);
		}
	}
	if(result.size() > 0)
	{
		return true;
	}
	return false;
}

bool Library::find_by_title(string title, vector<Book>& result)
{
	for (auto& ite : library)
	{
		if (ite.title == title)
		{
			result.push_back(ite);
		}
	}
	if (result.size() > 0)
	{
		return true;
	}
	return false;
}

bool Library::find_by_genre(Genre genre, vector<Book>& result)
{
for (auto& ite : library)
	{
		for(int i = 0; i < ite.genre.size(); i++)
		if (ite.genre[i] == genre)
		{
			result.push_back(ite);
		}
	}
	if (result.size() > 0)
	{
		return true;
	}
	return false;
}

void Library::add_book(Book book)
{
	library.push_back(book);
}

void Library::remove_book(string id)
{
	for (int i = 0; i < library.size(); i++)
	{
		if (library[i].bookID == id)
		{
			library.erase(library.begin() + i);
			cout << "Book removed successfully!" << endl;
			return;
		}
	}
	cout << "Book not found!" << endl;
}




