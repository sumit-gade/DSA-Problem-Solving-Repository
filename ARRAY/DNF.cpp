 /*sort an array with 0, 1 and 2 */
#include <bits/stdc++.h>
using namespace std;


void sort(int a[], int n)
    {
       int l=0,m=0,h=n-1;
       
       while(m<=h){
           int x= a[m];
           if(x==0)
            {
                swap(a[l], a[m]);
                l++;
                m++;
            }
            else if(x==1)
            {
                
                m++;
            }
            else{
                swap(a[h],a[m]);
                h--;
            }

       }
    };



void printArray(int arr[], int arr_size)
{
	
	for (int i = 0; i < arr_size; i++)
		cout << arr[i] << " ";
}

// Driver Code
int main()
{
	int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sort(arr, n);

	printArray(arr, n);

	return 0;
}


