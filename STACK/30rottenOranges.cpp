#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int r = grid.size();
    int c = grid[0].size();

    // Initialize the queue with all rotten oranges
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    int count = 0;
    q.push({-1, -1}); // End of one process marker

    // Process the queue
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if (i == -1 && j == -1) {
            if (!q.empty()) {
                count++;
                q.push({-1, -1});
            }
        } else {
            if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                grid[i - 1][j] = 2;
                q.push({i - 1, j});
            }

            if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                grid[i][j - 1] = 2;
                q.push({i, j - 1});
            }

            if (i + 1 < r && grid[i + 1][j] == 1) {
                grid[i + 1][j] = 2;
                q.push({i + 1, j});
            }

            if (j + 1 < c && grid[i][j + 1] == 1) {
                grid[i][j + 1] = 2;
                q.push({i, j + 1});
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }

    return count;
}

int main() {
    // Example input
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    // Output the result
    int result = orangesRotting(grid);
    if (result != -1) {
        cout << "All oranges rotted in " << result << " minutes." << endl;
    } else {
        cout << "Not all oranges can rot." << endl;
    }

    return 0;
}
