#include <iostream>
#include <vector>

using namespace std;

vector<int> valueEqualToIndex(int arr[], int n) {
    
    vector<int> v;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] == i + 1) {
            v.push_back(i + 1);
        }
    }
    
    return v;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> result = valueEqualToIndex(arr, n);

    cout << "Indices where array value is equal to index: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
