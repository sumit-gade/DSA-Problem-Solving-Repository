#include <bits/stdc++.h>
using namespace std;

void booleanMatrix(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();

    vector<int> row(r, 0); // Initialize vectors to keep track of rows and columns containing 1
    vector<int> col(c, 0);

    // Iterate through the matrix to mark rows and columns containing 1
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == 1) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Iterate through the matrix to set cells to 1 where corresponding row or column has 1
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (row[i] == 1 || col[j] == 1) {
                matrix[i][j] = 1;
            }
        }
    }
}

int main() {
    // Example usage
    vector<vector<int>> matrix = {
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };

    cout << "Original Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int num : row)
            cout << num << " ";
        cout << endl;
    }

    booleanMatrix(matrix);

    cout << "\nMatrix after boolean transformation:" << endl;
    for (const auto& row : matrix) {
        for (int num : row)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}

