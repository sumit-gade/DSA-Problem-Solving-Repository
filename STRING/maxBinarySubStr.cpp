/*
Split the binary string into substrings with equal number of 0s and 1s


Time complexity: O(N) where N is the length of the string 
Space Complexity: O(1)


*/

#include<iostream>
using namespace std;


int maxBinarySubStr(string str, int n)
{
    int count0=0,count1=0;

    /*store both count*/
    int cnt=0;
    for (int i = 0; i <n; i++)
    
    {
       if(str[i]=='0')
       count0++;

       else{
        count1++;
       }

       if(count0==count1)
       {
          cnt++;

       }
     

    }
    if (count0!=count1) {
        return -1;
    }
    return cnt;
    
}



int main(){
    string str="0100110101";
    int n=str.length();

    cout<<maxBinarySubStr(str,n);

     return 0;
}