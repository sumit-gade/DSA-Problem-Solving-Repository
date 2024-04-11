#include <iostream>
using namespace std;

int maxSubStr(string str) {
    int ans = 0;
    int sum = 0;
    int n = str.size();

    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            sum -= 1; // If the character is '0', decrement sum
        } else {
            sum += 1; // If the character is '1', increment sum
        }

        if (sum == 0) {
            ans++; // If sum becomes 0, increment the count of balanced substrings
        }
    }

    if (sum != 0) {
        return -1; // If sum is not zero after processing the whole string, it means string is not balanced
    }

    return ans; // Return the count of balanced substrings
}

int main() {
    string example = "0100110101";
    cout << "Maximum number of balanced substrings in '" << example << "': " << maxSubStr(example) << endl;
    return 0;
}

