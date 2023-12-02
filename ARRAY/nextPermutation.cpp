#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




void nextPermutation(vector < int > & nums) {
  int n = nums.size(), k, l;
  for (k = n - 2; k >= 0; k--) {
    if (nums[k] < nums[k + 1]) {
      break;
    }
  }
  if (k < 0) {
    reverse(nums.begin(), nums.end());
  } 
  else 
  {
    for (l = n - 1; l > k; l--)
     {
      if (nums[l] > nums[k]) {
        break;
      }
    }
    swap(nums[k], nums[l]);
    reverse(nums.begin() + k + 1, nums.end());
  }
}

int main() {
  // Example usage
  vector<int> nums = {1, 2, 3};
  
  cout << "Original permutation: ";
  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;

  nextPermutation(nums);

  cout << "Next permutation: ";
  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
