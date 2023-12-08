#include "Book.h"

void Book::check_in()
{
	for (auto& s : status)
	{
		if (s == "Checkout")
		{
			s = "Checkin";
			available_copies++;
			return;
		}
	}
	cout << "Book is not checked out" << endl;
}

void Book::check_out()
{
	for (auto& s : status)
	{
		if (s == "Checkin" && available_copies >= 1)
		{
			s = "Checkout";
			available_copies--;
			return;
		}
	}
	if (available_copies == 0)
		cout << "Book is not available" << endl;
	else
		cout << "Book is already checked out" << endl;
}