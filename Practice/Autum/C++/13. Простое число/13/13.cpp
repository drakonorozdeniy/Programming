using namespace std;
#include <iostream>
#include <math.h>

int main()
{
    setlocale(0, "");
    int n , k,b;
    k = 0;
    cin >> n;
    b = n;
    for (int i = 2; i < ((round(sqrt(n)))+1); i++) {

        if (b % i == 0) {
            k++;
        }
    }
    if (k == 0) {
        cout << "Простое" << endl;
    }
    else {
        cout << "Составное" << endl;
    }
    return 0;
}


