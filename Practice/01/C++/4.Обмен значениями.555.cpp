
#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a;
    std::cin >> b;
    c = b;
    b = a;
    a = c;
    std::cout << a<<std::endl;
    std::cout << b;
	int a1,b1;
	std::cin>>a1;
	std::cin>>b1;
	a1=a1+b1;
	b1=a1-b1;
	a1=a1-b1;
	std::cout << a1<<std::endl;
    std::cout << b1;
}

