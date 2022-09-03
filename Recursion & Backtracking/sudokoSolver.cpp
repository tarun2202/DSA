/*	37. Sudoku Solver
	Write a program to solve a Sudoku puzzle by filling the empty cells.
	A sudoku solution must satisfy all of the following rules:
		Each of the digits 1-9 must occur exactly once in each row.
		Each of the digits 1-9 must occur exactly once in each column.
		Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
	The '.' character indicates empty cells.	
*/

#include<bits/stdc++.h>
using namespace std;
//function to retrieve the sub matrix number in the board
int getnum(int i , int j){
        int x = 0  ;
        if( i < 3){
            if(j < 3)   x = 0; 
            else if(j >= 3 && j < 6)    x = 1 ;
            else if(j >= 6) x = 2;
        }
        else if(i >= 3 && i < 6){
            if(j < 3)   x = 3;
            else if(j >=3 && j < 6) x = 4 ;
            else if(j >= 6) x = 5 ;
        }
        else if(i >= 6){
            if(j < 3)   x = 6 ;
            else if(j >= 3 && j < 6)  x = 7;
            else if(j >= 6) x = 8;
        }
        return  x;
    }
    void p(vector<vector<char>>&board,int i,int j,bool&ansfound,int&n,vector<vector<char>>&rf,vector<vector<char>>&cf,vector<vector<char>>&mf,vector<vector<char>>&ans){
        if(ansfound == true) //if possible arrangement found- return
            return;
        if(i == n){ //base case- when all the cells of the board has been filled
            ansfound = true;    
            ans = board ;
            return;
        }  
        //incase found a non-zero character in the board    
        if(board[i][j] != '.'){
            if(j < (n - 1))
                p(board , i , j + 1 , ansfound , n , rf, cf ,mf , ans); //calling recursive function with the next column
            else
                p(board, i + 1 , 0 , ansfound , n , rf , cf , mf , ans); //calling recursive function with the next row, 0th column
            return;
        }
        int matrixnum = getnum(i , j);  //to find matrix number- in which the current element is getting placed 
        for(char x = '1' ; x <= '9' ; x++){
            //checking if that element already exist in the ith row,ith column and in ith sub-matrix
            if(rf[i][(x - 48) - 1] == 0 && cf[j][(x - 48) - 1] == 0 && mf[matrixnum][(x - 48) - 1] == 0){
                //if exists
                board[i][j] = x;
                rf[i][(x - 48) - 1]++;  //incrementing rowFreq 
                cf[j][(x - 48) - 1]++;  //incrementing colFrew
                mf[matrixnum][(x - 48) - 1]++;  //incrementing matFreq
                if(j < (n - 1))
                    p(board , i , j + 1 , ansfound , n , rf , cf , mf , ans);   //calling recursively with next col
                else
                    p(board , i + 1 , 0 , ansfound , n , rf , cf , mf , ans);   //calling recursively with the next row and 0th col
                //backtracking
                board[i][j] = '.';
                rf[i][(x - 48) - 1]--;
                cf[j][(x - 48) - 1]--;
                mf[matrixnum][(x - 48) - 1]--;
            }
        }
    }
    //optimize algo- for choosing the value to put at a particular cell. 
    //not making 27 operations 9 ops(to find if x exixts in a particular row), 9ops(to find if x exixts in a particular row), 9 Ops(to find if x exixts in a particular sub-matrix)
    //instead make only 3 operations to choose which value to place at a particular cell- by just comparing the x with their corresponding freq array 
    void solveSudoku(vector<vector<char>>& board) {
        bool ansfound = false ; //flag variable, return true when 1st possible arrangement is found
        int n = board.size();
        int i , j ;
        char x;
        vector<vector<char>>rf; //frequency of all 9 elements in each row  
        vector<vector<char>>cf; //frequency of all 9 elements in each column
        vector<vector<char>>mf; //frequency of elements in each matrix of size (nxn)/n 
        //making frequency array for all rows of board
        for( i = 0 ; i < n ; i++){
            vector<char>nums(9, 0);
            for(j = 0 ; j < n ; j++){
                if(board[i][j] != '.'){
                     x = board[i][j];
                     nums[(x - 48) - 1]++;
                }
            }
            rf.push_back(nums);
        }  
        //making frequency array for all columns of board     
        for(j = 0 ; j < n ; j++){
            vector<char>nums1(9,0);
            for(i = 0 ; i < n ; i++){
                if(board[i][j] != '.'){
                     x = board[i][j];
                     nums1[(x - 48) - 1]++;
                }
            }
            cf.push_back(nums1);
        }       
        //making frequency array of all 9 sub-matrices of board
        for(i = 0 ; i < n ; i += 3){
            for(j = 0 ; j < n ; j += 3){
                vector<char>nums2(9,0);
                for(int i1 = i ; i1 < i + 3 ; i1++){
                    for(int j1 = j ; j1 < j + 3 ; j1++){
                        if(board[i1][j1] != '.'){
                            x = board[i1][j1];
                            nums2[(x - 48) - 1]++;
                        }
                    }
                }
                mf.push_back(nums2);
            }
        }
        vector<vector<char>> ans;
        p(board ,0 , 0 , ansfound , n , rf , cf  , mf, ans);
        board = ans;
    }
int main(){    
    int n;
    cin>>n;
    vector<vector<char>> board(n,vector<char>(n,0)); //initializing the sudoku board
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>board[i][j];
    solveSudoku(board);
    for(auto i : board){
        for(auto j : i){
            cout<<j;
        }
        cout<<endl;
    }
}

