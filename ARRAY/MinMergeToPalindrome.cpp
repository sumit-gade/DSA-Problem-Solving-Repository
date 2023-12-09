#include <iostream>
using namespace std;

int PalinArray(int arr[], int n)
{
    int ans = 0;
    int i = 0, j = n - 1;

    while (i < j)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else if (arr[i] < arr[j])
        {
            i++;
            arr[i] = arr[i] + arr[i - 1];
            ans++;
        }
        else
        {
            j--;
            arr[j] = arr[j] + arr[j + 1];
            ans++;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum operations needed: " << PalinArray(arr, n) << endl;

    return 0;
}
