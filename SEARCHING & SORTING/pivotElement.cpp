



#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int>& nums) {
         int len = nums.size();
        int totalSum = 0;

        for(int i =0; i<len ; i++){
            totalSum += nums[i];   /* for total sum    sum=sum+arr[i]*/
        }

        int leftSum = 0;      

        for(int i=0; i<len; i++){
            leftSum += nums[i];

            if(totalSum - leftSum   == leftSum  - nums[i]){   
             /* (toal-left)right == left - nums[i](exclude pivot index)*/
                return i;
            }
        }
        return -1;
    }

int main() {
    std::vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    int pivot1 = pivotIndex(nums1);
    std::cout << "Pivot Index for nums1: " << pivot1 << std::endl;  // Output: 3
    return 0;
}
