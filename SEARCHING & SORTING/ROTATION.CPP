#include <iostream>
using namespace std;

int findKRotation(int arr[], int n) {
    // Traverse the array
    for (int i = 0; i < n; i++) {
        // Index where element is greater than the next element
        if (arr[i] > arr[(i + 1) % n]) {
            return (i + 1) % n;
        }
    }
    return 0; // NOT SORTED ARRAY
}

int main() {
    int arr1[] = {7, 9, 11, 12, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Array 1 is rotated " << findKRotation(arr1, n1) << " times.\n";

    int arr2[] = {3, 4, 5, 1, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Array 2 is rotated " << findKRotation(arr2, n2) << " times.\n";

    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Array 3 is rotated " << findKRotation(arr3, n3) << " times.\n";

    return 0;
}
