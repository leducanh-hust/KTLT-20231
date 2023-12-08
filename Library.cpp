#include "Library.h"
#include "User.h"

int Library::getNumberOfBooks()
{
	return library.size();
}

int Library::getNumberOfUsers() 
{
	return users.size();
}

bool Library::find_by_id(string id, Book* result)
{
    for(int i = 0; i < library.size(); i++)
	{
		if(library[i].bookID == id)
		{
			*result = library[i];
			return true;
		}
	}
	return false;
}


// bool Library::find_by_title(string title, vector<Book>& result)
// {
//     for (const auto& book : library)
//     {
//         if (book.title == title)
//         {
//             result.push_back(book);
//         }
//     }

//     return !result.empty();
// }


// bool Library::find_by_genre(string genre, vector<Book>& result)
// {
//     for (const auto& book : library)
//     {
//         for (const auto& bookGenre : book.genre)
//         {
//             if (bookGenre == genre)
//             {
//                 result.push_back(book);
//                 // Break the inner loop after finding a match to avoid duplicates
//             }
//         }
//     }

//     return !result.empty();  // Return true if result is not empty
// }


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









