#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> getPsei(vector<int> &arr, int m) {
    stack<int> s;
    vector<int> psei(m, -1);

    for(int i = 0; i < m; i++) {
        while(!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if(!s.empty()) {
            psei[i] = s.top();
        }
        s.push(i);
    }

    return psei;
}

vector<int> getNsei(vector<int> &arr, int m) {
    stack<int> s;
    vector<int> nsei(m, m);

    for(int i = m - 1; i >= 0; i--) {
        while(!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if(!s.empty()) {
            nsei[i] = s.top();
        }
        s.push(i);
    }

    return nsei;
}

int maxAreaRectHist(vector<int> &arr, int m) {
    vector<int> nsei = getNsei(arr, m);
    vector<int> psei = getPsei(arr, m);

    int max_area = 0;

    for(int i = 0; i < m; i++) {
        int h = arr[i];
        int w = nsei[i] - psei[i] - 1;
        int curr_area = h * w;
        max_area = max(max_area, curr_area);
    }

    return max_area;
}

const int MAX = 100;

int maxArea(int M[MAX][MAX], int n, int m) {
    vector<int> histogram(m, 0);
    int max_area = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(M[i][j] == 1) {
                histogram[j]++;
            } else {
                histogram[j] = 0;
            }
        }
        max_area = max(max_area, maxAreaRectHist(histogram, m));
    }

    return max_area;
}

int main() {
    int M[MAX][MAX] = {{1, 0, 1, 0, 0},
                       {1, 0, 1, 1, 1},
                       {1, 1, 1, 1, 1},
                       {1, 0, 0, 1, 0}};

    int n = 4;
    int m = 5;

    cout << "The largest rectangular area possible in the given matrix is: " << maxArea(M, n, m) << endl;

    return 0;
}
