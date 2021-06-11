// Example program
#include <iostream>
#include<math.h>
using namespace std;
int main()
{
    double a, b, c, x, x1, x2, D;
    cout << "vedite chislo " << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    if (a == 0 && c != 0 && b != 0) {
        x = (-1 * c) / b;
        cout << "x = " << x << endl;
    }
    else if (b == 0 && c < 0) {
        x1 = sqrt((-1 * c) / a);
        x2 = -1 * sqrt((-1 * c / a));
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (c == 0) {
        x1 = 0;
        x2 = (-1 * b) / a;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else {
        D = (pow(b, 2)) - (4 * a * c);
        if (D > 0) {
            x1 = ((-1 * b) + sqrt(D)) / (2 * a);
            x2 = ((-1 * b) - sqrt(D)) / (2 * a);
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
        else if (D == 0) {
            x = (-1 * b) / (2 * a);
            cout << "x = " << x << endl;
        }
        else if (D < 0) {
            cout << "Решений нет" << endl;
        }
    }
    return 0;
}

