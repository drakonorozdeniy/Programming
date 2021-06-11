#include <iostream>


using namespace std;

int main() {
	setlocale(0,"");
	int numbers[37], numb, red = 0, black = 0, a = 0;				
	int array_red[18] = { 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36 };
	int array_black[18] = { 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35 };
	for (int i = 0; i < 37; i++) numbers[i] = 0;					
	while (1) {
		cout << "Введите число\n";
		cin >> numb;
		if (numb < 0 || numb > 36) 
			break;
		else {
			numbers[numb]++;
			for (int color = 0; color < 18; color++) {
				if (numb == array_red[color])   red += 1;				
				else if (numb == array_black[color])   black += 1;
			}
		}
		for (int s = 0; s < 37; s++) {
			if (numbers[s] > a)   a = numbers[s];
		}
		for (int s = 0; s < 37; s++) {							
			if (numbers[s] == a)   cout << s << " ";
		}
		cout << "\n";
		for (int s = 0; s < 37; s++) {
			if (numbers[s] == 0)   cout << s << " ";				
		}
		cout << "\n" << red << " " << black << "\n";

	}
}