#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ostream& operator << (ostream& out, const vector<int>& vector);


int main() {
	vector<int> empty;
	ofstream out_file("data.txt");

	for (int i = 0; i < 64; i++) {
		empty.push_back(i);
		out_file << empty;
		cout << empty;
	}
	// 2 part of a task 
	for (int i = 63; i > 0; i--) {
		empty.pop_back();
		out_file << empty;
		cout << empty;
	}
	out_file.close();
}
// 3 part of a task
ostream& operator << (ostream& out, const vector<int>& vector) {
	out << vector.size() << "\t| ";

	for (int i = 0; i < vector.size(); i++) {
		out << &vector[i] << " ";
	}
	out << "\n";
	return out;
}