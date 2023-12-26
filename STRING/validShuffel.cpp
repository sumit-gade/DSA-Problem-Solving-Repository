// C++ code for the above approach:
#include <bits/stdc++.h>
using namespace std;

bool validShuffle(string str1, string str2, string shuffle)
{

	// n1 = size of str1, n2 = size of str2
	int n1 = str1.size();
	int n2 = str2.size();

	// n = size of string shuffle
	int n = shuffle.size();

	// Its obvious if the no. of char in
	// shuffle are more or less than the
	// length of str1 and str2 then it
	// won't be a valid shuffle
	if (n != n1 + n2)
		return false;

	// We use an unordered map to keep
	// track of frequency of
	// each character.
	unordered_map<char, int> freq;

	// Count frequency of each char
	// in str1
	for (int i = 0; i < n1; i++)
		freq[str1[i]]++;

	// Count frequency of each char
	// in str2
	for (int i = 0; i < n2; i++)
		freq[str2[i]]++;

	// If any of the char is not found in
	// the map, then its not a
	// valid shuffle.
	for (int i = 0; i < n; i++) {
		if (freq.find(shuffle[i]) != freq.end())
			freq[shuffle[i]]--;
		else
			return false;
	}
	return true;
}

// Drivers code
int main()
{
	string str1 = "BA", str2 = "XY", shuffle = "ABYX";

	(validShuffle(str1, str2, shuffle) == true)
		? printf("YES")
		: printf("NO");
	cout << endl;

	return 0;
}
