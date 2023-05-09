//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<string> ans;
    bool check(string part){
        if(part[0]==0 && part.length()>1){
            return false;
        }
        cout<< part << endl;
        int num=stoi(part);
        if(num<0 || num>255){
            return false;
        }
        return true;
    }
    void helper(string &s,int n, int count,int index, string temp){
        if(index==n && count == 5){
            ans.push_back(temp.substr(1));
        }
        for(int st=index;st<index+3 || st < n;st++){
            string part= s.substr(st,index-st+1);
            cout<< "helper function : "+part<< endl;
            if(check(part)){
                helper(s,n,count+1,index+1,temp+'.'+part);
            }
        }
        return;
    }
    vector<string> genIp(string &s) {
        // Your code here
        int len=s.length();
        helper(s,len,0,0,"");
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends