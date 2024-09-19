#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int sum = 0;
    
    // Calculate the sum of array elements (n-1 elements in the array)
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }

    // Calculate the expected sum of the first n natural numbers
    int expectedSum = (n * (n + 1)) / 2;

    // Return the missing number
    return expectedSum - sum;
}

int main() {
    int arr[] = {1, 2, 3, 5};  // Example: 4 is missing
    int n = 5;  // Array should contain numbers from 1 to 5

    // Call the function and output the missing number
    cout << "The missing number is: " << findMissingNumber(arr, n) << endl;

    return 0;
}
