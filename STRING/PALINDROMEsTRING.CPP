/* T=0(N) , S=0(1)*/
 


#include<iostream>
using namespace std;

string isPalindrome(string S)
{
    for (char i = 0; i <S.length()/2; i++)
    {

        if(S[i]!=S[S.length()-i-1])
        {
            return "NO";
        }
         
    }

    return "YES";
    
}


int main(){
     string S = "ACBA";
    cout << isPalindrome(S);
     return 0;
}
