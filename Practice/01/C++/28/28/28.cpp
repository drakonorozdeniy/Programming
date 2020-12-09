#include <iostream>
using namespace std; 

int main()
{
	int n,k=0,u=0; 
	cin >> n;
	if (n % 2 == 0 && n % 3 == 0) {
		while (n % 2 == 0) {
			n = n / 2;
			k++;
		}
		while (n % 3 == 0) {
			n = n / 3;
			u++;
		}
		cout << 2 << "^" << k << "*" << 3 << "^" << u << "*" << n << endl; 
	}

}


