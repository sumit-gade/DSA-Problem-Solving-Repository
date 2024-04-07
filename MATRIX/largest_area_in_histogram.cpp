#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<long long> getPsei(long long arr[], int n) {
    stack<long long> s;
    vector<long long> psei(n, -1);

    for(int i = 0; i < n; i++) {
        while(!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if(!s.empty()) {
            psei[i] = s.top();
        }
        s.push(i);
    }

    return psei;
}

vector<long long> getNsei(long long arr[], int n) {
    stack<long long> s;
    vector<long long> nsei(n, n);

    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if(!s.empty()) {
            nsei[i] = s.top();
        }
        s.push(i);
    }

    return nsei;
}

long long getMaxArea(long long arr[], int n) {
    vector<long long> nsei = getNsei(arr, n);
    vector<long long> psei = getPsei(arr, n);

    long long maxArea = 0;

    for(int i = 0; i < n; i++) {
        long long h = arr[i];
        long long w = nsei[i] - psei[i] - 1;
        long long curr_area = h * w;
        maxArea = max(maxArea, curr_area);
    }

    return maxArea;
}

int main() {
    long long arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The largest rectangular area possible in the given histogram is: " << getMaxArea(arr, n) << endl;

    return 0;
}
