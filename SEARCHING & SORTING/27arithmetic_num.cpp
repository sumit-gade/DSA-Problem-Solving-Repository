#include <iostream>

int inSequence(int A, int B, int C) {
    // If starting and target values are the same, return true
    if (A == B) {
        return 1;
    }

    // If increment is positive, ensure target is greater than start and divisible by the increment
    if (C > 0 && (B > A) && ((B - A) % C == 0)) {
        return 1;
    }

    // If increment is negative, ensure target is less than start and divisible by the absolute increment
    if (C < 0 && (B < A) && ((A - B) % -C == 0)) {
        return 1;
    }

    // If none of the above conditions are met, return false
    return 0;
}

int main() {
    // Test the function with various examples
    std::cout << "Test 1 (Expected: 1): " << inSequence(1, 5, 2) << std::endl;  // A=1, B=5, C=2; True because 5 = 1 + 2*2
    std::cout << "Test 2 (Expected: 0): " << inSequence(1, 6, 2) << std::endl;  // A=1, B=6, C=2; False because 6 is not a part of the sequence
    std::cout << "Test 3 (Expected: 1): " << inSequence(10, 2, -4) << std::endl;  // A=10, B=2, C=-4; True because 2 = 10 + (-4)*2
    std::cout << "Test 4 (Expected: 1): " << inSequence(7, 7, 0) << std::endl;  // A=7, B=7, C=0; True because B and A are the same
    std::cout << "Test 5 (Expected: 0): " << inSequence(5, 1, 0) << std::endl;  // A=5, B=1, C=0; False because C=0 means no progression unless A=B
    std::cout << "Test 6 (Expected: 1): " << inSequence(10, 10, 2) << std::endl;  // A=10, B=10, C=2; True because the sequence starts at 10 and B is 10

    return 0;
}
