/*	79. Word Search
	Given an m x n grid of characters board and a string word, return true if word exists in the grid.
	The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are 
	horizontally or vertically neighboring. The same letter cell may not be used more than once.

 	Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
	Output: true
	
	time Complexity: O(M*N*4^k) k=length of word, O(m*n)- nested for loop
	space complexity: O(k) 
	
	Approach :-
1) Traverse the board to find the first character and then call recursively for rest of the characters.
2) if index(k) reaches word.size() that means that we found the string successfully, so return true. --> Base case
3) if current character == word[k] the we recursively call in the four directions with k + 1.
4) Base case -- > if the current coordinates exceeds the board size or the current character board[x][y] != word[index] then return false.
5) Return the accumulative answer of all the four directions i.e. (left || right || up || down).

*/


#include<bits/stdc++.h>
using namespace std;
bool search(int i,int j,int m,int n,vector<vector<char>>&board,string word,int k){
	if(k==word.length())
		return true;
	if(i>=m || i<0 || j>=n || j<0 || board[i][j]!=word[k])
		return false;
	board[i][j]='#';
	bool op1=search(i+1,j,m,n,board,word,k+1); //move down
    bool op2=search(i-1,j,m,n,board,word,k+1); //move up
    bool op3=search(i,j+1,m,n,board,word,k+1); //move right
    bool op4=search(i,j-1,m,n,board,word,k+1); //move left
    board[i][j]=word[k];
    //if any of the options has able to find the rest of the word, then we have that string in the              grid
    return (op1 || op2 || op3 || op4);		
}
bool exist(vector<vector<char>>&board,string word){
	int m=board.size();
	int n=board[0].size();
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(board[i][j]==word[0])
				if(search(i,j,m,n,board,word,0))
					return true;
	return false;				
}
int main(){
	vector<vector<char>>board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	string word="ABCCED";
	cout<<exist(board,word);
}

