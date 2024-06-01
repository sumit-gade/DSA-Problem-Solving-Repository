#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> ans)
{

    while(!ans.empty())
    {
        cout<<ans.top()<<endl;
        ans.pop();
    }

}

int main(){
    stack<int> ans;
    ans.push(5);
    ans.push(10);
    ans.push(15);
    ans.push(20);

    printStack(ans);

   
     return 0;
}