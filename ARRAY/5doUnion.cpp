// tc-0(n+m)

#include<iostream>
#include <unordered_set>

using namespace std;

/*Sets are a type of associative container in which each element has to be unique because the value of the element identifies it.
 The values are stored in a specific sorted order i.e. either ascending or descending.*/

int doUnion(int a[], int n, int b[], int m) {
    unordered_set<int> unionSet;

    // Insert elements from array 'a' into the unionSet
    for (int i = 0; i < n; ++i) {
        unionSet.insert(a[i]);
    }

    // Insert elements from array 'b' into the unionSet
    for (int i = 0; i < m; ++i) {
        unionSet.insert(b[i]);
    }

    // Return the size of the unionSet, which represents the count of distinct elements in the union
    return unionSet.size();
}

// Example usage:
int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);

    int b[] = {3, 4, 5, 6, 7};
    int m = sizeof(b) / sizeof(b[0]);

    int result = doUnion(a, n, b, m);
    cout << "Number of elements in the union: " << result << endl;

    return 0;
}
