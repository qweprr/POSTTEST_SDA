#include <iostream>
using namespace std;

void balikArray(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    const int n = 7;
    int arr[n];

    // isi array dengan kelipatan 3
    for (int i = 0; i < n; i++) {
        arr[i] = 3 * (i + 1);
    }

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    // panggil fungsi untuk membalik array
    balikArray(arr, n);

    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
