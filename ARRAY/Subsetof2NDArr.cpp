/* TC-o(N)
sc-o(n)

*/


#include <iostream>
#include <unordered_map>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        map[a1[i]] = 1;
    }
    for (int j = 0; j < m; j++) {
        if (map[a2[j]] != 1) {
            return "No";
        }
    }
    return "Yes";
}

int main() {
    // Example usage
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 1, 4};

    string result = isSubset(arr1, arr2, 5, 3);
    cout << result << endl;

    return 0;
}
