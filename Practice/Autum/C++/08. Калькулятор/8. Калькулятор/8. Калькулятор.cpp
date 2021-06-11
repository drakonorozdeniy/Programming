#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	double a, b;
	char operation;
	cin >> a >> operation >> b;
	if (operation == '*') {
		cout << a * b << endl;
	}
	else if (operation == '/') {
		if (b == 0) {
			cout << "Делить на ноль нельзя" << endl;
		}
		else {
			cout << a / b << endl;
		}
	}
	else if (operation == '+') {
		cout << a + b << endl;
	}
	else if (operation == '-') {
		cout << a - b << endl;
	}
	return 0;
}

