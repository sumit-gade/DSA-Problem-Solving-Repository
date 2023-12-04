#include<iostream>
#include<vector>
using namespace std;

long long maxProduct(vector<int> arr, int n) {
    long long ans = arr[0];
    long long ma = ans;
    long long mi = ans;

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            swap(ma, mi);
        }

        ma = max((long long)arr[i], ma * arr[i]);
        mi = min((long long)arr[i], mi * arr[i]);
        ans = max(ans, ma);
    }

    return ans;
}


int main(){

     vector<int> arr = {6, -3, -10, 0, 2};
    int n = arr.size();

    long long result = maxProduct(arr, n);

    cout << "Maximum Product Subarray: " << result << endl;
    
     return 0;
}