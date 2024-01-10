#include<iostream>
#include<algorithm>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    
    sort(arr, arr + size);
    
    
  /*  // take absolute value of difference
    // this does not affect the pair as A-B=diff is same as
    // B-A= -diff
    n = abs(n);*/
    
    int i=0;
    int j=1;
    
    while(i<size && j<size)
    {
        if((i!=j) && (arr[j]-arr[i]==n || arr[i]-arr[j]==n))
        {
              cout << "Pair Found: (" << arr[i] <<
                        ", " << arr[j] << ")"; 
            return true;
        }
        else if(arr[j]-arr[i]<n)
        
            j++;
        
        
        else
        
            i++;
        
    }
    
     cout << "No such pair"; 
    return false;
   
    
}

int main(){
     int arr[] = {1, 8, 30, 40, 100}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    int n = -60; 
    findPair(arr, size, n); 
    return 0; 
     return 0;
}