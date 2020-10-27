
#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	int s,l1,r1,l2,r2,m,o ;
	cin >> s >> l1 >> r1 >> l2 >> r2;
	m = s - l1;
	o = s - r1;
	if (l2 <= m && m<= r2) {
		cout << l1 << " " << m << endl;
	}
	else if (l2 <= o &&  m<= r2) {
		cout<< r1 <<" "<<  o << endl;
	}
	else {
		cout << "-1" << endl; 

	}
	

	return 0;
}

