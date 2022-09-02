/*	Rat Maze With Multiple Jumps
	given a maze of nxn. rat has to reach destination(n-1,n-1) from source(0,0). Given that rat can only 
	move forward and downward with the multiple jumps. 
	note: ->if multiple sol. exists, shortest earliest hop is accepted.
		  ->in maze, 0 means no further movement
		  ->in a maze, non-zero means, max jump rat can make.
	
	Input: {{2,1,0,0},			Output: {{1,0,0,0},
			{3,0,0,1},					 {1,0,0,1},
			{0,1,0,1},					 {0,0,0,1},
			{0,0,0,1}}					 {0,0,0,1}}

	Time Complexity: O(n*n*k) where k is max(matrix[i][j])
	Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>>& maze,vector<vector<int>> &ans,int n,int i,int j){ //working fine in other compiler
    if(i>=n or j>=n || maze[i][j]==0)
        return false;
    return true;    
}
bool ratMaze(vector<vector<int>>& maze,vector<vector<int>>& ans,int n,int i,int j){
    if(i==n-1 and j==n-1){
        ans[i][j]=1;
        return true;
    }
    if(isSafe(maze,ans,n,i,j)){
        ans[i][j] = 1 ;
	    for(int k =1 ; k <= maze[i][j] ; k++){   
    	    if(ratMaze(maze,ans,n,i,j+k))  //move forward 
			    return true ;
    	    if(ratMaze(maze,ans,n,i+k,j)) //move downward
			    return true ;
	    }
        ans[i][j] = 0 ;
    }
    return false;  
}
vector<vector<int>> shortestPath(vector<vector<int>> &maze,vector<vector<int>> &ans){
    int n=maze.size();
    ans.resize(n,vector<int>(n,0));
    if(ratMaze(maze,ans,n,0,0))
        return ans;
    else    
        return {{-1}};    
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n,0));
    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].size();j++)
            cin>>grid[i][j];
    vector<vector<int>>ans(n,vector<int>(n,0));        
    ans= shortestPath(grid,ans);
    for(auto i:ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

