//{ Driver Code Starts
// Initial Template for C++
/*
    Sample Inputs a& outputs :
    Input:
        S = "geeksforgeek"
    Output: "gksforgk"
        Explanation: 
        g(ee)ksforg(ee)k -> gksforgk

    Input: 
        S = "abccbccba"
    Output: ""
    Explanation: 
        ab(cc)b(cc)ba->abbba->a(bbb)a->aa->(aa)->""(empty string)

*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        // code here
        
        string res=""; // to store new editied and  updated stringwith no dup at that itereation
        for(int i=0;i<s.length();){
            char c=s[i];
            int freq=0;
            while(s[i]==c){ // check for duplicates and keep incrementing i;
                freq++;
                i++;
            }
            if(freq==1){ // to check that the char is only present single time
                res+=c;
            }
        }
        if(res==s){ // Base Condition
            return res;
        }
        return rremove(res);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends