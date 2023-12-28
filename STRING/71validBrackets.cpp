#include <iostream>
#include <stack>
#include <string>

using namespace std;



bool isValidParenthesis(const std::string &expression) {
    std::stack<char> s;

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            // If opening bracket, push onto the stack
            s.push(ch);
        } else {
            // If closing bracket
            if (!s.empty()) {
                char top = s.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    // If it matches with the top of the stack, pop
                    s.pop();
                } else {
                    // Mismatch, the expression is not valid
                    return false;
                }
            } else {
                // There's no corresponding opening bracket, so it's not valid
                return false;
            }
        }
    }

    // After processing all characters, check if the stack is empty
    // If the stack is empty, all brackets were matched, and the expression is valid
    return s.empty();
}

int main() {
    
 string expression = "{[()]}";
    if (isValidParenthesis(expression)) {
        cout << "The expression is valid." << endl;
    } else {
        cout << "The expression is not valid." << endl;
    }

    return 0;
}
