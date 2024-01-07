#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[minIndex], arr[i]);
    }
}

int main() {
   
    vector<int> array = {64, 25, 12, 22, 11};
    int n = array.size();

    cout << "Original array: ";
    for (int i : array) {
        cout << i << " ";
    }
    cout << endl;

    selectionSort(array, n);

    cout << "Sorted array: ";
    for (int i : array) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
