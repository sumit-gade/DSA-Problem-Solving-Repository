#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> subsequences_rec;

void recurssiveAllPossibleSubsequences(int i, string s, string prev) {
    // base case
    if (i == s.size()) { // If we've reached the end of the string, add prev to the result
        if (prev.size()) // If prev is not empty, add it to subsequences_rec
            subsequences_rec.push_back(prev);
        return;
    }

    // recursive call

    // choose
    recurssiveAllPossibleSubsequences(i + 1, s, prev + s[i]);

    // reject
    recurssiveAllPossibleSubsequences(i + 1, s, prev);
}

vector<string> AllPossibleStrings(string s) {
    // Code here

    subsequences_rec.clear(); // Clearing global variable before using it again
    recurssiveAllPossibleSubsequences(0, s, "");

    sort(subsequences_rec.begin(), subsequences_rec.end()); // Sorting the result

    return subsequences_rec;
}

int main() {
    string example = "abc";
    vector<string> result = AllPossibleStrings(example);
    cout << "All possible subsequences of '" << example << "':\n";
    for (const auto& str : result) {
        cout << str << "\n";
    }
    return 0;
}
