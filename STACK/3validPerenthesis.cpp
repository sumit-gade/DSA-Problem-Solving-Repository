#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else if ((st.top() == '(' && s[i] == ')') ||
                       (st.top() == '{' && s[i] == '}') ||
                       (st.top() == '[' && s[i] == ']')) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};

int main() {
    Solution solution;
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";

    cout << "Test 1: " << (solution.isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: " << (solution.isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3: " << (solution.isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << "Test 4: " << (solution.isValid(test4) ? "Valid" : "Invalid") << endl;
    cout << "Test 5: " << (solution.isValid(test5) ? "Valid" : "Invalid") << endl;

    return 0;
}
