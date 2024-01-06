/*  Search In Rotated Sorted Array   */


#include <iostream>
#include <vector>

using namespace std;



int getPivot(std::vector<int>& arr, int n) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e) {
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        } else {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int binarySearch(std::vector<int>& arr, int s, int e, int key) {
    int start = s;
    int end = e;
    int mid = start + (end - start) / 2;

    while (start <= end) {
        if (arr[mid] == key) {
            return mid;
        }

        // go to the right part
        if (key > arr[mid]) {
            start = mid + 1;
        } else {  // key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int search(std::vector<int>& arr, int n, int k) {
    int pivot = getPivot(arr, n);

    if (arr[pivot] <= k && k <= arr[n - 1]) {
        // binary search on the second part
        return binarySearch(arr, pivot, n - 1, k);
    } else {
        // binary search on the first part
        return binarySearch(arr, 0, pivot - 1, k);
    }
}

int main() {
    vector<int> rotatedArray = {4, 5, 6, 7, 8, 1, 2, 3};
    int n = rotatedArray.size();
    int key = 6;

    int result = search(rotatedArray, n, key);

    if (result != -1) {
        std::cout << "Element found at index: " << result << endl;
    } else {
        std::cout << "Element not found in the array." << endl;
    }

    return 0;
}
