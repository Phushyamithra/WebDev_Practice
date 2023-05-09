#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Complete this function
    vector<string> ans;
    void helper(string S, int n , int ind , string temp){
        if(ind==n){
            ans.push_back(temp);
        }
        for(int i=0;i<n;i++){
            temp=temp+S[i];
            helper(S,n,ind+1,temp);
            temp.erase(i,1);
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        helper(S,S.length(),0,"");
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}