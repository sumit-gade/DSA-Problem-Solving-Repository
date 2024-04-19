#include <iostream>
#include <limits> // Include the header file for numeric limits
using namespace std;

// Define max and min functions
int findSum(int A[], int N)
    {
     
   int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<N;i++){
    	    maxi=max(maxi,A[i]);
    	    mini=min(mini,A[i]);
    	}
    	return maxi+mini;
    }

int main() {
    int array[] = {4, 2, 6, 1, 9};
    int size = sizeof(array) / sizeof(array[0]);
    cout << "Sum of maximum and minimum element: " << findSum(array, size) << endl;
    return 0;
}
