using namespace std;
#include <iostream>

int main()
{
	setlocale(0, "");
	int p,m,i,x,k;
	p = 1;
	cout << "Дамы и господа сегодня мы с вами будем играть в угадайку\nБудет загадано число в промежутке[0, 100]\nВам нужно будет его угадать желаю удачи!"<<endl;
	while (p != 2) {
		m = rand() % 101;
		cout << "Введите число 0<=x<=100" << endl;
		for (i = 0; i < 5; i++) {
			cin >> x;
			if (m > x) {
				cout << "Загаданное число больше" << endl;
			}
			else if (x > m) {
				cout << "Загаданное число меньше" << endl;
			}
			else if (x == m) {
				cout << "Вы угадали, поздравляю!!!" << endl;
			}
		}if (i == 5 && x != m) {
			cout << "Вы проиграли (( , загаданное число было {" << m << "}" << endl;
		}cout << "Хотите начать сначала? (1 - ДА )" << endl;
		cin >> k;
		if (k != p) {
			break;
		}
	} 
}

