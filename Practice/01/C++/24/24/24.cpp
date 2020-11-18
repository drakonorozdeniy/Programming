#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

int main() {
	int  s=0 , t=1;
	ifstream in_file("in.json");
	json j;
	json j2 = json::array();
	in_file >> j;
	for (int i = 0; i < j.size(); i++) {
		if (j[i]["userId"] == t && j[i]["completed"] == true ) {
			s++;
		}
		else if (j[i]["userId"] != t && j[i]["completed"] == true) {
			j2.push_back({ { "userId", t }, { "task_comleted", s } });
			s = 0;
			t++;
			s++;
		}
	}
	j2.push_back({ { "userId", t }, { "task_comleted", s } });

	ofstream o_file("out.json");
	o_file << j2.dump(2); 
}