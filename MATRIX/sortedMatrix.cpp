/*
Time Complexity: O(N2log(N2))
Auxiliary Space: O(N2)

*/

#include <bits/stdc++.h>
using namespace std;
 
// Function to print all elements of matrix in sorted orderd
void sortedMatrix(int N, vector<vector<int> > Mat)
{
    vector<int> temp;
   
   // Store all elements of matrix into temp
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp.push_back(Mat[i][j]);
        }
    }
 
    // Sort the temp
    sort(temp.begin(), temp.end());
 
    // Print the values of temp
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " ";
    }
}
 
int main()
{
    int N = 4;
    vector<vector<int> > Mat = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 27, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
    sortedMatrix(N, Mat);
 
    return 0;
}