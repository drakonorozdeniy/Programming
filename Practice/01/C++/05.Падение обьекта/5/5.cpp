
#include <iostream>

int main()
{
	int x;
	double a, x0, v0, t;
	a = 9.8;
	std::cin >> x0;
	std::cin >> v0;
	std::cin >> t;
	x = (x0 + (v0 * t) - (a * t * t * 0.5));
	std::cout << x << std::endl;

}