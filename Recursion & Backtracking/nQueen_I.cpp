/*
	The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens 
	attack each other.
	Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer 
	in any order.
	Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' 
	both indicate a queen and an empty space, respectively.
	
	Input: n = 4
	Output: [[".Q..","...Q","Q...","..Q."],
			 ["..Q.","Q...","...Q",".Q.."]]
	
	Time complexity: O(n!)
	auxillary space: O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<string> > ans; // 2D vector of strings to store the solutions
bool isSafe(int i,int j,vector<string> &board, int n){
    int row=i;
    int col=j;
    // checking if there is a queen in the same column
    //checking row;
    while(row>=0){
        if(board[row][col]=='Q') return false;
        row--;
    }

    // checking backward diagonal;         
    row=i;
    col=j;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }  
    //checking forward diagonal
    row=i;         
    col=j;
    while(row>=0 && col<n){
        if(board[row][col]=='Q') return false;
        row--;
        col++;
    }  
    return true;
}
void printBoard(vector<string> &board,int n,int i){
    //base condition- when placed queen in the all possible cell of the rows
    if(i==board.size()){
        ans.push_back(board);
        return;
    }
    // Try placing a queen on each column for a given row. 
    // Explore next row by placing Q at each valid column for the current row
    for(int j=0;j<board.size();j++){
        if(isSafe(i,j,board,n)){
            board[i][j]='Q';    //queen placed at the valid cell
            printBoard(board,n,i+1);    //exploring next row
            board[i][j]='.'; //Backtracking to get all possible solutions
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<string> board(n,string(n,'.'));  // creating an empty board 
    printBoard(board,n,0);  // calling the recursive function
    for(auto i:ans){	//works fine other ide.
        for(auto j:i){
            cout<<j<<endl;
        }
        cout<<endl;
    }
}


