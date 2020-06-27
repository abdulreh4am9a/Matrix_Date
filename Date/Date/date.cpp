#include "date.h"
//default constructor
date::date() {
	year = 1970;
	month = 1;
	day = 1;
}
//no of days in month
int monthDays(int m, int y) {
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		return 31;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) {
		return 30;
	}
	else if (m == 2) {
		if (isLeapYear(y)) {
			return 29;
		}
		else {
			return 28;
		}
	}
	else
		return 0;
}
//is leap year
bool isLeapYear(int y) {
	if (y % 4 == 0 && y % 100 != 0) {
		return true;
	}
	else if (y % 100 == 0 && y % 400 == 0) {
		return true;
	}
	else if (y % 400 == 0) {
		return true;
	}
	else {
		return false;
	}
}
//constructor
date::date(int year, int month, int day) {
	if (year > 0) {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day > 0 && day <= 31)
			{
				this->year = year;
				this->month = month;
				this->day = day;
			}
			else {
				this->year = 1970;
				this->month = 1;
				this->day = 1;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 0 && day <= 30)
			{
				this->year = year;
				this->month = month;
				this->day = day;
			}
			else {
				this->year = 1970;
				this->month = 1;
				this->day = 1;
			}
		}
		else if (month == 2) {
			if (isLeapYear(year)) {
				if (day > 0 && day <= 29) {
					this->year = year;
					this->month = month;
					this->day = day;
				}
				else {
					this->year = 1970;
					this->month = 1;
					this->day = 1;
				}
			}
			else {
				if (day > 0 && day <= 28) {
					this->year = year;
					this->month = month;
					this->day = day;
				}
				else {
					this->year = 1970;
					this->month = 1;
					this->day = 1;
				}
			}
		}
		else {
			this->year = 1970;
			this->month = 1;
			this->day = 1;
		}
	}
	else {
		this->year = 1970;
		this->month = 1;
		this->day = 1;
	}
}
//destructor
date::~date() {
	//cout << "Don't count the days, make the days count (" << year << "/" << month << "/" << day << ")." << endl;
	//commenting destructructor to get clear output
}
//set year
void date::setYear(int year) {
	this->year = year;
	if (year < 0) {
		this->year = 1970;
	}
}
//set month
void date::setMonth(int month) {
	this->month = month;
	if (month < 0 || month > 12) {
		this->month = 1;
	}
}
//set day
void date::setDay(int day) {
	this->day = day;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day < 0 || day > 31)
		{
			this->day = 1;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day < 0 || day > 30)
		{
			this->day = 1;
		}
	}
	else if (month == 2) {
		if (isLeapYear(year)) {
			if (day < 0 || day > 29) {
				this->day = 1;
			}
		}
		else {
			if (day < 0 || day > 28) {
				this->day = 1;
			}
		}
	}
}
//get year
int date::getYear()const {
	return year;
}
//get month
int date::getMonth()const {
	return month;
}
//get day
int date::getDay()const {
	return day;
}
//add year
void date::addYear(int y) {
	year = year + y;
}
//add month
void date::addMonth(int m) {
	month = month + m;
	while (month > 12) {
		month = month - 12;
		year++;
	}
	while (month < 1) {
		month = month + 12;
		year--;
	}
}
//add day
void date::addDay(int d) {
	day = day + d;
	while (day > monthDays(month, year)) {
		day = day - monthDays(month, year);
		addMonth(1);
	}
	while (day < 1) {
		addMonth(-1);
		day = day + monthDays(month, year);
	}
}
//difference
int date::diff(date d) {
	int days = 0;
	if (this->year != d.year) {
		days += calYearDays(this->year + 1, d.year - 1);
	}
	if (this->year != d.year && this->month != d.month) {
		days += calFullMonthDays(this->month, 12, this->year);
		days += calFullMonthDays(1, d.month, d.year);
		days += monthDays(this->month, this->year) - this->day;
		days += d.day;
	}
	if (this->year == d.year && this->month != d.month) {
		for (int x = this->month + 1;x < d.month;x++) {
			days += monthDays(x, this->year);
		}
		days += monthDays(this->month, this->year) - this->day;
		days += d.day;
	}
	if (this->year == d.year && this->month == d.month && this->day != d.day) {
		days += d.day - this->day;
	}
	/*days += calFullMonthDays(this->month, 12, this->year);
	days += monthDays(this->month, this->year) - this->day;
	days += calFullMonthDays(1, d.month, d.year);
	days += d.day;*/
	return days;
}
//display
void date::display() {
	cout << "YY/MM/DD : " << year << "/" << month << "/" << day << endl;
}
//calculate full year days
int calYearDays(int y1, int y2) {
	int days = 0;
	for (int y = y1;y <= y2;y++) {
		if (isLeapYear(y)) {
			days += 366;
		}
		else {
			days += 365;
		}
	}
	return days;
}
//calculate full month days
int calFullMonthDays(int m1, int m2, int y) {
	int days = 0;
	for (int m = m1;m <= m2;m++) {
		days += monthDays(m, y);
	}
	return days;
}

