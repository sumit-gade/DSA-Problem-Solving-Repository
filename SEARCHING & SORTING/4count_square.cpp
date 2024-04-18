#include <iostream>
#include <cmath>

int countSquares(int N) {
    int a = sqrt(N);
    if (a * a == N)
        return a - 1;
    else
        return a;
}

int main() {
    int num = 16; // Example: counting squares of 16
    int result = countSquares(num);
    std::cout << "Number of complete squares less than or equal to " << num << ": " << result << std::endl;
    return 0;
}
