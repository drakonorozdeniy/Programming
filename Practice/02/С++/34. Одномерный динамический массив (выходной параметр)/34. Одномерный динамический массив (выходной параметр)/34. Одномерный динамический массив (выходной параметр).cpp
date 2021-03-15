
#include <iostream>
#include <string>

using namespace std;

int* create(int*& parametr, int size, int first , int step );
void sort(int* arr, int size);
string print(int* arr, int size);
void destroy(int* arr);


int main()
{
    int size; cin >> size;
    int first; cin >> first;
    int step; cin >> step;
   
    int* arr = create(arr,size, first, step);
    sort(arr, size);
    string out = print(arr, size);
    cout << out;
    destroy(arr);
}

int* create(int*& parametr, int size , int first = 0 , int step = 0 ) {

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = first;
        first = first + step;
    }
    return arr; 
}


void sort(int* arr, int size) {
    for (int step = 1; step < size; step++) {
        int key = arr[step];
        int j = step - 1;
        while (key < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

string print(int* arr, int size) {
    string out = "[";
    for (int i = 0; i < size - 1; i++) {
        out += to_string(arr[i]) + ", ";
    }
    out += to_string(arr[size - 1]) + "]";
    return out;
}

void destroy(int* arr) {
    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }
}

