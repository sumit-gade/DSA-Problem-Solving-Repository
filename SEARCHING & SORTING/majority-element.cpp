#include<iostream>

using namespace std;

int majorityElement(int a[], int size)
{
    int cnt = 1, res = 0;

    for (int i = 1; i < size; i++)
    {
        if (a[res] == a[i])
            cnt++;
        else
            cnt--;

        if (cnt == 0)
        {
            cnt = 1;
            res = i;
        }
    }

    cnt = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[res] == a[i])
            cnt++;
    }

    if (cnt <= (size / 2))
        return -1;
    else
        return a[res];
}





int main() {
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = majorityElement(arr, size);

    if (result != -1) {
        std::cout << "Majority element is: " << result << std::endl;
    } else {
        std::cout << "No majority element found." << std::endl;
    }

    return 0;
}
