
/*


time complexity == O(n)
space same

*/








#include<iostream>
#include<vector>
using namespace std;


    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int posIndex=0,negIndex=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                ans[negIndex]=nums[i];
                negIndex+=2;

            }
            else{
                   ans[posIndex]=nums[i];
               posIndex+=2;
                
            }
        }
        return ans;

    }


int main(){

   
    vector<int> nums = {1, -2, 3, -4, 5, -6};
    vector<int> result = rearrangeArray(nums);

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Rearranged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    
     return 0;
}