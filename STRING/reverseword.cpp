#include <iostream>
#include <algorithm>

using namespace std;

string reverseWords(string str) {
    // Step 1: Reverse the entire string
    reverse(str.begin(), str.end());

    int i = 0;
    int l = 0, r = 0;
    int n = str.length();

    // Step 2: Reverse each word in the reversed string (words are separated by '.')
    while (i < n) {
        // Traverse the word (until a dot is found or end of string)
        while (i < n && str[i] != '.') {
            str[r++] = str[i++];
        }

        // Reverse the word that we just encountered
        if (l < r) {
            reverse(str.begin() + l, str.begin() + r);
            l = r + 1;  // Move the left pointer to the position after the dot
        }

        // Skip over the dot and add it back
        if (i < n && str[i] == '.') {
            str[r++] = '.';
            i++;  // Skip the dot
        }
    }

    return str;
}

int main() {
    string input = "i.like.this.program.very.much";
    cout << "Original string: \"" << input << "\"" << endl;
    string output = reverseWords(input);
    cout << "Reversed words string: \"" << output << "\"" << endl;
    return 0;
}
