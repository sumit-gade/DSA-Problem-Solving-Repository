#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nextPermutation(int N, vector<int>& arr){
    // No permutation when single element
    if (N == 1) {
        return arr;
    }

    int idx1 = -1;
    for (int i = N - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            idx1 = i;
            break;
        }
    }

    // If no next permutation, reverse the entire array
    if (idx1 < 0) {
        reverse(arr.begin(), arr.end());
    } else {
        int idx2 = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (arr[i] > arr[idx1]) {
                idx2 = i;
                break;
            }
        }

        swap(arr[idx1], arr[idx2]);
        reverse(arr.begin() + idx1 + 1, arr.end());
    }

    return arr;
}

int main() {
    // Example usage
    vector<int> arr = {1, 2, 3};
    int N = arr.size();
    cout << "Original Array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    arr = nextPermutation(N, arr);

    cout << "Next Permutation: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
