#include <vector>
#include <cmath> // For abs function
#include <iostream> // For testing purpose

int diagonalSumDifference(const std::vector<std::vector<int>>& grid) {
    int sumL = 0;
    int sumR = 0;
    int n = grid.size();

    for (int i = 0; i < n; ++i) {
        sumL += grid[i][i];         // Sum of primary diagonal elements
        sumR += grid[i][n - i - 1]; // Sum of secondary diagonal elements
    }

    return std::abs(sumL - sumR); // Return the absolute difference
}

int main() {
    // Test case
    std::vector<std::vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int result = diagonalSumDifference(grid);
    std::cout << "Diagonal Sum Difference: " << result << std::endl; // Expected output: 0

    return 0;
}
