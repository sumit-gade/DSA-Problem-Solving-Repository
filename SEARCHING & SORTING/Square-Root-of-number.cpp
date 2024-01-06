//Square Root of a number    O(LOGN)



#include <iostream>


using namespace std;

long long int binarySearch(int n) {
    long long int s = 0;
    long long int e = n;
    long long int ans = -1;

    while (s <= e) {
        long long int mid = s + (e - s) / 2;
        long long int square = mid * mid;

        if (square == n) {
            return mid;
        }

        if (square < n) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    return ans;
}

int floorSqrt(int n) {
    return binarySearch(n);
}

int main() {
    int number = 16;  
    long long int result = floorSqrt(number);

   cout << "Square root of " << number << " is: " << result << endl;

    return 0;
}
