#include <iostream>
#include <string>
using namespace std;

int calculate(char a) {
    if (a == 'I') {
        return 1;
    } else if (a == 'V') {
        return 5;
    } else if (a == 'X') {
        return 10;
    } else if (a == 'L') {
        return 50;
    } else if (a == 'C') {
        return 100;
    } else if (a == 'D') {
        return 500;
    } else if (a == 'M') {
        return 1000;
    }
    return 0; // If character is not a valid Roman numeral
}

int romanToDecimal(string &str) {
    int n = str.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int v1 = calculate(str[i]);
        if (i < n - 1) {
            int v2 = calculate(str[i + 1]);
            if (v1 < v2) {
                ans += v2 - v1;
                i++; // Skip the next character since it's already processed
            } else {
                ans += v1;
            }
        } else {
            ans += v1;
        }
    }
    return ans;
}

int main() {
    string romanNumeral = "XXIV";
    cout << "Roman numeral: " << romanNumeral << ", Decimal value: " << romanToDecimal(romanNumeral) << endl;
    return 0;
}
