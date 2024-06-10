#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    bool knows(vector<vector<int>>& M, int a, int b) {
        return M[a][b] == 1;
    }
    
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> s;
        
        // Step 1: Push all elements into the stack
        for(int i = 0; i < n; i++) {
            s.push(i);
        }   
        
        // Step 2: Get 2 elements and compare them
        while(s.size() > 1) {
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            // If a knows b, then a cannot be a celebrity, push b
            if(knows(M, a, b)) {
                s.push(b);
            }
            // If a does not know b, then b cannot be a celebrity, push a
            else {
                s.push(a);
            }
        }
        
        // Step 3: The single element in the stack is a potential celebrity
        int ans = s.top();
        
        // Verify if ans is a celebrity
        // Check if ans does not know anyone
        int zeroCount = 0;
        for(int i = 0; i < n; i++) {
            if(M[ans][i] == 0) {
                zeroCount++;
            }
        }
        
        // If ans knows someone, it cannot be a celebrity
        if(zeroCount != n) {
            return -1;
        }
        
        // Check if everyone knows ans
        int oneCount = 0;
        for(int i = 0; i < n; i++) {
            if(M[i][ans] == 1) {
                oneCount++;
            }
        }
        
        // If not everyone knows ans, it cannot be a celebrity
        if(oneCount != n - 1) {
            return -1;
        }
        
        return ans;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int n = 3;
    int result = sol.celebrity(M, n);
    
    if(result == -1) {
        cout << "No celebrity found" << endl;
    } else {
        cout << "Celebrity is person " << result << endl;
    }
    
    return 0;
}
