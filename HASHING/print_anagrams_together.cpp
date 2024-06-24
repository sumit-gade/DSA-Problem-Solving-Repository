#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> Anagrams(vector<string>& string_list) {
    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < string_list.size(); i++) {
        string s = string_list[i];
        sort(s.begin(), s.end());  // Sort the characters of the string
        mp[s].push_back(string_list[i]); // Group the original string under the sorted key
    }

    vector<vector<string>> ans;

    for (auto i : mp) {  // Traverse the map
        ans.push_back(i.second); 
    }

    return ans;
}

int main() {
    // Example list of strings
    vector<string> string_list = {"cat", "dog", "tac", "god", "act"};

    // Function call
    vector<vector<string>> result = Anagrams(string_list);

    // Output the result
    cout << "Anagram groups: " << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
