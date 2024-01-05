#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {

        int s=0;
        int e=arr.size()-1;

        int mid = s+(e-s)/2;

        while(s<e) /*no need of =*/
        {
            if(arr[mid]<arr[mid+1])
            {
                s=mid+1;
            }
            else
            {
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return s;

        
    }

int main() {
    vector<int> arr1 = {0, 1, 3,5,7,9,4,2};
    int peak1 = peakIndexInMountainArray(arr1);
    cout << "Peak Index for arr1: " << peak1 << std::endl; 
    return 0;
}
