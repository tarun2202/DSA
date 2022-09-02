/*	LC 980. Unique Paths III
	You are given an m x n integer array grid where grid[i][j] could be:

		1 representing the starting square. There is exactly one starting square.
		2 representing the ending square. There is exactly one ending square.
		0 representing empty squares we can walk over.
		-1 representing obstacles that we cannot walk over.
	Return the number of 4-directional walks from the starting square to the ending square, 
	that walk over every non-obstacle square exactly once.
	
	Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
	Output: 2
	Explanation: P1: DDRUURRDLD
				 P2: RRRDLLLDRR
				 
	time complexity: O(m*n)*O(4^(m*n))

*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<bool> >isVisited;
bool isSafe(vector<vector<int> >& mat,int i,int j,int m,int n){
	if(i>=0 and i<m and j>=0 and j<n)
		if(mat[i][j]==0 || mat[i][j]==2)
			return true;
    return false;
}
int countPath(vector<vector<int> > &mat,int i,int j,int m,int n,int count0){
	//when encountered destination
	if(mat[i][j]==2)
		//if we found the desitination check whether we have covered all cells or not 
		//if no return 0 else return 1
		return (count0==-1)?1:0; 
	isVisited[i][j]=true;
	int sum=0;
	count0--;
	// check whether it's safe or not and if it's safe then check it's already visited or not
	
	//moving right
	if(isSafe(mat,i,j+1,m,n) and !isVisited[i][j+1])
		sum += countPath(mat,i,j+1,m,n,count0);
	//moving down
	if(isSafe(mat,i+1,j,m,n) and !isVisited[i+1][j])
		sum += countPath(mat,i+1,j,m,n,count0);
	//moving left
	if(isSafe(mat,i,j-1,m,n) and !isVisited[i][j-1])
		sum += countPath(mat,i,j-1,m,n,count0);
	//moving up
	if(isSafe(mat,i-1,j,m,n) and !isVisited[i-1][j])
		sum += countPath(mat,i-1,j,m,n,count0);	
	
	isVisited[i][j]=false; //backtracking
	count0++; //backtracking
	
	return sum;	
}
int main(){
	vector<vector<int> >mat{{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
	int m=mat.size();
    int n=mat[0].size();
    isVisited=vector<vector<bool> >(m,vector<bool>(n,false)); //initializing using fill constructor
	int si,sj,count0=0;		
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j]==1){
				si=i;
				sj=j;
			}
			else if(mat[i][j]==0)
				count0++;
        }
	}	
	// maintain the count of zero beacuse we have to cover all possible blocks
	int ans=countPath(mat,si,sj,m,n,count0);
	cout<<ans;
}
