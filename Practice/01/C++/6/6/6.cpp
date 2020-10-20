#include <cmath>
#include<math.h>
#include <iostream>
using namespace std;
int main()
{
    double a, b, c, x, x1, x2;
    int D;
    cin >> a;
    cin >> b;
    cin >> c;
    D = (pow(b, 2)) - (4 * a * c);
    if (a == 0 && c != 0 && b != 0); {
        x = (-1 * c) / b;
        cout << "x=" << int(x) << endl;
    }
    if  (D > 0) {
        x1 = (-b - (sqrt(D))) / (2 * a);
        x2 = (-b - (sqrt(D))) / (2 * a);
        cout << "x1=" << int(x1) << endl;
        cout << "x2=" << int(x2) << endl;
    }
    if (D == 0) {
        x = -b / (2 * a);
        cout << "x=" << int(x) << endl;
    }
    if  (D < 0) {
        cout << "net resheniu\n";
    }
}


