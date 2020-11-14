#include <iostream>
#include "Header.h"
#include "Header2.h"
#include "Header3.h"
#include <iomanip>
using namespace std;

int main() {
	cout << "n" << "	" << "n!" << endl;
	for (int i = 1; i < 11; i++) {
		cout << i << "	" << factorial(i) << endl;
	}
	cout << endl;
	cout << "x" << "	" << "sinx" << endl;
	for (double j = 0; j <= (3.1415 / 4); j = j + (3.1415 / 180)) {
		cout << setprecision(4) << j <<"	"<<sinx(j,5)<<endl; 

	}
	cout << endl;
	cout << "k" << "	" << "C(k,10)" << endl;
	for (int h = 1; h <= 10; h++) {
		cout << h << "	" << sochetanie(10, h) << endl;

	}
}

