#include<iostream>
#include<vector>
using namespace std;

 void moveZeroes(vector<int>& nums) {
        int nonZero=0;
        for(int j=0; j<nums.size(); j++)
        {
          if(nums[j]!=0)
          {
            swap(nums[j],nums[nonZero]);
            nonZero++;
          }
        }
    }

int main(){
    
     vector<int> nums={ 5, 6, 0, 4, 6, 0, 9, 0, 8 }; 

      for (int num : nums)
       {
    cout << num << " ";
       }

       cout<<endl;



    // function call 
    moveZeroes(nums); 

     for (int num : nums)
      {
    cout << num << " ";
      }
    
     return 0;
}