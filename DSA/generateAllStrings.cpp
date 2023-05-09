#include<bits/stdc++.h>
using namespace std;

vector<string> ans;

void permute(string& str, int ind, int n)
{
	// Base case
	if (ind == n)
        ans.push_back(str);
	else {
		// Permutations made
		for (int i = ind; i <= n; i++) {

			// Swapping done
			swap(str[ind], str[i]);

			// Recursion called
			permute(str, ind + 1, n);

			// backtrack
			swap(str[ind], str[i]);
		}
	}
}

int main() {
	int t;
    cout<< "Enter the  number of testcases" << endl;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		permute(str,0,str.length()-1);
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<endl;
		}
	}
	
	return 0;
}