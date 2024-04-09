#include <iostream>
using namespace std;

string countAndSay(int n) {
    if(n == 1) {
        return "1";
    }

    // Recursive call
    string say = countAndSay(n - 1);
    string result = "";

    for(int i = 0; i < say.length(); i++) {
        char ch = say[i]; // The number to be repeated
        int count = 1;

        // Counting the repeated numbers
        while(i < say.length() - 1 && say[i] == say[i + 1]) {
            count++;
            i++;
        }

        // Appending the count and character to the result string
        result += to_string(count) + string(1, ch);
    }

    return result;
}

int main() {
    // Example usage
    int n = 9;
    cout << "The count-and-say sequence for n = " << n << " is: " << countAndSay(n) << endl;
    return 0;
}
