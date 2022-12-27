/*	1091. Shortest Path in Binary Matrix
	Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear 
	path, return -1.
	A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., 
	(n - 1, n - 1)) such that:
	All the visited cells of the path are 0.
	All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge 
	or a corner).
	The length of a clear path is the number of visited cells of this path.
			Input: grid = [[0,1],[1,0]]
			Output: 2
	
	time complexity: O(8*N*M) ~ O(N*M)
	space complexity: O(N*M)
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        if (r==0) return -1;
        
        int c=grid[0].size();
        if(c==0) return -1;
        
        if(grid[0][0]!=0 || grid[r-1][c-1]!=0) 
            return -1;
        
        // BFS        
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        
        vector<vector<int>> directions={{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
        grid[0][0]=1;
        while(!q.empty()) {
            auto curr=q.front();
            q.pop();
            int x=curr.first;
            int y=curr.second;
            if(x==r-1 && y==c-1) 
                return grid[x][y];
                      
            for(auto direction : directions){
                int nx=x+direction[0];
                int ny=y+direction[1];
                
                if(nx>=0 && nx<r && ny>=0 && ny<c && grid[nx][ny]==0) {
                    q.push(make_pair(nx,ny));
                    grid[nx][ny]=grid[x][y]+1;
                }
            }
        }
        return -1;     
    }
};
