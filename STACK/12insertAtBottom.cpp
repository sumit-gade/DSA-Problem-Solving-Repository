//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        if (st.empty()) {
            st.push(x);
            return st;
        }
        
        stack<int> temp;
        
        while (!st.empty()) {
            int curr = st.top(); // transfer elements from st to temp
            st.pop();
            temp.push(curr);
        }
        
        st.push(x); // push x at the bottom
        
        while (!temp.empty()) {
            int curr = temp.top();
            temp.pop();
            st.push(curr); // transfer elements back to st
        }
        
        return st;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp = ob.insertAtBottom(st, x);
        vector<int> v;
        while (!tmp.empty()) {
            v.push_back(tmp.top());
            tmp.pop();
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i != v.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
