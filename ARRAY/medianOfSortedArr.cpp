#include <bits/stdc++.h>

using namespace std;



	int find_median(vector<int> v)
		{
		  sort(v.begin(),v.end());
		  
		  int n=v.size();
		  
		  if(n%2==1)  //checked if odd
		  {
		      return v[n/2];
		  }
		  
		  return (v[n/2]+v[n/2-1])/2;  // for even
		}

int main() {
    vector<int> example_vector = {4, 2, 7, 1, 9, 5};
    
    int median = find_median(example_vector);
    
    cout << "Median: " << median << std::endl;

    return 0;
}
