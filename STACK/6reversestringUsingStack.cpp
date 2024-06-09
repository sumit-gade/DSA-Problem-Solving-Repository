#include <iostream>
#include <stack>
using namespace std;

char* reverse(char *S, int len)
{
    stack<char> st;
    for(int i = 0; i < len; i++)
    {
        st.push(S[i]);
    }
    
    for(int i = 0; i < len; i++)
    {
        S[i] = st.top();  // Corrected the assignment operator
        st.pop();
    }
    
    return S;
}

int main() {
    char str[] = "Hello";
    int len = sizeof(str) / sizeof(str[0]) - 1; // Exclude the null terminator
    cout << "Original: " << str << endl;
    reverse(str, len);
    cout << "Reversed: " << str << endl;
    return 0;
}
