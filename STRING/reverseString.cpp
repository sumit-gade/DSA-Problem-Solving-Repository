#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    int st = 0;
    int e = s.size() - 1;

    while (st < e) {
        swap(s[st++], s[e--]);
    }
}

int main() {
  

    // Create a vector of characters
    vector<char> myString = {'H', 'e', 'l', 'l', 'o'};

    // Display the original string
    cout << "Original String: ";
    for (char c : myString) {
        cout << c;
    }
    cout << endl;

    // Reverse the string using the reverseString function
    reverseString(myString);

    // Display the reversed string
    cout << "Reversed String: ";
    for (char c : myString) {
        cout << c;
    }
    cout << endl;

    return 0;
}
