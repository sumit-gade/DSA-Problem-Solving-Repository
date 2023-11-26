// Maximum and minimum of an array using minimum number of comparisons

#include<bits/stdc++.h>
using namespace std;
 
/*Pair struct is used to return  2 values*/ 

struct Pair 
{
    int min;
    int max;
}; 
 
Pair getMinMax(int arr[], int n)
{
    struct Pair minmax;     
    int i;
     
    // If there is only one element 
    
    if (n == 1)
    {
        minmax.max = arr[0];
        minmax.min = arr[0];     
        return minmax;
    } 
     
    // If there are more than one elements
   
    if (arr[0] > arr[1]) 
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    } 
    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    } 
     
    for(i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max)     
            minmax.max = arr[i];
             
        else if (arr[i] < minmax.min)     
            minmax.min = arr[i];
    }
    return minmax;
}
 

int main()
{
    int arr[] = {1,2,3,4,5,6 };
    int arr_size = 6;
     
    struct Pair minmax = getMinMax(arr, arr_size);
     
    cout << "Minimum element is "
         << minmax.min << endl;
    cout << "Maximum element is "
         << minmax.max;
          
    return 0;
} 

// Time Complexity: O(n)
