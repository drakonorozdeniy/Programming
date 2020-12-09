#include <vector>
#include <ctime>
#include <iostream>
using namespace std;

vector<int> Bozosort(vector<int> arr, bool sortirovka = true);
vector<int>  Bozosort(int a, int b, int c, bool sortirovka = true);
vector<int> Bozosort(vector < vector <int> > a, bool sortirovka = true); 

int main() {
    setlocale(0, "");
    int m = 1, n, b;
    vector<int> mass, myvector, unit;
    cout << "Введите количетсво чисел которые будем сортировать" << endl;
    cin >> n;
    cout << "Введите числа " << endl;
    vector < vector <int> > a(m, vector <int>(n));
    for (int i = 0; i < m; i++)     // Цикл, который идёт по строкам
        for (int j = 0; j < n; j++) // Цикл, который идёт по элементам
        {
            cin >> a[i][j]; // Заполнение вектора или массива (в данном случае ввод)
            mass.push_back(a[i][j]);
        }
    cout << endl; 
    for (auto const& element : Bozosort(a))
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort(a, false))
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort(mass)) 
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort(mass, false)) 
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort(mass[0], mass[1], mass[2])) 
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort(mass[0], mass[1], mass[2], false)) 
        cout << element << ' '; 
}

vector<int> Bozosort(vector<int> arr, bool sortirovka) {
    bool exit = false;
    int g = arr.size();
    if (sortirovka) {
        while (!exit) {
            exit = true;
            srand(time(0));
            int i = 0 + rand() % g;
            int k = 0 + rand() % g;
            if (arr[i] <= arr[k] && i > k || arr[k] <= arr[i] && k > i) {
                int t = arr[i];
                arr[i] = arr[k];
                arr[k] = t;
            }
            for (int num = 0; num < (g - 1); num++) 
                if (arr[num] > arr[num + 1]) 
                    exit = false;
        }
    }
    else {
        while (!exit) {
            exit = true;
            srand(time(0));
            int i = 0 + rand() % g;
            int k = 0 + rand() % g;
            if (arr[k] <= arr[i] && k < i || arr[k] >= arr[i] && i < k) {
                int t = arr[i];
                arr[i] = arr[k];
                arr[k] = t;
            }
            for (int num = 0; num < (g - 1); num++) 
                if (arr[num] < arr[num + 1]) 
                    exit = false;
        }
    }
    return arr;
}

vector<int> Bozosort(vector < vector <int> > a, bool sortirovka) {
    vector<int > unit;
    int m = 1;
    bool exit = false;
    int g = a[0].size();
    if (sortirovka) {
        while (!exit) {
            exit = true;
            srand(time(0));
            int i = 0 + rand() % g;
            int k = 0 + rand() % g;
            if (a[0][i] <= a[0][k] && i > k || a[0][k] <= a[0][i] && k > i) {
                int t = a[0][i];
                a[0][i] = a[0][k];
                a[0][k] = t;
            }
            for (int num = 0; num < (g - 1); num++)
                if (a[0][num] > a[0][num + 1])
                    exit = false;
        }
    }
    else {
        while (!exit) {
            exit = true;
            srand(time(0));
            int i = 0 + rand() % g;
            int k = 0 + rand() % g;
            if (a[0][k] <= a[0][i] && k < i || a[0][k] >= a[0][i] && i < k) {
                int t = a[0][i];
                a[0][i] = a[0][k];
                a[0][k] = t;
            }
            for (int num = 0; num < (g - 1); num++)
                if (a[0][num] < a[0][num + 1])
                    exit = false;
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < g; j++)
            unit.push_back(a[i][j]);
    return unit;
}

vector<int>  Bozosort(int a, int b, int c, bool sortirovka) {
    vector<int> chisla;
    chisla.push_back(a);
    chisla.push_back(b);
    chisla.push_back(c);
    int g = chisla.size();
    bool exit = false;
    if (sortirovka) {
        while (!exit) {
            exit = true;
            srand(time(0));
            int i = 0 + rand() % g;
            int k = 0 + rand() % g;
            if (chisla[i] <= chisla[k] && i > k || chisla[k] <= chisla[i] && k > i) {
                int t = chisla[i];
                chisla[i] = chisla[k];
                chisla[k] = t;
            }
            for (int num = 0; num < (g - 1); num++)
                if (chisla[num] > chisla[num + 1])
                    exit = false;
        }
    }
    else {
        while (!exit) {
            exit = true;
            srand(time(0));
            int i = 0 + rand() % g;
            int k = 0 + rand() % g;
            if (chisla[i] >= chisla[k] && k < i || chisla[k] >= chisla[i] && i < k) {
                int t = chisla[i];
                chisla[i] = chisla[k];
                chisla[k] = t;
            }
            for (int num = 0; num < (g - 1); num++)
                if (chisla[num] < chisla[num + 1])
                    exit = false;
        }
    }
    return chisla;
}

   












