#include"matrix.h"
matrix::matrix(int row = 0, int col = 0) {
	m = row;
	n = col;
	p = new int* [m];
	for (int i = 0;i < m;i++) {
		p[i] = new int[n];
	}
}
//matrix::~matrix() {
//	for (int i = 0;i < m;i++) {
//		delete[] p[i];
//	}
//	delete[] p;
//}
void matrix::defineMatrix() {
	cout << "Enter matrix elements" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Row " << i + 1 << " " << "Column " << j + 1 << ": ";
			cin >> p[i][j];
		}
	}
}
void matrix::display() {
	cout << "The matrix is:";
	for (int i = 0; i < m; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << p[i][j] << " ";
		}
	}
	cout << endl;
}
matrix matrix::operator+(const matrix& rhs) {
	matrix temp(m, n);
	if (m == rhs.m && n == rhs.n) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp.p[i][j] = p[i][j] + rhs.p[i][j];
			}
		}
	}
	else {
		cout << "Invalid Addition" << endl;
		for (int i = 0; i < temp.m; i++) {
			for (int j = 0; j < temp.n; j++) {
				temp.p[i][j] = NULL;
			}
		}
	}
	return temp;
}
matrix matrix::operator-(const matrix& rhs) {
	matrix temp(m, n);
	if (m == rhs.m && n == rhs.n) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp.p[i][j] = p[i][j] - rhs.p[i][j];
			}
		}
	}
	else {
		cout << "Invalid Subtraction" << endl;
		for (int i = 0; i < temp.m; i++) {
			for (int j = 0; j < temp.n; j++) {
				temp.p[i][j] = NULL;
			}
		}
	}
	return temp;
}
matrix matrix::operator*(const matrix& rhs) {
	matrix temp(m, rhs.n);
	if (n == rhs.m) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < rhs.n;j++) {
				temp.p[i][j] = 0;
				for (int k = 0; k < n; k++) {
					temp.p[i][j] = temp.p[i][j] + (p[i][k] * rhs.p[k][j]);
				}
			}
		}
	}
	else {
		cout << "Invalid Multiplication" << endl;
		for (int i = 0; i < temp.m; i++) {
			for (int j = 0; j < temp.n; j++) {
				temp.p[i][j] = NULL;
			}
		}
	}
	return temp;
}
ostream& operator <<(ostream& os, const matrix& rhs) {
	for (int i = 0; i < rhs.m; i++)
	{
		for (int j = 0; j < rhs.n; j++)
		{
			os << rhs.p[i][j] << " ";
		}
		os << endl;
	}
	return os;
}