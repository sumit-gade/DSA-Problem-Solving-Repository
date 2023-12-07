#include<iostream>
using namespace std;


 int minSwap(int arr[], int n, int k) {
        int cnt=0;
        
        for(int i=0;i<n;i++) 
        {
            if(arr[i]<=k)
            {
                cnt++;   // kitne less then or equal hai sabko count kr liya array me
            }
        }
        
        int current_window=0;
        
        for(int i=0; i<cnt; i++)
        {
            if(arr[i]<=k)
            {
                current_window++;
            }
            
        }
        
        int ans= cnt-current_window;
        
        for(int i=cnt;i<n;i++)
        {
            if(arr[i]<=k)
            {
                current_window++;
            }
            
            if(arr[i-cnt]<=k)
            {
                current_window--;
            }
            ans=min(ans,cnt-current_window);
        }
        return ans;
        
        
        
        
    }

int main(){
     const int size = 6;
    int arr[size] = {2, 1, 5, 6, 3, 4};
    int k = 3;

    int result = minSwap(arr, size, k);

    std::cout << "Minimum swaps required: " << result << std::endl;

     return 0;
}