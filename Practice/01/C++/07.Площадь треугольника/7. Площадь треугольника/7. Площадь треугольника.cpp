#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(0, "");
    int r;
    double p, a, b, c, S, x1, y1, x2, y2, x3, y3, a1, b1, c1;
    cout << "Введите каким способом вы хотите работать\n1-через длины сторон a b c\n2-через координаты вершины A B C "<<endl;
    cin >> r;
    if (r == 1) {
        cout << "Вы выбрали работать через длинны сторонон"<<endl;
        cin >> a >> b >> c;
        if ((a + b) > c) {
            p = (a + b + c) / 2;
            S = sqrt(p * (p - a) * (p - b) * (p - c));
            cout << "S = " << S;
        }
        else {
            cout << "Введите верные числовые значения,\nсумма двух сторон обязана быть больше третьей" << endl;
        }
    }
    else {
        cout << "Вы выбрали работать через координаты вершин"<<endl;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        a1 = sqrt(pow((y2 - y1), 2) + (pow((x2 - x1), 2)));
        b1 = sqrt(pow((y3 - y2), 2) + (pow((x3 - x2), 2)));
        c1 = sqrt(pow((y1 - y3), 2) + (pow((x1 - x3), 2)));
        if ((a1 + b1) < c1) {
            cout << "Введите верные числовые значения,\nсумма двух сторон обязана быть больше третьей" << endl;
        }
        else {
            S = 0.5*(abs((x2 * y3) - (x3 * y2)));
            cout << "S = " << S<<endl;
        }
    }

    return 0;


}
