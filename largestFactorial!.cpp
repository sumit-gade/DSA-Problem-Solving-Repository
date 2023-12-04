#include <iostream>
#include <vector>
#include <algorithm> // Include this header for the reverse function
using namespace std;

vector<int> factorial(int N) {
    vector<int> res;
    res.push_back(1);
    for (int x = 2; x <= N; x++) {
        int car = 0;
        for (int i = 0; i < res.size(); i++) {
            int val = res[i] * x + car;
            res[i] = val % 10;
            car = val / 10;
        }
        while (car != 0) {
            res.push_back(car % 10);
            car /= 10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int N;
    cout << "Enter a number to calculate its factorial: ";
    cin >> N;

    vector<int> result = factorial(N);

    cout << "Factorial of " << N << " is: ";
    for (int digit : result) {
        cout << digit;
    }
    cout << endl;
    return 0;
}
