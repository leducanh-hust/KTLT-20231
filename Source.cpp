#include"User.h"
#include"Book.h"
#include"Library.h"

using namespace std;

class Date
{
public:
	int date;
	int month;
	int year;
	
	//Compare dates: 1 if x is the day before, 0 if y is the day before 
	Date() = default;
	Date(int d, int m, int y) : date(d), month(m), year(y) {}
	bool cmp(Date x, Date y)
	{
		if (x.year < y.year)
			return 1;
		return 0;
	}
	friend ostream& operator<<(ostream& out, const Date& date)
	{
		out << date.date << "/" << date.month << "/" << date.year;
		return out;
	}
};

int main()
{

}