/*

time complexity - O(n1+n2+n3)
space complexity-o(1)


*/


#include<iostream>
#include<vector>
using namespace std;

  vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
           int i=0,j=0,k=0;
           
           vector<int> v;
           
           while(i<n1 and j<n2 and k<n3)
           {
               if(A[i]==B[j] and B[j]==C[k])
               {
                   v.push_back(A[i]);
                   i++;j++;k++;
                   
               }
               else if(A[i]<B[j])
              {
                  i++;
              }
               
               else if(B[j]<C[k])
               {
                   j++;
               }
               
               
               else
               {
                   k++;
               }
               
               // for duplicates
               
               int xx=A[i-1];
               while(A[i]==xx)
               i++;
               
                int yy=B[j-1];
               while(B[j]==xx)
               j++;
               
                int zz=C[k-1];
               while(C[k]==xx)
               k++;
           }
           if(v.size()==0)
           return{-1};
           return v;
        }


int main() {
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {2, 5, 6};
    int C[] = {3, 4, 5, 7};

    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);
    int n3 = sizeof(C) / sizeof(C[0]);

    vector<int> result = commonElements(A, B, C, n1, n2, n3);

    cout << "Common Elements: ";
    if (result[0] == -1) {
        cout << "No common elements.";
    } else {
        for (int element : result) {
            cout << element << " ";
        }
    }

    return 0;
}