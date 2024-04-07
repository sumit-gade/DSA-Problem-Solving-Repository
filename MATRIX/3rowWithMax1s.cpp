/* time compexity =O(n*LOGm)*/

#include <iostream>
#include <vector>
#include <algorithm> // for upper_bound

using namespace std;

// Function prototype
int rowWithMax1s(vector<vector<int> > arr, int n, int m);

int main() {
    // Example usage
    vector<vector<int>> arr = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 1, 1}
    };

    int n = arr.size(); // Number of rows
    int m = arr[0].size(); // Number of columns

    int max_ones_row = rowWithMax1s(arr, n, m);

    if (max_ones_row != -1) {
        cout << "Row with maximum 1s: " << max_ones_row << endl;
    } else {
        cout << "No row contains any 1s." << endl;
    }

    return 0;
}

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    int max_ones = 0;
    int max_ones_row = -1;

    for (int i = 0; i < n; i++) {
        int curr_row_ones = m - (upper_bound(arr[i].begin(), arr[i].end(), 0) - arr[i].begin());
        if (curr_row_ones > max_ones) {
            max_ones = curr_row_ones;
            max_ones_row = i;
        }
    }

    return max_ones_row;
}













/*Time Complexity:  O(m*n)
Auxiliary Space:  O(1)


#include <bits/stdc++.h>
using namespace std;
#define R 4 
#define C 4 

// Function that returns index of row 
// with maximum number of 1s. 
int rowWithMax1s(bool mat[R][C]) {
	// code here
	int rowIndex = -1 ;
	int maxCount = 0 ;
	
	for(int i = 0 ; i < R ; i++){
		int count = 0 ;
		for(int j = 0 ; j < C ; j++ ){
			if(mat[i][j] == 1){
				count++ ;
			}
		}
		if(count > maxCount){
			maxCount = count ;
			rowIndex = i ;
		}
	}
	
	return rowIndex ;
}


int main() 
{ 
	bool mat[R][C] = { {0, 0, 0, 1}, 
					   {1, 1, 1, 1}, 
					   {0, 1, 1, 1}, 
					   {0, 0, 0, 0} }; 

	cout << "Index of row with maximum 1s is " << rowWithMax1s(mat); 

	return 0; 
} */
