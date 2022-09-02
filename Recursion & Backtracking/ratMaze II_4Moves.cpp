/*	GFG: Rat in a Maze Problem - I
	Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination 
	at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. 
	The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
	Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it 
	while value 1 at a cell in the matrix represents that rat can be travel through it.
	Note: In a path, no cell can be visited more than one time. If the source cell is 0, 
	the rat cannot move to any other cell.
	
	Input: grid= {{1,0,0,0},
				  {1,1,0,1},
				  {1,1,0,0},
				  {0,1,1,1}}
	Output: DDRDRR DRDDRR 
	
	time complexity: O(3^(N^2)).
	auxillary space: O(L * X), L = avg. length of the path, X = number of paths.

*/

#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
vector<vector<bool> >isVisited;
bool isSafe(vector<vector<int> >& mat,int i,int j,int n){
	if(i>=0 and i<n and j>=0 and j<n and mat[i][j]!=0)
		return true;
    return false;
}
int countPath(vector<vector<int> > &mat,int i,int j,int n,string current){
	//when rat is placed at 0
	if(mat[i][j]==0) 
        return -1;  //can't reach destination
    //when encountered destination
    if(i==n-1 and j==n-1){
		//check if desitination has value 1 or not
		if(mat[i][j]==1)
			ans.push_back(current);
		return 1;
	}
	isVisited[i][j]=true;	
	//moving down
	if(isSafe(mat,i+1,j,n) and !isVisited[i+1][j])
		countPath(mat,i+1,j,n,current+"D");
	//moving left
	if(isSafe(mat,i,j-1,n) and !isVisited[i][j-1])
		countPath(mat,i,j-1,n,current+"L");
	//moving right
	if(isSafe(mat,i,j+1,n) and !isVisited[i][j+1])
		countPath(mat,i,j+1,n,current+"R");
	//moving up
	if(isSafe(mat,i-1,j,n) and !isVisited[i-1][j])
		countPath(mat,i-1,j,n,current+"U");	
	
	isVisited[i][j]=false; //backtracking
	return 1;	
}
int main(){
	vector<vector<int> >mat{{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
	int n=mat.size();
    isVisited=vector<vector<bool> >(n,vector<bool>(n,false)); //initializing using fill constructor
	int check=countPath(mat,0,0,n,"");
    if(check==1){
        for(auto i: ans)
            cout<<i<<" ";
    }
    else
        cout<<-1;        
}
