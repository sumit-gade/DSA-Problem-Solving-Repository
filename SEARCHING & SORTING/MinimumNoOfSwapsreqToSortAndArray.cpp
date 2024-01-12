#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


void swap(vector<int> &arr, int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}



 int minimumNumberOfSwaps(vector<int> arr, int n)
 {
    int ans=0;   // count karega kitne swaps honge
    unordered_map<int,int> m;   //ye arrray aur uske index ko sath me dtore karega
    vector<int> temp=arr; // temp arrray sorted arrray hoga

    sort(temp.begin(),temp.end());

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]=i;

    }

    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=temp[i])    //if given array is not equal to sorted arrray 
        { 
            ans++;             // count badhana hoga ans me 
            int init=arr[i];     // swap karne se pahle hamko wo given array ka index store krna hogawarna kho
            swap(arr,i,m[temp[i]]); // swap kroo jo equal nahi hai sorted arrray ke


            //update krna hoga unke index ko jo swap hua
            m[init] =m[temp[i]];
            m[temp[i]]=i;



        }
    }

    return ans;
    
    
 }

int main(){
    vector<int> arr={1,5,4,3,2};
    int n=5;
    cout<<"minimum no. of swaps required to swp an arrray is "<<minimumNumberOfSwaps(arr,n)<<endl;
     return 0;
}