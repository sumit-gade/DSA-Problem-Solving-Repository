#include<bits/stdc++.h>

using namespace std;

   bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int>s;
        int pre_sum=0;
        for(int i=0;i<n;i++)
        {
            pre_sum+=arr[i];
            
             if(pre_sum==0)
        return true;
        
        if(s.find(pre_sum)!=s.end())
        return true;
        
        s.insert(pre_sum);
        }
        return false;
       
    }

int main() {
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (subArrayExists(arr, n)) {
        cout << "Subarray with sum 0 exists." << endl;
    } else {
        cout << "Subarray with sum 0 does not exist." << endl;
    }

    return 0;
}
