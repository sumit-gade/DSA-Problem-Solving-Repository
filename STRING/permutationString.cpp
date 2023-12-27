//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void rec(int ind,string s, set<string>&st)
	{
	    if(ind>=s.size())
	    {
	        st.insert(s);
            return;	        
	    }
	    
	    for(int i=ind;i<s.size();i++)
	    {
	        swap(s[ind],s[i]);
	        rec(ind+1,s,st);
	        swap(s[ind],s[i]);  // this is backtracking
	    }
	}
	
	  
	  
		vector<string>find_permutation(string S)
		{
		   set<string>st;
		   rec(0,S,st);  //index-0,string in que -S  , set st
		   vector<string>ans(st.begin(), st.end());
		   return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends