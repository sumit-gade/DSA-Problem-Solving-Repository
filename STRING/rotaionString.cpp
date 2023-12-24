/*Time Complexity: O(N), where N is the length of the string.
Auxiliary Space: O(N)*/






// C++ program to check if two given strings
// are rotations of each other
#include <bits/stdc++.h>
using namespace std;

bool areRotations(string str1, string str2)
{
	/* Check if sizes of two strings are same */
	if (str1.length() != str2.length())
		return false;

	string temp = str1 + str1;
	return (temp.find(str2) != string::npos);
}

int main()
{
	string str1 = "AACD", str2 = "ACDA";

	
	if (areRotations(str1, str2))
		printf("Strings are rotations of each other");
	else
		printf("Strings are not rotations of each other");
	return 0;
}
