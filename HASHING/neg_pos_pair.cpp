#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> PosNegPair(int a[], int n) {
    vector<int> v, ans;
    map<int, int> mp;

    // Separate negative elements and count positive elements
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            v.push_back(a[i]);
        } else {
            mp[a[i]]++;
        }
    }

    // Sort negative elements
    sort(v.begin(), v.end());

    // Find pairs and add to ans
    for (int i = v.size() - 1; i >= 0; i--) {
        int data = abs(v[i]);

        if (mp[data] > 0) {
            ans.push_back(v[i]);
            ans.push_back(data);
            mp[data]--;
        }
    }

    return ans;
}

int main() {
    // Example array
    int a[] = {4, 8, 9, -4, 1, -1, -8, -9, -1, 1};
    int n = sizeof(a) / sizeof(a[0]);

    // Function call
    vector<int> result = PosNegPair(a, n);

    // Output the result
    cout << "Pairs of positive and negative numbers: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
