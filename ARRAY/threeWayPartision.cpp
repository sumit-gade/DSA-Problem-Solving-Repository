#include <iostream>
#include <vector>

void threeWayPartition(std::vector<int>& arr, int a, int b) {
    int start = 0;
    int curr = 0;
    int end = arr.size() - 1;

    while (curr <= end) {
        if (arr[curr] < a) {
            std::swap(arr[curr], arr[start]);
            start++;
            curr++;
        } else if (arr[curr] >= a && arr[curr] <= b) {
            curr++;
        } else if (arr[curr] > b) {
            std::swap(arr[curr], arr[end]);
            end--;
        }
    }
}

int main() {
    
    std::vector<int> arr = {2, 1, 3, 5, 4, 7, 6, 8};
    int a = 3;
    int b = 6;

    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    threeWayPartition(arr, a, b);

    std::cout << "After Three-way Partitioning: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
