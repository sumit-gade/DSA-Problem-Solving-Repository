
#include<iostream>
using namespace std;

      int firstOccr(int arr[], int n, int k){
          int start=0;
          int end=n-1;
          int ans=-1;

          int mid=start+(end-start)/2;

    while(start<=end){

        if(arr[mid]==k){
            ans=mid;
            end=mid-1;
            //return ans;
        }
        else if(k>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}
     int lastOccr(int arr[], int n, int k){
          int start=0;
          int end=n-1;
          int ans=-1;

          int mid=start+(end-start)/2;
     while(start<=end){

        if(arr[mid]==k){
            ans=mid;
            start=mid+1;
            //return ans;
        }
        else if(k>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
     }
    return ans;
}
int main(){

       int arr[8]={6,8,8,9,9,9,9,9};
       int f=firstOccr(arr,8,9);
       int l=lastOccr(arr,8,9);

       int ans=(l-f)+1;      //(last - first)+1

       cout<<ans<<" "<<endl;
}

