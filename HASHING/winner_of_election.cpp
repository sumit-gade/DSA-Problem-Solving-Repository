#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> winner(string arr[], int n) {
    // Create an unordered map to count votes for each candidate
    unordered_map<string, int> umap;
    for (int i = 0; i < n; i++) {
        umap[arr[i]]++;
    }

    string name = "";
    int max_vote = 0;

    // Find the candidate with the maximum votes
    for (auto itr = umap.begin(); itr != umap.end(); itr++) {
        string key = itr->first;
        int val = itr->second;

        if (val > max_vote) {
            max_vote = val;
            name = key;
        } else if (val == max_vote) {
            // In case of a tie, select the lexicographically smaller name
            if (key < name)
                name = key;
        }
    }

    // Prepare the result
    vector<string> ans;
    ans.push_back(name);
    string temp = to_string(max_vote);  // Convert int to string
    ans.push_back(temp);

    return ans;
}

int main() {
    string arr[] = {"john", "johnny", "jackie", "johnny", "john", "jackie", "jamie", "jamie", "john"};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<string> result = winner(arr, n);

    cout << "Winner: " << result[0] << endl;
    cout << "Votes: " << result[1] << endl;

    return 0;
}
