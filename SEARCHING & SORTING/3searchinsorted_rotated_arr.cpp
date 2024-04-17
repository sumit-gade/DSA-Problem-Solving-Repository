#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int>& nums, int target, int start, int end) {
    int l = start, r = end;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int findMin(vector<int>& nums) {
    int n = nums.size();
    int start = 0, end = n - 1;
    if (nums[start] < nums[end]) {
        return 0;
    }
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]) {
            return mid;
        }
        if (nums[mid] <= nums[end]) { // jo part sorted hai wahi part me me krna hai
            end = mid - 1; // here left part is small
        } else if (nums[start] <= nums[mid]) {
            start = mid + 1; // here right
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int min_index = findMin(nums);
    int a1 = BinarySearch(nums, target, 0, min_index - 1); // in half-half binary search
    int a2 = BinarySearch(nums, target, min_index, n - 1);
    if (a1 == -1)
        return a2;
    else
        return a1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << "Index of " << target << " in the array: " << search(nums, target) << endl;
    return 0;
}
