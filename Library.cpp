#include "Library.h"

void Library::find_by_id(string id, Book& result)
{
	for (int i = 0; i < library.size(); i++)
	{
		if (library[i].bookID == id)
		{
			result = library[i];
			return;
		}
	}
	throw "Book not found";
}

void Library::find_by_author(string author, vector<Book>& result)
{
	for (int i = 0; i < library.size(); i++)
	{
		if (library[i].author == author)
		{
			result.push_back(library[i]);
		}
	}
	if (result.size() == 0)
	{
		throw "Book not found";
	}
}

void Library::find_by_title(string title, vector<Book>& result)
{
	for (int i = 0; i < library.size(); i++)
	{
		if (library[i].title == title)
		{
			result.push_back(library[i]);
		}
	}
	if (result.size() == 0)
	{
		throw "Book not found";
	}
}

void Library::find_by_genre(Genre genre, vector<Book>& result)
{
	for (int i = 0; i < library.size(); i++)
	{
		for (int j = 0; j < library[i].genre.size(); j++)
		{
			if (library[i].genre[j] == genre)
			{
				result.push_back(library[i]);
			}
		}
	}
	if (result.size() == 0)
	{
		throw "Book not found";
	}	
}
