#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) {
    vector<int> res; // Result vector
    map<int, int> mp;

    // Count the occurrences of each element in A1
    for (int i = 0; i < N; i++) {
        mp[A1[i]]++;
    }

    // Append elements from A2 as per their order
    for (int i = 0; i < M; i++) {
        if (mp.find(A2[i]) != mp.end()) {
            int counter = mp[A2[i]]; // Number of occurrences of A2[i] in A1

            while (counter--) {
                res.push_back(A2[i]); // Push all occurrences of A2[i]
            }

            mp.erase(A2[i]); // Remove the element from the map
        }
    }

    // Append remaining elements in ascending order
    for (auto x : mp) {
        int counter = x.second;

        while (counter--) {
            res.push_back(x.first);
        }
    }

    return res;
}

int main() {
    // Example arrays
    vector<int> A1 = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    vector<int> A2 = {2, 1, 8, 3};

    int N = A1.size(); // Size of A1
    int M = A2.size(); // Size of A2

    // Function call
    vector<int> result = sortA1ByA2(A1, N, A2, M);

    // Output the result
    cout << "Sorted A1 according to A2: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
