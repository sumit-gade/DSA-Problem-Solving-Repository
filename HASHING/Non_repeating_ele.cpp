#include <iostream>
#include <unordered_map>
using namespace std;

int firstNonRepeating(int arr[], int n) 
{ 
    unordered_map<int, int> ump;
    
    // First pass: count occurrences of each element
    for(int i = 0; i < n; i++)
    {
        int key = arr[i];
        ump[key]++;
    }
    
    // Second pass: find the first element with a count of 1
    for(int i = 0; i < n; i++)
    {
        int key = arr[i];
        if(ump[key] == 1)
            return key;
    }
    
    return -1; // Return -1 if no non-repeating element is found
}

int main() {
    int arr[] = {9, 4, 9, 6, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = firstNonRepeating(arr, n);
    
    if(result != -1)
        cout << "The first non-repeating element is " << result << endl;
    else
        cout << "There are no non-repeating elements in the array" << endl;
    
    return 0;
}
