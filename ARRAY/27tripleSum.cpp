#include<iostream>
#include<algorithm>
using namespace std;

bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        
        for(int i=0;i<n;i++)
        {
            int y=X-A[i];
            int low=i+1,high=n-1;
            
            while(low<high)
            {
                if(A[low]+A[high]==y)
                {
                    return 1;
                }
                
                
                else if(A[low]+A[high]>y)
                {
                    high--;
                }
                
              else if(A[low]+A[high]<y)
                {
                    low++;
                }
            }
        }
        
        return 0;
    }

int main() {
    int A[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(A) / sizeof(A[0]);
    int X = 22;

    if (find3Numbers(A, n, X)) {
        std::cout << "Triplet found with sum " << X << std::endl;
    } else {
        std::cout << "No triplet found with sum " << X << std::endl;
    }

    return 0;
}