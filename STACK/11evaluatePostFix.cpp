#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string S) {
    stack<int> st;
    
    for(int i = 0; i < S.length(); i++) {
        if(S[i] >= '0' && S[i] <= '9') { // condition for operand
            st.push(S[i] - '0'); // convert character to integer
        } else { // condition for operator
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            
            switch(S[i]) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    if(op2 != 0) { // check for division by zero
                        st.push(op1 / op2);
                    } else {
                        cout << "Error: Division by zero" << endl;
                        return -1; // or handle the error as needed
                    }
                    break;
                default:
                    cout << "Error: Invalid character" << endl;
                    return -1; // handle the error for invalid character
            }
        }
    }
    
    return st.top(); // final result
}

int main() {
    // Example 1
    string postfix1 = "231*+9-";
    cout << "The result of postfix evaluation for '231*+9-' is " << evaluatePostfix(postfix1) << endl;
    
    // Example 2
    string postfix2 = "34+2*7/";
    cout << "The result of postfix evaluation for '34+2*7/' is " << evaluatePostfix(postfix2) << endl;
    
    return 0;
}
