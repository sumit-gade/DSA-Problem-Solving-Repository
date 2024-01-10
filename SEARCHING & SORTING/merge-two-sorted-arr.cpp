#include<iostream>

#include<vector>
using namespace std;

 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
       int i =0,j=0,k=0;

    while (i<m && j<n)
    {
        if(nums1[i]<nums2[j])  // dono  sorted arr ko  compare krre hai
        {
           nums1[k]=nums1[i];  // jo chota wo 3rd arr me save krro
            k++;                // 3rd arr ke index badah do
            i++;                // jo chota usse bhi bada do
        }
        else
        {
            nums1[k]=nums2[j];          //j ko ko  3rd arrr me daldo 
             k++;
            j++;                            // do same
           
        }
    }
    while(i<m)       // 1st arrr baach gaa to uske element pure copy krdo 3rd me
    {
        nums1[k]= nums1[i];       
        k++;
        i++;
    }
 
    while(j<n)                   //  2nd arr ke akrdo element copy 3rd me
    {
      nums1[k]==nums2[j];
        k++;
        j++;
    }

 }

int main(){

      vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    
     return 0;
}