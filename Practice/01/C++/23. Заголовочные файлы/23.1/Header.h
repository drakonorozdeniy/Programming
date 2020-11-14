#pragma once
#include <iostream>
using namespace std;

int factorial(int n)
{
	int b = 1;
	while (n > 0) {
		b = b * n;
		n--;
	}
	return b;

}
