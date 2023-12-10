#include<bits/stdc++.h>
using namespace std;

    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        
        int top = 0;
        int bottom = r-1;
        int left = 0;
        int right = c-1;
        
        vector<int> ans;
        
        while(top<=bottom && left<=right){
            
            for(int i=left; i<=right ; i++)
                ans.push_back(matrix[top][i]);
            top++;
            
            for(int i=top;i<=bottom;i++)
                ans.push_back(matrix[i][right]);
            right--;
            
            if(top<=bottom){
                for(int i=right;i>=left;i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }
            
            if(left<=right){
                for(int i=bottom;i>=top;i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }
        
        return ans;

    }

int main() {

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int rows = matrix.size();
    int cols = matrix[0].size();

    // Call the function
    vector<int> result = spirallyTraverse(matrix, rows, cols);

    // Print the result
    cout << "Spirally Traversed Matrix: ";
    for (int num : result) {
        cout << num << " ";
    }

     return 0;
}