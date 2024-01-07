#include <iostream>
#include <vector>

void insertionSort(int n, std::vector<int> &arr) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];  // Store the current element for comparison
        int j = i - 1;      // Start with the element to the left of the current one

        // Compare the current element with the elements to its left
        for (; j >= 0; j--) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];  // Shift elements to the right
            } else {
                break;  // Stop shifting if the current element is greater than or equal to temp
            }
        }

        arr[j + 1] = temp;  // Place the stored element in its correct position
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22};

    std::cout << "Original array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    insertionSort(arr.size(), arr);

    std::cout << "Sorted array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
