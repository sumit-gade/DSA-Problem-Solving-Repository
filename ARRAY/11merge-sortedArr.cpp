#include<iostream>
#include<algorithm>
using namespace std;


void merge(long long arr1[], long long arr2[], int n, int m) {
    int i = n - 1;
    int j = 0;
    
    while (i >= 0 && j < m) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
        }
        
        i--;
        j++; 
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}


int main() {
    int n = 4;
    int m = 5;
    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {0, 2, 6, 8, 9};

    merge(arr1, arr2, n, m);

    cout << "Merged arr1: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }

    cout << "\nMerged arr2: ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}