#include <bits/stdc++.h>
using namespace std;

// Structure to represent a petrol pump
struct petrolPump {
    int petrol;
    int distance;
};

// Function to find the starting point of the circular tour
int tour(petrolPump p[], int n) {
    int start = 0;
    int extraFuel = 0;
    int requiredFuel = 0;

    for (int i = 0; i < n; i++) {
        extraFuel += (p[i].petrol - p[i].distance);

        if (extraFuel < 0) {
            start = i + 1;
            requiredFuel += extraFuel;
            extraFuel = 0;
        }
    }

    if (extraFuel + requiredFuel >= 0) return start;

    return -1;
}

int main() {
    // Example input
    petrolPump p[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    int n = sizeof(p) / sizeof(p[0]);

    // Finding the starting point of the circular tour
    int start = tour(p, n);

    if (start != -1) {
        cout << "The starting point of the circular tour is petrol pump " << start << endl;
    } else {
        cout << "No solution possible" << endl;
    }

    return 0;
}
