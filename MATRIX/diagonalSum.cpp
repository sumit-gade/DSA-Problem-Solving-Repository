#include <iostream>
#include <vector>

int DiagonalSum(std::vector<std::vector<int>>& matrix) {
    int sum = 0;
    int n = matrix.size(); // Use size() method to get the number of rows/columns

    for (int i = 0; i < n; ++i) {
        sum += matrix[i][i];       // Add the primary diagonal element
        sum += matrix[i][n - i - 1]; // Add the secondary diagonal element
    }

    // If the matrix size is odd, subtract the middle element which was added twice
    if (n % 2 != 0) {
        sum -= matrix[n / 2][n / 2];
    }

    return sum;
}

int main() {
    // Test case
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int result = DiagonalSum(matrix);
    std::cout << "Diagonal Sum: " << result << std::endl; // Expected output: 25

    return 0;
}
