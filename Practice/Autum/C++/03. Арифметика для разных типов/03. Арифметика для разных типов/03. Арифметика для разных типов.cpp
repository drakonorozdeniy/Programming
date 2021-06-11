using namespace std;
#include <iostream>

int main()
{
	int a, b, c, d;
	double a1, b1, c1, d1;
	cin >> a >> b;
	if (b != 0) {
		cout << a + b << " " << a - b << " " << a * b << endl;
		cout << a / b << endl;
	}
	else {
		cout << a + b << " " << a - b << " " << a * b << endl;
		cout << "Делить на 0 нельзя, поэтому вывода на деление нет ";
	}
	cin >> a1 >> b1;
	if (b1 != 0) {
		cout << a1 + b1 << " " << a1 - b1 << " " << a1 * b1 << endl;
		cout << a1 / b1 << endl;
	}
	else {
		cout << a1 + b1 << " " << a1 - b1 << " " << a1 * b1 << endl;
		cout << "Делить на 0 нельзя, поэтому вывода на деление нет ";
	}
	cin >> c >> c1;
	if (c1 != 0) {
		cout << c + c1 << " " << c - c1 << " " << c * c1 << endl;
		cout << a / b << endl;
	}
	else {
		cout << c + c1 << " " << c - c1 << " " << c * c1 << endl;
		cout << "Делить на 0 нельзя, поэтому вывода на деление нет ";
	}
	cin >> d1 >> d;
	if (d != 0) {
		cout << d1 + d << " " << d1 - d << " " << d1 * d << endl;
		cout << a / b << endl;
	}
	else {
		cout << d1 + d << " " << d1 - d << " " << d1 * d << endl;
		cout << "Делить на 0 нельзя, поэтому вывода на деление нет ";
	}

}


