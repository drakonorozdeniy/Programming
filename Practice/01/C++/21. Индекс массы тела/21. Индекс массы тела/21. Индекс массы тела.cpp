#include <iostream>
using namespace std;

double bmi( double height, double weight) {
    double k;
    height = height / 100;
    k= weight / (height * height);
    return k;
}

void print_bmi(double k) {
    double bmi(double height, double weight);
    if (k < 18.5)
        cout << "Underweight";
    else if (k < 25 )
        cout << "Normal";
    else if (k  < 30)
        cout << "Overweight";
    else 
        cout << "Obesity";
}
int main()
{
    double weight, height;
    cout << "Write you height and weight:";
    cin >> height>>weight;
    print_bmi(bmi(height, weight));

}