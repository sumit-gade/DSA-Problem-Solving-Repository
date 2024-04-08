#include <iostream>
#include <vector>
using namespace std;

void rotateby90(vector<vector<int>>& matrix, int n) {
    // Transpose the matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Swap opposite rows
    for(int i = 0; i < (n / 2); i++) {
        for(int j = 0; j < n; j++) {
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
}

int main() {
    // Example usage
    vector<vector<int>> matrix = {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9}};
    int n = 3;

    // Display original matrix
    cout << "Original Matrix:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Rotate the matrix by 90 degrees
    rotateby90(matrix, n);

    // Display rotated matrix
    cout << "\nRotated Matrix:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
