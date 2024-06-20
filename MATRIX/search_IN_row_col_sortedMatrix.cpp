#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<int>> matrix, int n, int m, int x) {
    int i = 0, j = m - 1;
    while (i < n && j >= 0) {
        if (matrix[i][j] == x) return true;
        else if (matrix[i][j] > x) {
            j--;
        } else {
            i++;
        }
    }
    return false;
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns
    int x = 5;                // Element to search for

    // Function call and output the result
    bool result = search(matrix, n, m, x);
    if (result) {
        cout << "Element " << x << " found in the matrix." << endl;
    } else {
        cout << "Element " << x << " not found in the matrix." << endl;
    }

    return 0;
}
