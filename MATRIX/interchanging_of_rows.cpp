#include <bits/stdc++.h>

using namespace std;

void interchangeRows(vector<vector<int>>& matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < (row / 2); i++) {
        for (int j = 0; j < col; j++)
            swap(matrix[i][j], matrix[row - 1 - i][j]);
    }
}

int main()
{
    // Example usage of interchangeRows function
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int num : row)
            cout << num << " ";
        cout << endl;
    }

    interchangeRows(matrix);

    cout << "\nMatrix after interchanging rows:" << endl;
    for (const auto& row : matrix) {
        for (int num : row)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
