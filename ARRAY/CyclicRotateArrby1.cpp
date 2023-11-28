/* Write a program to cyclically rotate an array by one.

Given array is 
1 2 3 4 5 
Rotated array is
5 1 2 3 4 

Time Complexity: O(n), as we need to iterate through all the elements. Where n is the number of elements in the array.
Auxiliary Space: O(1), as we are using constant space.

*/


#include <iostream>
using namespace std;

void rotate(int arr[], int n)
{

	// store the last element in a variable
	int last_el = arr[n - 1];

	// assign every value by its predecessor
	for (int i = n - 1; i > 0; i--) {
		arr[i] = arr[i - 1];
	}

	// first element will be assigned by last element
	arr[0] = last_el;
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Printing initial array
	cout << "Given array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';

	
	rotate(arr, n);

	// Printing rotated array
	cout << "\nRotated array is\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';

	return 0;
}


