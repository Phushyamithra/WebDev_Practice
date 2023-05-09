//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool check(int grid[N][N], int row, int col, int num){
        // row search 
        for(int i=0;i<9;i++){
            if(grid[i][col]==num){
                return false;
            }
        }
        
        // col search
        for(int j=0;j<9;j++){
            if(grid[row][j]==num){
                return false;
            }
        }
        
        // box search
        int ini = row-(row%3);
        int inj = col-(col%3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[ini+i][inj+j]==num){
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(int grid[N][N], int row , int col){
        if(row==9){
            return true; //  completed entire puzzle
                        //and is on last box end
        }
        if(col == 9 ){
            return helper(grid, row+1,0);// that particular row is checked and at 
                                        //end so moving to next row
        }
        if(grid[row][col]!=0){
            return helper(grid,row,col+1);// if there is no blank just 
                                            //continue to next ele in same row
        }
        for(int i=1;i<=9;i++){// in a particular blank starting from 0 to 9 
                                //to check which ele can be placed
            if(check(grid,row,col,i)==true){// check function checks that row , col and box 
                                            //whether that ele is there or not
                                            
                grid[row][col]=i; // if not there we will place that ele
                if(helper(grid,row,col+1)){// and continue moving to next ele 
                    return true;
                }
            }
            grid[row][col]=0;// if that's the not the right ele to place
                            //for backtrack this one 
        }
        return false;// if no solution can be found
    }
    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return helper(grid,0,0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<grid[i][j]<<" ";
            }
        }
        return;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cout<< "Enter the  number of testcases" << endl;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends