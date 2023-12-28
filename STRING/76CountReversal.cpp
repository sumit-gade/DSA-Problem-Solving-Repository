#include<iostream>
#include<stack>
using namespace std;

int countRev (string s)
{
    if(s.size()%2==1){
         return -1;
        
    }
    
    stack<char>st;
    int c=0;
    
    for(auto e:s)  // for each e =s
    {
        if(e=='{')   // open mila to push krte jao
        st.push(e);
        
        else
        {
            if(st.empty())  // empty mila to change krro c++ krke
            {
                c++;
                st.push('{');  // for open push krdo
            }
            else
            {
                st.pop();  // tehn pop krdo
            } 
            
        }
        
    }
    
    c=c+(st.size()/2);    // changes count krrlo
    return c;
   
}





    int main() {
    string input = "}}{{";
    int result = countRev(input);
    cout << "Minimum number of reversals needed: " << result << endl;
    return 0;
}

