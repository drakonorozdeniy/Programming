#include <vector>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

template<typename T> vector<T> Bozosort(vector<T> arr, bool sortirovka = true);
template<typename K> vector<K> Bozosort(vector < vector <K> > a, bool sortirovka = true);
template<typename U> vector<U>  Bozosort(U a, U b, U c, bool sortirovka = true);

int main() {
    setlocale(0, "");
    int m = 1, n, n1,k=0;
    vector<double> doublearr;
    vector<string> strarr;
    cout << "Введите количетсво не целых чисел которые будем сортировать" << endl;
    cin >> n;
    cout << "Введите эти  числа " << endl;
    vector < vector <double> > arr2x(m, vector <double>(n));
    for (int i = 0; i < m; i++)     // Цикл, который идёт по строкам
        for (int j = 0; j < n; j++) // Цикл, который идёт по элементам
        {
            cin >> arr2x[i][j]; // Заполнение вектора или массива (в данном случае ввод)
            doublearr.push_back(arr2x[i][j]);
        }
    cout << "Введите количество чисел которые будем сортировать" << endl;
    cin >> n1;
    vector < vector <string> > array2D(m, vector <string>(n1));
    cout << "Введите числа " << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n1; j++)
        {
            cin >> array2D[i][j];
            strarr.push_back(array2D[i][j]);
        }
    cout << endl;
    for (auto const& element : Bozosort<double>(doublearr)) 
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort<double>(doublearr,false)) 
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort<double>(arr2x))
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort<double>(arr2x,false))
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort<double>(doublearr[0],doublearr[1],doublearr[2]))
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort<double>(doublearr[0], doublearr[1], doublearr[2],false))
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort<string>(strarr)) 
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort<string>(strarr,false))
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort<string>(array2D))
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort<string>(array2D,false))
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort<string>(strarr[0],strarr[1],strarr[2]))
        cout << element << ' ';
    cout << endl;
    for (auto const& element : Bozosort<string>(strarr[0], strarr[1], strarr[2],false))
        cout << element << ' ';
    cout << endl;
}
template<typename T>
vector<T> Bozosort(vector<T> arr, bool sortirovka ) {
    bool exit = false;
    int g = arr.size();
    if (sortirovka) {
        while (!exit) {
            exit = true;
            srand(time(0));
            int i = 0 + rand() % g;
            int k = 0 + rand() % g;
            if (arr[i] <= arr[k] && i > k || arr[k] <= arr[i] && k > i) {
                T t = arr[i];
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
                T t = arr[i];
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
template<typename K>
vector<K> Bozosort(vector < vector <K> > a, bool sortirovka) {
    vector<K> unit;
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
                K t = a[0][i];
                a[0][i] = a[0][k];
                a[0][k] = t;
            }
            for (int num = 0; num < (g-1); num++)
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
                K t = a[0][i];
                a[0][i] = a[0][k];
                a[0][k] = t;
            }
            for (int num = 0; num < (g - 1); num++)
                if (a[0][num] < a[0][num + 1])
                    exit = false;
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < g ; j++)
            unit.push_back(a[i][j]);
    return unit;
}
template<typename U>
vector<U>  Bozosort(U a, U b, U c, bool sortirovka) {
    vector<U> chisla;
    chisla.push_back(a);
    chisla.push_back(b);
    chisla.push_back(c);
    bool exit = false;
    int g = chisla.size();
    if (sortirovka) {
        while (!exit) {
            exit = true;
            srand(time(0));
            int i = 0 + rand() % g;
            int k = 0 + rand() % g;
            if (chisla[i] <= chisla[k] && i > k || chisla[k] <= chisla[i] && k > i) {
                U t = chisla[i];
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
                U t = chisla[i];
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
