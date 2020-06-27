#include <iostream>
using namespace std;
class matrix {
	int m, n, ** p;
public:
	matrix(int row, int col);
	//~matrix();
	void defineMatrix();
	void display();
	matrix operator+(const matrix& rhs);
	matrix operator-(const matrix& rhs);
	matrix operator*(const matrix& rhs);
	friend ostream& operator <<(ostream& os, const matrix& rhs);
};