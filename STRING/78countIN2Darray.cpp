#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findOccurrence(vector<vector<char>> &mat, const string &target) {
        int res = 0;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                res += helper(mat, i, j, target, 0);
            }
        }

        return res;
    }

private:
    int helper(vector<vector<char>> &mat, int i, int j, const string &target, int idx) {
        int found = 0;

        if (i < mat.size() && i >= 0 && j < mat[0].size() && j >= 0 &&
            target[idx] == mat[i][j]) {    // agar match mil gaya to 

            mat[i][j] = '#';  // to not repeat itself again

            if (idx == target.length() - 1) {   // agr jo chaihiye wo mil gaya to use count 1 badha do
                found = 1;
            } else {
                found += helper(mat, i, j - 1, target, idx + 1);
                found += helper(mat, i + 1, j, target, idx + 1);
                found += helper(mat, i - 1, j, target, idx + 1);
                found += helper(mat, i, j + 1, target, idx + 1);
            }

            mat[i][j] = target[idx];    // for back backtracking  

        } 

        return found;
    }
};

int main() {

    vector<vector<char>> matrix = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'}
    };

    string target = "abc";

    Solution solution;
    int occurrences = solution.findOccurrence(matrix, target);

    cout << "Occurrences: " << occurrences << endl;

    return 0;
}
