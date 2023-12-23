#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int arr[][4], int n, int k)
{
	// Create a min-heap (priority queue) to store elements
	// in sorted order
	priority_queue<int, vector<int>, greater<int> > pq;

	// Add all elements of the 2D array to the min-heap
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pq.push(arr[i][j]);
		}
	}

	int c = 0;
	while (!pq.empty()) {
		int temp = pq.top();
		pq.pop();
		c++;

		if (c == k)
			return temp;
	}

	// If kth smallest element not found, return -1
	return -1;
}

int main()
{
	int mat[4][4] = { { 10, 20, 30, 40 },
					{ 15, 25, 35, 45 },
					{ 25, 29, 37, 48 },
					{ 32, 33, 39, 50 } };

	int res = kthSmallest(mat, 4, 7);

	cout << "7th smallest element is " << res << endl;

	return 0;
}
