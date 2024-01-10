#include<iostream>
#include<algorithm>
using namespace std;

long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr , arr+n);
	    long count=0;
	    
	    
	    for(int i=0; i<n-2;i++)
	    {
	        int  j=i+1,k=n-1;
	        
	        
	        while(j<k)
	        {
	            long long S=arr[i]+arr[j]+arr[k];
	            
	            if(S<sum)
	            {
	                count=count+(k-j);
	                j++;
	                
	            }
	                
	                else
	                
	                    k--;
	                
	            
	        }
	    }
	    
	    return count;
	    
	}


int main() {
    const int size = 6;
    long long arr[size] = {5, 1, 3, 4, 7, 9};
    long long targetSum = 12;

    long long result = countTriplets(arr, size, targetSum);

    cout << "Number of triplets with sum less than " << targetSum << ": " << result << endl;

    return 0;
}