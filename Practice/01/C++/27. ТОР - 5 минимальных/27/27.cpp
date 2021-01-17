#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortirovka(vector<int> a, int n); 

int main()
{
	setlocale(0, "");
	int n, b;
	vector<int> signals;
	const int m = 5;
	cout << "Введите количество сигналов" << endl;
	cin >> n;
	cout << "Введите сигналы" << endl; 
	for (int i = 0; i < n; i++) {
		cin >> b;
		if (signals.size() != 5) {
			signals.push_back(b);
		}
		else if (signals.size() == 5 && b < *std::max_element(signals.begin(), signals.end())) {
			signals.pop_back();
			signals.push_back(b);
		}
		for (auto const& element : sortirovka(signals, signals.size()))
			cout << element << ' ';
		cout << endl;
	}
}
vector<int> sortirovka(vector<int> a, int n) {
	bool exit = false; // болевая переменная для выхода из цикла, если массив отсортирован
	while (!exit) { // пока массив не отсортирован
		exit = true;
		for (int j = 0; j < (a.size() - 1); j++) {
			if (a[j] < a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				exit = false;
			}
		}
	}
	return a;
}