/*	Shortest Distance in a Binary Maze
	Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between 
	a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 
	If the path is not possible between source cell and destination cell, then return -1.
	Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right.
		Input:
grid[][] = {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}}
		source = {0, 1}		destination = {2, 2}
	Output: 3

	time complexity: O(4*M*N) ~ O(M*N)
	space complexity: O(M*N)
*/	

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int r = grid.size();
        int c=grid[0].size();
        //edge case 1: when empty grid is given
        if (r==0 || c==0) return -1;
        //edge case 2: when source and destination is same: dist is 0
        if(source.first==destination.first && source.second==destination.second)
            return 0;
        // BFS        
        queue<pair<int,int>> q;
        q.push({source.first,source.second});
        
        int dr[]={-1, 0, 1, 0};
        int dc[]={0, 1, 0, -1};
        grid[source.first][source.second]=0;
        while(!q.empty()) {
            auto curr=q.front();
            q.pop();
            int x=curr.first;
            int y=curr.second;
            if(x==destination.first && y==destination.second) 
                return grid[x][y];
                      
            for(int i=0;i<4;i++){
                int nx=x+dr[i];
                int ny=y+dc[i];
                
                if(nx>=0 && nx<r && ny>=0 && ny<c && grid[nx][ny]==1) {
                    q.push(make_pair(nx,ny));
                    grid[nx][ny]=grid[x][y]+1;
                }
            }
        }
        return -1; 
    }
};
