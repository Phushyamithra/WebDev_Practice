//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// As it's top down approach we doesn't need to check down diagonals and
//down rows as we won't be filling them first they would be empty
// and also left to right won't be needed as well 
class Solution{
public:
    vector<vector<int>> ans;
    bool isSafe(vector<vector<int>> &board, int row, int n, int col){
        for(int i=0;i<row;i++){ // checks row wise for any presence of other queen
            if(board[i][col]==1){
                return false;
            }
        }
        for(int i=row-1,j=col-1; i>=0&&j>=0; i--,j--){// checks left top diagonal for other queen
            if(board[i][j]==1){
                return false; 
            }
        }
        for(int i=row-1,j=col+1; i>=0&&j<n; i--,j++){// checks right top diagonal for other queen
            if(board[i][j]==1){
                return false;
            }
        }
        return true;
        
    }
    void helper(vector<vector<int>> &board, int n, int row){
        if(row==n){// Base Condition when the row comes to "N"and board completes
            vector<int> temp;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]==1){  // checking 
                                            //for the presence of 1's and adding their column number 
                                            //as they are found in board is queen position.
                        temp.push_back(j+1);
                    }
                }
            }
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<n;i++){
            if(isSafe(board,row,n,i)==true){
                board[row][i]=1;
                helper(board,n,row+1);
                board[row][i]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n,vector<int>(n,0));
        helper(board,n,0);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cout<< "enter number of test cases";
    cin>>t;
    while(t--){
        int n;
        cout<< "Enter the board size N*N";
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends