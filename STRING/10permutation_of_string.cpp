#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<string> st; // for unique and lexicographically sorted order.

void recursiveFunc(int i, string s)
{
    int n = s.size();
    if (i == n)
    {
        st.insert(s);
        return;
    }

    for (int j = i; j < n; j++)
    {
        swap(s[i], s[j]);
        recursiveFunc(i + 1, s);
        swap(s[i], s[j]); // for backtracking
    }
}

vector<string> find_permutation(string S)
{
    recursiveFunc(0, S);

    vector<string> ans;

    for (auto perm : st)
    {
        ans.push_back(perm);
    }

    return ans;
}

int main()
{
    string input = "ABC";
    vector<string> permutations = find_permutation(input);

    cout << "Permutations of " << input << " are:" << endl;
    for (const string &perm : permutations)
    {
        cout << perm << endl;
    }

    return 0;
}
