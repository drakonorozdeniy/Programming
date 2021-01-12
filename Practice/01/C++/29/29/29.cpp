﻿#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

template<class T>
vector<T> BozoSort(vector<T>array, int num, bool b = 1) {
    bool check = 1;
    while (check) {
        check = 0;
        int a1 = rand() % num;     
        int a2 = rand() % num;
        swap(array[a1], array[a2]); 
        if (b) {                
            for (int i = 0; i < num - 1; i++) {
                if (array[i] > array[i + 1]) {
                    check = 1;
                    break;
                }
            }
        }
    }
    return array;
}

struct Student {
    string name;
    int group;
    map<string, int> exams;
};


ostream& operator << (ostream& out, Student stud) {
    out << "+-----------+-------+------+------+------+------+\n"
        << "| Name      | Group | Math | Phys | Hist | Prog |\n"
        << "+-----------+-------+------+------+------+------+\n"
        << "| " << stud.name << " | " << stud.group << " "
        << "    | " << stud.exams.at("Math")
        << "    | " << stud.exams.at("Phys")
        << "    | " << stud.exams.at("Hist")
        << "    | " << stud.exams.at("Prog")
        << "    |\n"
        << "+-----------+-------+------+------+------+------+\n";
    return out;
}

ostream& operator << (ostream& out, vector<Student> stud_v) {
    out << "+-----------+-------+------+------+------+------+\n"
        << "| Name      | Group | Math | Phys | Hist | Prog |\n"
        << "+-----------+-------+------+------+------+------+\n";
    for (const auto& stud : stud_v) {
        out << "| " << stud.name << " | " << stud.group << " "
            << "    | " << stud.exams.at("Math")
            << "    | " << stud.exams.at("Phys")
            << "    | " << stud.exams.at("Hist")
            << "    | " << stud.exams.at("Prog")
            << "    |\n"
            << "+-----------+-------+------+------+------+------+\n";
    }
    return out;
}

bool operator > (Student& a, Student& b) {
    return a.name > b.name;
}

int main() {
    //создание вектора из 10 структур типа Student
    vector<Student> AllStudents = {
        Student{"Akihito K", 5, {{"Math", 5}, {"Phys", 4}, {"Hist", 3}, {"Prog", 5}}},
        Student{"Pipez   L", 2, {{"Math", 5}, {"Phys", 5}, {"Hist", 5}, {"Prog", 3}}},
        Student{"Tores   M", 5, {{"Math", 4}, {"Phys", 2}, {"Hist", 2}, {"Prog", 5}}},
        Student{"Uzumaki N", 2, {{"Math", 3}, {"Phys", 4}, {"Hist", 3}, {"Prog", 4}}},
        Student{"Rain    M", 4, {{"Math", 5}, {"Phys", 5}, {"Hist", 5}, {"Prog", 5}}},
        Student{"Anxel   T", 2, {{"Math", 4}, {"Phys", 4}, {"Hist", 5}, {"Prog", 2}}},
        Student{"Miracle E", 2, {{"Math", 5}, {"Phys", 4}, {"Hist", 5}, {"Prog", 3}}},
        Student{"Mores   P", 3, {{"Math", 4}, {"Phys", 4}, {"Hist", 5}, {"Prog", 3}}},
        Student{"Ebinuma K", 1, {{"Math", 3}, {"Phys", 4}, {"Hist", 4}, {"Prog", 5}}},
        Student{"Kojima  D", 4, {{"Math", 4}, {"Phys", 5}, {"Hist", 3}, {"Prog", 2}}}
    };

    

    vector<Student> MARK_TWO;
    for (int i = 0; i < 10; i++) {
        if (AllStudents[i].exams.at("Math") == 2 or
            AllStudents[i].exams.at("Phys") == 2 or
            AllStudents[i].exams.at("Hist") == 2 or
            AllStudents[i].exams.at("Prog") == 2) {
            MARK_TWO.push_back(AllStudents[i]);
        }
    }

    if (!MARK_TWO.empty()) {
        cout << BozoSort(MARK_TWO, MARK_TWO.size());
    }
    else {
        cout << "Not found\n";
        return 0;
    }

    cout << endl << "Expulsion\n\n";
    int i = rand() % MARK_TWO.size();
    cout << MARK_TWO[i];
}