//Equal to
bool date::operator==(date rhs) {
	if ((year == rhs.year) && (month == rhs.month) && (day == rhs.day)) {
		return true;
	}
	else {
		return false;
	}
}

//Not Equal to
bool date::operator!=(date rhs) {
	if ((year != rhs.year) || (month != rhs.month) || (day != rhs.day)) {
		return true;
	}
	else {
		return false;
	}
}

//greater then
bool date::operator>(date rhs) {
	if (year > rhs.year)
		return true;
	else if ((year == rhs.year) && (month > rhs.month))
		return true;
	else if ((year == rhs.year) && (month == rhs.month) && (day > rhs.day))
		return true;
	else
		return false;
}

//less then
bool date::operator<(date rhs) {
	if (year < rhs.year)
		return true;
	else if ((year == rhs.year) && (month < rhs.month))
		return true;
	else if ((year == rhs.year) && (month == rhs.month) && (day < rhs.day))
		return true;
	else
		return false;
}

//greater then equal to
bool date::operator>=(date rhs) {
	if (year >= rhs.year)
		return true;
	else
		return false;
}

//less then equal to
bool date::operator<=(date rhs) {
	if (year <= rhs.year)
		return true;
	else
		return false;
}

//Pre Increament
date& date::operator++() {
	this->addDay(1);
	return *this;
}

//Pre Decreament
date& date::operator--() {
	this->addDay(-1);
	return *this;
}

//Post Increament
date date::operator++(int) {
	date temp(this->year, this->month, this->day);
	this->addDay(1);
	return temp;
}

//Post Decreament
date date::operator--(int) {
	date temp(this->year, this->month, this->day);
	this->addDay(-1);
	return temp;
}

//Insertion Operator
ostream& operator <<(ostream& os, const date& rhs) {
	os << rhs.year << "/" << rhs.month << "/" << rhs.day;
	return os;
}

//Extraction Operator
istream& operator >>(istream& in, date& rhs) {
	long int date;
	in >> date;
	int year = date % 10000;
	date = date / 10000;
	int month = date / 100;
	int day = date % 100;
	if (year > 0) {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day > 0 && day <= 31)
			{
				rhs.year = year;
				rhs.month = month;
				rhs.day = day;
			}
			else {
				rhs.year = 1970;
				rhs.month = 1;
				rhs.day = 1;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 0 && day <= 30)
			{
				rhs.year = year;
				rhs.month = month;
				rhs.day = day;
			}
			else {
				rhs.year = 1970;
				rhs.month = 1;
				rhs.day = 1;
			}
		}
		else if (month == 2) {
			if (isLeapYear(year)) {
				if (day > 0 && day <= 29) {
					rhs.year = year;
					rhs.month = month;
					rhs.day = day;
				}
				else {
					rhs.year = 1970;
					rhs.month = 1;
					rhs.day = 1;
				}
			}
			else {
				if (day > 0 && day <= 28) {
					rhs.year = year;
					rhs.month = month;
					rhs.day = day;
				}
				else {
					rhs.year = 1970;
					rhs.month = 1;
					rhs.day = 1;
				}
			}
		}
		else {
			rhs.year = 1970;
			rhs.month = 1;
			rhs.day = 1;
		}
	}
	else {
		rhs.year = 1970;
		rhs.month = 1;
		rhs.day = 1;
	}
	return in;
}