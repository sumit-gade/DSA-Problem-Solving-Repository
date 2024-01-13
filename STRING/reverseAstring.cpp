#include<iostream>
using namespace std;


string reverseWord(string str)
    {
       int n=str.length();
       int end=n-1;
       int start=0;
       
       
       while(start<end)
       {
           int temp=str[start];
           str[start]=str[end];
           str[end]=temp;
           start++;
           end--;
       }
       return str;
    }

int main(){

   string str = "SUMIT";
   
    cout <<reverseWord(str);
    
     return 0;
}