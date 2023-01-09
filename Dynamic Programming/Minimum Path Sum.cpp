/*	64. Minimum Path Sum
	Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the 
	sum of all numbers along its path.
	Note: You can only move either down or right at any point in time.
		Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
		Output: 7
		Explanation: Because the path 1 ? 3 ? 1 ? 1 ? 1 minimizes the sum.
*/

class Solution {
public:
    //Memorization --> TC: O(M*N)   SC: O(M*N)
    /*int findMinSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i==0 && j==0)
            return grid[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i==0)
            return dp[i][j] = grid[i][j] + findMinSum(i, j-1, grid, dp);
        if(j==0)
            return dp[i][j] = grid[i][j] + findMinSum(i-1, j, grid, dp);             
        return dp[i][j] = grid[i][j] + min(findMinSum(i-1, j, grid, dp), findMinSum(i, j-1, grid, dp));    
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findMinSum(m-1, n-1, grid, dp); 
    }*/

    //Tabulation --> TC: O(M*N)   SC: O(M*N)
    /*int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0)
                    dp[i][j] = grid[0][0];
                else if(i==0)
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                else if(j==0)
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                else
                    dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);            
            }
        }
        return dp[m-1][n-1]; 
    }*/

    //Space Optimization --> TC: O(M*N)     SC: O(N)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0)
                    curr[j] = grid[i][j];
                else if(i==0)
                    curr[j] = grid[i][j] + curr[j-1];
                else if(j==0)
                    curr[j] = grid[i][j] + prev[j];
                else
                    curr[j] = grid[i][j] + min(prev[j], curr[j-1]);            
            }
            prev = curr;
        }
        return prev[n-1]; 
    }
};
