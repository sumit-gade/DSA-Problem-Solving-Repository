#include <iostream>
#include <vector>
using namespace std;

void Addition(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB) {
    int n = matrixA.size();  // number of rows
    int m = matrixA[0].size();  // number of columns
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrixA[i][j] += matrixB[i][j];
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example matrices
    vector<vector<int>> matrixA = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    vector<vector<int>> matrixB = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    
    cout << "Matrix A before addition:" << endl;
    printMatrix(matrixA);
    
    cout << "Matrix B:" << endl;
    printMatrix(matrixB);
    
    // Perform addition
    Addition(matrixA, matrixB);
    
    cout << "Matrix A after addition:" << endl;
    printMatrix(matrixA);
    
    return 0;
}
