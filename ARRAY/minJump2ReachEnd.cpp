
/*

Minimum no. of Jumps to reach end of an array


Time Complexity: O(n) 


*/










#include<iostream>
using namespace std;

int minJumps(int arr[], int n){
        
    int maxR = arr[0];
    int step = arr[0];
    int jump = 1;
        
    if (n == 1)
        return 0;
        
    else if (arr[0] == 0)
        return -1;
        
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                return jump ; // Corrected return value
            }
            
            maxR = max(maxR, i + arr[i]);
            step--;
            
            if (step == 0)
            {
                jump++;
                if (i >= maxR)
                {
                    return -1;
                }
                step = maxR - i;
            }
        }
    }
}

int main(){
    int arr[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Minimum number of jumps to reach the end is " << minJumps(arr, n); // Corrected function call
    return 0;
}

