#include<iostream>
#include<algorithm>
using namespace std;

  void sort012(int a[], int n)
    {
       int f=0,s=0,t=0;
       for(int i=0;i<n;i++)
       {
           if(a[i]==0)
           {
               f++;
           }
           else if(a[i]==1)
           {
               s++;
           }
           else
           {
               t++;
           }
       }
       
       for(int i=0;i<f;i++)
       {
           a[i]=0;
       }
       
        for(int i=f;i<f+s;i++)
       {
           a[i]=1;
       }
       
        for(int i=f+s;i<f+s+t;i++)
       {
           a[i]=2;
       }
    }

    void printArray(int arr[], int arr_size)
{
    // Iterate and print every element
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
}

int main(){

    


    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    sort012(arr, n);
 
    printArray(arr, n);
 



    
     return 0;
}