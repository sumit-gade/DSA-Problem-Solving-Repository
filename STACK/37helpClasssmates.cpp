#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> help_classmate(vector<int> arr, int n) {  
    vector<int> nsei(n, -1);
    stack<int> s;
   
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && arr[i] <= s.top()) {
            s.pop();
        }
        if(!s.empty()) {
            nsei[i] = s.top();
        }
        s.push(arr[i]);
    }

    return nsei;
}

int main() {
    // Example input
    vector<int> arr = {4, 8, 5, 2, 25};
    int n = arr.size();

    // Function call and output the result
    vector<int> result = help_classmate(arr, n);
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
