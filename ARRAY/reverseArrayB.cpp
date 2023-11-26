/*  Recursive Way   */

#include <bits/stdc++.h> 
using namespace std; 
  

void rvereseArray(int arr[], int start, int end) 
{ 
    if (start >= end) 
    return; 
      
    int temp = arr[start];  
    arr[start] = arr[end]; 
    arr[end] = temp; 
      
    // Recursive Function calling 
    rvereseArray(arr, start + 1, end - 1);  
}      
  
  

void printArray(int arr[], int size) 
{ 
   for (int i = 0; i < size; i++) 
   cout << arr[i] << " "; 
  
   cout << endl; 
}  
  

int main()  
{ 
    int arr[] = {1, 2, 3, 4, 5, 6}; 
      
    // To print original array 
    printArray(arr, 6); 
      
    // Function calling 
    rvereseArray(arr, 0, 5); 
      
    cout << "Reversed array is" << endl; 
      
    // To print the Reversed array 
    printArray(arr, 6); 
      
    return 0; 
} 

/*

Time Complexity: O(n)
Auxiliary Space: O(n)

*/