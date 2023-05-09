//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    // helper functtion does all the work of josephus function of killing and finding safe position 
    int helper(int n,int k){ // this  function returns od 0 based indexing so on 1 based add this result +1
        
        if(n==1) return 0;
        int x=helper(n-1,k);
        int y=(x+k)%n;
        return y;
    }
    int josephus(int n, int k)
    {
       //Your code here
       if(n==1) return 1; // 1 indexing
       return helper(n,k)+1;// 1 based indexing result 
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
    cout << " testcases ";
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends