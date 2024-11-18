#include <iostream>
using namespace std;

int max(int arr[], int n) {
    int x = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > x)
            x = arr[i];
    return x;
}

void countsort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10];
    memset(count, 0, sizeof(count)); 

    for (i = 0; i < n; i++)
        count[arr[i] / exp % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n) {
    int y = max(arr, n);
    for (int exp = 1; y / exp > 0; exp *= 10)
        countsort(arr, n, exp);
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl; 
}

int main() {
    int arr[] = {904, 46, 5, 72, 62, 1}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    radixsort(arr, n);
    print(arr, n);
    return 0;
}

