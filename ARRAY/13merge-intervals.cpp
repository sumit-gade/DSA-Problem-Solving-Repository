#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


    vector<vector<int>> merge(vector<vector<int>>& intervals) {

     vector<vector<int>> res;   //initiallise res

     if(intervals.size()==0)    //if size 0 return res
     {
         return res;
     }
     sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b)
     {
         return a[0]<b[0];     //sort(x,y)   x part in all intervals
     });

     vector<int>curr=intervals[0];  //initialze with first interval

     for(int i=1;i<intervals.size();i++)  // start from index[1]
     {
         if(curr[1]<intervals[i][0])  //compare index[0] of y part and index[1] of x part 
         {
             res.push_back(curr);
             curr=intervals[i];  // updtae current
         }

         else
         {
             curr[1]=max(curr[1],intervals[i][1]);   // max of interal index[0],[1] of y partwhich is [1]
         }
     }
     
     res.push_back(curr);
     return res;

        
    }





int main() {
    // Example intervals: {{1,3}, {2,6}, {8,10}, {15,18}}
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    // Call the merge function to merge overlapping intervals
    vector<vector<int>> mergedIntervals = merge(intervals);

    // Print the merged intervals
    cout << "Merged Intervals: ";
    for (const vector<int>& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}