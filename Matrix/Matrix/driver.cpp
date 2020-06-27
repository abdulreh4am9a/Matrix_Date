#include "matrix.h"
int main() {
	cout << "\t\t\t ***************" << endl;
	cout << "\t\t\t Question No. 01" << endl;
	cout << "\t\t\t Class of Matrix" << endl;
	cout << "\t\t\t ***************" << endl;
	//declaring two 3x3 matrices
	matrix a(3, 3), b(3, 3);
	//taking inputs of a matrix
	a.defineMatrix();
	//displaying matrix a
	cout << a;
	//taking inputs of b matrix
	b.defineMatrix();
	//displaying matrix b
	cout << b;
	//adding these matrices
	cout << "\nADDITION OF MATRICES" << endl << a + b;
	//subtracting these matrices
	cout << "\nSUBTRACTION OF MATRICES" << endl << a - b;
	//multiplying these matrices
	cout << "\nMULTIPLICATION OF MATRICES" << endl << a * b;
	return 0;
}