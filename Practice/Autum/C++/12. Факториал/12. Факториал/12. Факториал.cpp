using namespace std;
#include <iostream>

int main()
{
    int n, b;
    b = 1;
    cin >> n;
    while (n != 0) {
        b = b * n;
        n--;
    }
    cout << b << endl;
    return 0;
}

