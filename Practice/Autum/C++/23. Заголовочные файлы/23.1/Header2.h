#ifndef F_4
#define F_4
#include <iostream>
#include "Header.h"
using namespace std;
double sinx(double x, double k) {
	int l;
	double sum, m;
	sum = x;
	l = 1;
	for (int i = 3; i < (2 * k + 1); i = i + 2) {
		if (l % 2 == 0) {
			m = pow(x, i) / factorial(i);
		}
		else {
			m = -1 * (pow(x, i) / factorial(i));
		}
		l++;
		sum = sum + m;
	}
	return sum;
}
#endif