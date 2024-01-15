#include<iostream>
#include<vector>
using namespace std;

    int findDuplicate(vector<int>& nums) {


      int tortoise = nums[0];
    int hare = nums[0];

    // Phase 1: Detect if there is a cycle
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Phase 2: Find the entrance to the cycle
    tortoise = nums[0];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    // The entry point of the cycle is the repeated number
    return tortoise;


    }





    int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    int result = findDuplicate(nums);
    cout << "The repeated number is: " << result << endl;

    return 0;
}
    

