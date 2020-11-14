#ifndef F_5
#define F_5
#include <iostream>
#include "Header.h"
using namespace std;

int sochetanie(int n, int l) {
	int C;
	C = factorial(n) / (factorial(l) * factorial(n - l));
	return C;
}
#endif 