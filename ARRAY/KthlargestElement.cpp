/* find K'th smallest element*/


#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int N, int K)
{
	
	sort(arr, arr + N);   // O(NlognN)

	// gives kth element in the sorted array
	return arr[K - 1];
}


int main()
{
	int arr[] = { 5,3,7,8,2,4 };
	int N = sizeof(arr) / sizeof(arr[0]), K = 2;

	
	cout << "K'th smallest element is "
		<< kthSmallest(arr, N, K);
	return 0;
}


