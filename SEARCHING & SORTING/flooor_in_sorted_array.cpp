#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<long long> v, long long n, long long x) {
    long long start = 0;
    long long end = n - 1;
    long long floor = -1;
    
    while (start <= end) {
        long long mid = start + (end - start) / 2;
        
        if (v[mid] == x) {
            return mid;  // Return index if exactly x
        } else if (v[mid] < x) {
            floor = mid;  // Update floor to the last known smallest value <= x
            start = mid + 1;
        } else {  // v[mid] > x
            end = mid - 1;
        }
    }
    
    return floor;  // Return the last updated index or -1 if no such index exists
}

int main() {
    vector<long long> arr = {1, 2, 8, 10, 11, 12, 19};
    long long n = arr.size();
    vector<long long> test_values = {0, 5, 10, 20, 3};

    for (long long x : test_values) {
        cout << "Floor index of " << x << " in the array is: " << findFloor(arr, n, x) << endl;
    }

    return 0;
}
