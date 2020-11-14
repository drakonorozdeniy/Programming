using namespace std;
#include <iostream>
#include <string>


int main(int argc, const char * argv[1])
{
	setlocale(0, "");
	int n,p,c,k;
	string l;
	k = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l;
		p = l.find("a");
		c = l.find("55661");
		cout << p<<" " << c  << endl;
		if (c==4 && p==0) {
			cout << l << endl; 
			k++;
		}
	if (k == 0) {
		cout << "-1";
		}
return 0;
	}

}


