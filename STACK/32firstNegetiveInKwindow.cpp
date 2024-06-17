#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> ans;
    queue<long long> q;

    // Initialize the first window
    for(int i = 0; i < K - 1; i++) {
        if(A[i] < 0) q.push(A[i]);
    }

    // Process the rest of the windows
    for(int i = K - 1; i < N; i++) {
        if(A[i] < 0) q.push(A[i]);
        if(!q.empty()) {
            ans.push_back(q.front());
            if(q.front() == A[i - K + 1]) // if front element matches the outgoing element then pop
                q.pop();
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}

int main() {
    // Example input
    long long A[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long N = sizeof(A) / sizeof(A[0]);
    long long K = 3;

    // Function call and output the result
    vector<long long> result = printFirstNegativeInteger(A, N, K);
    for(long long x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
