#include <iostream>
#include <unordered_set>

int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
    std::unordered_set<int> s;
    for(int i = 0; i < n; i++) {
        s.insert(a[i]);
    }
    
    int count = 0;
    for(int i = 0; i < m; i++) {
        int key = b[i];
        
        if(s.find(key) != s.end()) {
            count++;
            s.erase(key);  // Remove the element once counted to avoid duplicate counts
        }
    }
    
    return count;
}

int main() {
    int a[] = {1, 2, 2, 3, 4};
    int b[] = {2, 2, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    
    int result = NumberofElementsInIntersection(a, b, n, m);
    std::cout << "Number of elements in the intersection of the two arrays: " << result << std::endl;
    
    return 0;
}
