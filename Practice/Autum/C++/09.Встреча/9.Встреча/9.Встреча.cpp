using namespace std;
#include <iostream>
int main()
{
    setlocale(0, "");
    int a, b,m,c,d,p;
    char h,l;
    cin >> a >> h >> b;
    cin >> c >> l >> d;
    m = a * 60 + b;
    p = c * 60 + d;
    if (p - m <= 15) {
        cout << "Встреча состоиться" << endl; 
    }
    else {
        cout << "Встреча не состоиться" << endl; 
    }
    return 0;
}

