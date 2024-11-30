#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio> 

using namespace std;

int main() {
    setlocale(0, "");
    int n;
    int flag = 1; 
    cout << "Elements: ";
    if (scanf("%d", &n) == 1) { 
        flag = 0; 
    }
    if (flag) {
        cout << "Incorrect input\n";
        return 0;
    }

    if (n <= 0) {
        cout << "Elems.\n";
        return 1;
    }

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Elem " << i + 1 << ": ";
        if (!(cin >> arr[i])) { 
            cout << "Incorrect input.\n";
            delete[] arr;
            return 1;
        }
    }

    cout << "Elems:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Address: " << &arr << "\n";

    cout << "Rast:\n";
    for (int i = 0; i < n; i++) {
        size_t byte = i * sizeof(int);
        int element = i;
        cout << "Elem " << i + 1 << ": " << arr[i] << " Rast: " << byte << " byte or " << element << " elems\n";
    }
    delete[] arr;

    return 0;
}
