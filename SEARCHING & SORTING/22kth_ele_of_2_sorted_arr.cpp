#include <iostream>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    if (k > n + m || k <= 0) {  // Checking if k is within the range of elements available
        return -1;  // Return -1 or any other error code
    }

    int sorted1[m + n];  // Array to store the merged sorted array
    int i = 0, j = 0, d = 0;

    // Merging two sorted arrays
    while (i < n && j < m) {
        if (arr1[i] < arr2[j])
            sorted1[d++] = arr1[i++];
        else
            sorted1[d++] = arr2[j++];
    }
    
    // Append remaining elements of arr1
    while (i < n)
        sorted1[d++] = arr1[i++];
    
    // Append remaining elements of arr2
    while (j < m)
        sorted1[d++] = arr2[j++];

    // Return the element at kth position in the merged sorted array
    return sorted1[k - 1];
}

int main() {
    int arr1[] = {2, 3, 6, 7, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {1, 4, 8, 10};
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int k = 5;

    int kth = kthElement(arr1, arr2, n, m, k);
    if (kth != -1) {
        cout << "The " << k << "th element is " << kth << endl;
    } else {
        cout << "Invalid input for k!" << endl;
    }

    return 0;
}
