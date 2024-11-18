#include <iostream>
using namespace std;

int max(int m, int n) { return (m > n) ? m : n; }

int* add(int A[], int B[], int m, int n)
{
    int size = max(m, n);
    int* sum = new int[size]();

    for (int i = 0; i < m; i++)
        sum[i] = A[i];

    for (int i = 0; i < n; i++)
        sum[i] += B[i];

    return sum;
}

void printPoly(int poly[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << poly[i];
        if (i != 0)
            cout << "x^" << i;
        if (i != n - 1)
            cout << " + ";
    }
    cout << endl;
}

int main()
{
    int m, n;
    
    cout << "Enter the degree of the first polynomial: ";
    cin >> m;
    m++;
    
    int* A = new int[m];
    cout << "Enter the coefficients of the first polynomial:" << endl;
    for (int i = 0; i < m; i++)
        cin >> A[i];
    
    cout << "Enter the degree of the second polynomial: ";
    cin >> n;
    n++;
    
    int* B = new int[n];
    cout << "Enter the coefficients of the second polynomial:" << endl;
    for (int i = 0; i < n; i++)
        cin >> B[i];
    
    cout << "First polynomial is: ";
    printPoly(A, m);
    
    cout << "Second polynomial is: ";
    printPoly(B, n);
    
    int* sum = add(A, B, m, n);
    int size = max(m, n);
    
    cout << "Sum polynomial is: ";
    printPoly(sum, size);
    
    delete[] A;
    delete[] B;
    delete[] sum;
    
    return 0;
}

