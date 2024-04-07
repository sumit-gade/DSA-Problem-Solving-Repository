/*
Time Complexity: O(N2log(N2))
Auxiliary Space: O(N2)

*/










#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

// Function prototype
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat);

int main() {
    // Example usage
    int N = 3;
    vector<vector<int>> Mat = {
        {5, 2, 7},
        {1, 9, 4},
        {3, 6, 8}
    };

    vector<vector<int>> sortedMat = sortedMatrix(N, Mat);

    // Display the sorted matrix
    cout << "Sorted Matrix:" << endl;
    for (const auto &row : sortedMat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
    vector<int> temp;
   
    // Store all elements of matrix into temp
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp.push_back(Mat[i][j]);
        }
    }
 
    // Sort the temp
    sort(temp.begin(), temp.end());

    int curr = 0;
 
    // Assign sorted elements back to the matrix
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            Mat[i][j] = temp[curr];
            curr++;
        }      
    }

    return Mat;
}
