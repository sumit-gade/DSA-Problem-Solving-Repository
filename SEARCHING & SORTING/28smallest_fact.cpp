#include <iostream>

// Function to calculate the number of trailing zeroes in x!
int find_no_of_Zeroes_factorial(int x) {
    int denom = 5;  // The first power of 5
    int zeroes = 0; // Counter for trailing zeroes

    // Calculate trailing zeroes by dividing by increasing powers of 5
    while (x >= denom) {
        zeroes += (x / denom); // How many times is 5 a factor in x
        denom *= 5;            // Move to the next power of 5
    }

    return zeroes;
}

// Function to find the smallest number whose factorial has at least `n` trailing zeroes
int findNum(int n) {
    int low = 0;          // Lower bound for binary search
    int high = 5 * n;     // Upper bound for binary search
    int ans = 0;          // Variable to store the answer

    // Binary search to find the smallest number with at least `n` trailing zeroes
    while (low <= high) {
        int mid = (low + high) / 2; // Middle point of the current range
        int zeroes = find_no_of_Zeroes_factorial(mid);

        if (zeroes >= n) { // If the number of trailing zeroes in mid! is at least `n`
            ans = mid;     // Potential answer
            high = mid - 1; // Narrow the search to find a smaller number
        } else {
            low = mid + 1; // Increase the lower bound
        }
    }

    return ans; // The smallest number with at least `n` trailing zeroes in its factorial
}

int main() {
    int n;
    std::cout << "Enter the number of trailing zeroes required: ";
    std::cin >> n;

    int result = findNum(n); // Find the smallest number with at least `n` trailing zeroes
    std::cout << "The smallest number whose factorial contains at least " << n << " trailing zeroes is: " << result << std::endl;

    return 0; // End of program
}
