#include <iostream>

using namespace std;

int middle(int A, int B, int C) {
    if ((A > C && A < B) || (A > B && A < C))
        return A;

    if ((C > A && C < B) || (C > B && C < A))
        return C;

    else
        return B;
}

int main() {
    // Example 1
    int result1 = middle(5, 10, 8);
    cout << "Example 1: " << result1 << endl;

    // Example 2
    int result2 = middle(15, 7, 12);
    cout << "Example 2: " << result2 << endl;

    // Example 3
    int result3 = middle(3, 3, 3);
    cout << "Example 3: " << result3 << endl;

    return 0;
}
