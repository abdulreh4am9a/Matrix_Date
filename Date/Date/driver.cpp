#include "date.h"
int main() {
	cout << "\t\t\t ***************" << endl;
	cout << "\t\t\t Question No. 02" << endl;
	cout << "\t\t\t Class  of  Date" << endl;
	cout << "\t\t\t ***************" << endl;
	//only checking new operators overloaded in ths assignment
	//getting two date from user
	date a, b;
	cout << "Enter a date in this format [MMDDYYYY]: ";
	cin >> a;
	cout << "Date Entered: " << a << endl;
	cout << "Enter another date in this format [MMDDYYYY]: ";
	cin >> b;
	cout << "Date Entered: " << b << endl;
	//testing logical operators
	if (a == b)
		cout << "Both dates are EQUAL" << endl;
	if (a != b)
		cout << "Dates are NOT EQUAL" << endl;
	if (a > b)
		cout << a << " is greator than " << b << endl;
	if (a < b)
		cout << b << " is greator than " << a << endl;
	if (a >= b)
		cout << a << " is greator than and equal to " << b << endl;
	if (a <= b)
		cout << b << " is greator than and equal to " << a << endl;
	cout << "Date is " << a;
	cout << " after pre increament, date is " << ++a << endl;
	cout << "Date is " << b;
	cout << " after post increament, date is " << b++ << endl;
	cout << "Date is " << a;
	cout << " after pre decreament, date is " << --a << endl;
	cout << "Date is " << b;
	cout << " after post decreament, date is " << b-- << endl;
	return 0;
}