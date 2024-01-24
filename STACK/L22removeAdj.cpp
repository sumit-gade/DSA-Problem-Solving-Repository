#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

string removeDuplicates(string s) {
    int n = s.size(), i = 0;
    stack<char> st;  // Initialize a stack to store characters

    // Iterate through each character in the input string
    while (i < n) {
        // If the stack is empty or the top of the stack is not equal to the current character
        if (st.empty() || st.top() != s[i]) {
            st.push(s[i]);  // Push the current character onto the stack
        } else {
            st.pop();  // If the top of the stack is equal to the current character, pop from the stack
            i++;  // Move to the next character in the string
        }
    }

    string ans = "";  // String to store the answer

    // Pop elements from the stack and append them to the answer string
    while (!st.empty()) {
        char ele = st.top();
        st.pop();
        ans += ele;
    }

    reverse(ans.begin(), ans.end());  // Reverse the answer string to get the final result
    return ans;
}

int main() {
    string input = "azxxzy";
    string result = removeDuplicates(input);

    cout << "Original String: " << input << endl;
    cout << "String after removing consecutive duplicates: " << result << endl;

    return 0;
}
