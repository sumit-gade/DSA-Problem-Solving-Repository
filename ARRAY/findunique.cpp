#include <iostream>

int findUnique(int *arr, int size)
{
    int ans = 0;

    // Iterate through the array
    for (int i = 0; i < size; i++) {
        // Use XOR (^) to cancel out duplicate elements
        ans = ans ^ arr[i];
    }

    // The remaining value in 'ans' is the unique element
    return ans;
}


int main() {
    int arr[] = {2, 4, 6, 8, 2, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int uniqueElement = findUnique(arr, size);

    std::cout << "The unique element is: " << uniqueElement << std::endl;

    return 0;
}
