#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> previous_smaller(vector<int>& heights){
        vector<int> ans;
        stack<int> st;
        int n = heights.size();
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            int ele = (st.empty()) ? -1 : st.top();
            ans.push_back(ele);
            st.push(i);
        }
        return ans;
    }

    vector<int> next_smaller(vector<int>& heights){
        vector<int> ans(n);
        stack<int> st;
        int n = heights.size();
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            int ele = (st.empty()) ? n : st.top();
            ans[i] = ele;
            st.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        vector<int> ps = previous_smaller(heights);
        vector<int> ns = next_smaller(heights);
        
        for(int i = 0; i < n; i++){
            int curr = (ns[i] - ps[i] - 1) * heights[i];
            res = max(res, curr);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "The largest rectangle area is: " << sol.largestRectangleArea(heights) << endl;
    return 0;
}
