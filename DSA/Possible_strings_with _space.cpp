//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<string>  spaceString(char str[]);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        char str[10000];
        cin >> str;
        vector<string> vec = spaceString(str);
        for (string s : vec) {
            cout << s << "$";
        }
        cout << endl;
    }

}

// } Driver Code Ends


/*You have to complete this function*/
vector<string> ans;

void helper(char str[], int n, char space[], int ind1, int ind2) {
    if (ind1 == n) {
        space[ind2] = '\0';
        ans.push_back(space);
        return;
    }
    space[ind2] = str[ind1];
    helper(str, n, space, ind1 + 1, ind2 + 1);

    space[ind2] = ' ';
    space[ind2 + 1] = str[ind1];
    helper(str, n, space, ind1 + 1, ind2 + 2);
}
vector<string>  spaceString(char str[])
{
    //Your code here
    int len = strlen(str);
    if (len == 1) {
        string temp;
        temp += str[0];
        ans.push_back(temp);
        return ans;
    }
    else {
        char space[2 * len];
        space[0] = str[0];
        helper(str, len, space, 1, 1);
        return ans;
    }
}