/*
Time Complexity: O(N*logN)   - sort ke  liye  
Auxiliary Space: O(1)

*/








// C++ program to find the smallest number which greater than a given number 
// and has same set of digits as given number 
#include <iostream> 
#include <cstring> 
#include <algorithm> 
using namespace std; 

void swap(char *a, char *b) 
{ 
	char temp = *a; 
	*a = *b; 
	*b = temp; 
} 

void findNext(char number[], int n) 
{ 
	int i, j; 

	for (i = n-1; i > 0; i--) 
		if (number[i] > number[i-1])    // left>right
		break; 

	if (i==0) 
	{ 
		cout << "Next number is not possible"; 
		return; 
	} 

	int x = number[i-1], smallest = i;      //smallest in right = i
	for (j = i+1; j < n; j++) 
		if (number[j] > x && number[j] < number[smallest])   
			smallest = j; 

	swap(&number[smallest], &number[i-1]); 
	sort(number + i, number + n); 

	cout << number; 

	return; 
} 

int main() 
{ 
	char digits[] = "534976"; 
	int n = strlen(digits); 
	findNext(digits, n); 
	return 0; 
} 
