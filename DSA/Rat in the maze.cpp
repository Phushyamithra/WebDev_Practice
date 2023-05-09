//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    // this function is to check left and right up and down tomove or not 
    // to move left there shouldn't be any wall visited of that part should be 0 and 
    // in maze there should be 1 .
    // same conditions for all the directions
    bool isSafe(vector<vector<int>> &maze, vector<vector<int>> &visited, int n, int srcx, int srcy){
        if(srcx>=0 && srcy>=0 && srcx < n && srcy < n && maze[srcx][srcy]==1 && visited[srcx][srcy]==0){
            return true;
        }    
        return false;
    }
    void helper(vector<vector<int>> &maze , vector<vector<int>> &visited, int srcx, int srcy, int n, string temp){
        if(srcx==n-1 && srcy==n-1){ // reached the target area
            ans.push_back(temp);
            return;
        }
        visited[srcx][srcy]=1;
        if(isSafe(maze,visited,n,srcx+1,srcy)){ // calling to move down 
            helper(maze,visited,srcx+1,srcy,n,temp+"D");
        }
        if(isSafe(maze,visited,n,srcx,srcy-1)){ //calling to move left
            helper(maze,visited,srcx,srcy-1,n,temp+"L");
        }
        if(isSafe(maze,visited,n,srcx,srcy+1)){ // calling to move right
            helper(maze,visited,srcx,srcy+1,n,temp+"R");
        }
        if(isSafe(maze,visited,n,srcx-1,srcy)){ // calling to move up
            helper(maze,visited,srcx-1,srcy,n,temp+"U");
        }
        visited[srcx][srcy]=0;
    }
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        // Your code goes here
        if(maze[0][0]==0) return ans; // checks whether start is a wall or path
        vector<vector<int>> visited(n,vector<int> (n,0));
        helper(maze,visited,0,0,n,"");
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cout<< "Enter testcases"<< endl;
    cin >> t;
    while (t--) {
        int n;
        cout << " Enter the maze size ";
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        cout<< "Enter the maze : "<<  endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends