#include<iostream>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {

        // no permutaiton when single element
        if(nums.size()==1)
        {
            return;
        }

        int idx1;
        for(int i=nums.size()-2;i>=0;i--)  
        {
            if(nums[i]<nums[i+1])  
            {
                idx1=i;
                break;
            }
        }

        // agar koi next permutation nahi hai to pureee array ko reverse krdo
        if(idx1<0)
        {
            reverse(nums.begin(),nums.end());
        }

        else
        {
            int idx2=0;
            for(int i=nums.size()-1;i>=0;i--)
            {
                if(nums[i]>nums[idx1])
                {
                    idx2=i; 
                    break;
                }
            }

            swap(nums[idx1],nums[idx2]);

            reverse(nums.begin()+idx1+1,nums.end());

        }
        
    }



int main() {
    // Example vector: {1, 2, 3}
    vector<int> nums = {1, 2, 3};

    // Call the nextPermutation function to find the next permutation
    nextPermutation(nums);

    // Print the next permutation
    cout << "Next Permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}