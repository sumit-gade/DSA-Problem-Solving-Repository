#include <iostream>
#include <vector>
using namespace std;

int countBuildings(vector<int> &height) {
    if (height.empty()) return 0; // Edge case for an empty vector

    int ans = 1; // First building always has a clear view
    int mx = height[0]; // Initialize the maximum height with the first building's height

    for (int i = 1; i < height.size(); i++) {
        if (height[i] > mx) { // If current building is taller than the max so far
            mx = height[i]; // Update the max height
            ans++; // Increment the count of buildings with clear view
        }
    }

    return ans; // Return the total number of buildings with a clear view
}

int main() {
    vector<int> heights = {4, 2, 3, 7, 6, 9, 8};
    
    cout << "Number of buildings with a clear view: " << countBuildings(heights) << endl;
    
    return 0;
}
