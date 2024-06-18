#include <iostream>
#include <vector>
using namespace std;

int areMatricesIdentical(int N, vector<vector<int>> Grid1, vector<vector<int>> Grid2) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (Grid1[i][j] != Grid2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N;
    cout << "Enter the size of the matrices: ";
    cin >> N;

    vector<vector<int>> Grid1(N, vector<int>(N));
    vector<vector<int>> Grid2(N, vector<int>(N));

    cout << "Enter elements of matrix Grid1:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Grid1[i][j];
        }
    }

    cout << "Enter elements of matrix Grid2:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Grid2[i][j];
        }
    }

    if (areMatricesIdentical(N, Grid1, Grid2)) {
        cout << "The matrices are identical." << endl;
    } else {
        cout << "The matrices are not identical." << endl;
    }

    return 0;
}
