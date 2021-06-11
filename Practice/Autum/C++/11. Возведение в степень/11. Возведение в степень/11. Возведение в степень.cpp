#include <iostream>
using namespace std;
int main()
{
	int a, b, m;
	cin >> a >> b;
	m = 1;
	for (int i = 0; i < b; i++) {
		m=m*a;
	}cout << m << endl;
	return 0;

}
