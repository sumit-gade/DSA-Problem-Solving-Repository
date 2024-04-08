#include <iostream>
#include <vector>
using namespace std;

vector<int> sumTriangles(const vector<vector<int>>& matrix, int n) {
    vector<int> ans;

    int sum_lower = 0;

    for(int i = 0; i < n; i++) // Lower Triangle
    {
        for(int j = 0; j <= i; j++) {
            sum_lower += matrix[i][j];
        }
    }

    int sum_upper = 0;

    for(int i = 0; i < n; i++) // Upper Triangle
    {
        for(int j = n - 1; j >= i; j--) {
            sum_upper += matrix[i][j];
        }
    }

    ans.push_back(sum_upper);
    ans.push_back(sum_lower);

    return ans;
}

int main() {
    // Example usage
    vector<vector<int>> matrix = {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9}};

    int n = 3;

    vector<int> result = sumTriangles(matrix, n);

    cout << "Sum of upper triangle elements: " << result[0] << endl;
    cout << "Sum of lower triangle elements: " << result[1] << endl;

    return 0;
}
