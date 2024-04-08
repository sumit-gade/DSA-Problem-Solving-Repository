#include <iostream>
#include <vector>
using namespace std;

int sumOfMatrix(int N, int M, vector<vector<int>> Grid) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum += Grid[i][j];
        }
    }
    return sum;
}

int main() {
    vector<vector<int>> exampleGrid = {{1, 2, 3},
                                       {4, 5, 6},
                                       {7, 8, 9}};
    int N = exampleGrid.size(); // Number of rows
    int M = exampleGrid[0].size(); // Number of columns

    cout << "Sum of the matrix elements: " << sumOfMatrix(N, M, exampleGrid) << endl;

    return 0;
}
