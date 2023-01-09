/*	63. Unique Paths II
	You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
	The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or 
	right at any point in time.
	An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square
	that is an obstacle.
	Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
	The testcases are generated so that the answer will be less than or equal to 2 * 109.
		Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
		Output: 2
		Explanation: There is one obstacle in the middle of the 3x3 grid above.
		There are two ways to reach the bottom-right corner:
				1. Right -> Right -> Down -> Down
				2. Down -> Down -> Right -> Right
*/

class Solution {
public:
    // Memorization (Top Down DP approach)  --> TC: O(M*N)      SC: O(M*N)
    /*int countPaths(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
        // if current cell is unsafe to move: return 0
        if(obstacleGrid[i][j] == 1)
            return 0;
        //when reached destination
        if(i==0 && j==0)
            return 1;    
        
        if(dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = 0;
        if(i > 0)
            dp[i][j] += countPaths(i-1, j, obstacleGrid, dp);
        if(j > 0)
            dp[i][j] += countPaths(i, j-1, obstacleGrid, dp);        
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(m-1, n-1, obstacleGrid, dp);
    }*/

    //Tabulation--> TC: O(M*N)      SC: O(M*N)
    /*int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        //for(int i=0; i<m; i++)
           // if(obstacleGrid[i][0] == 0)
        int i=0;
        while(i<m && !obstacleGrid[i][0])
            dp[i++][0] = 1;   //possible path
        int j=0;
        while(j<n && !obstacleGrid[0][j])
            dp[0][j++] = 1;
             
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }        
        return dp[m-1][n-1];
    }*/

    //Space Optimization for Tabulation--> TC: O(M*N)      SC: O(N)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int>prev(n, 0);
        for(int i=0; i<m; i++){
            vector<int>curr(n, 0);
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1)
                    continue;
                if(i==0 && j==0 && obstacleGrid[i][j] != 1)
                    curr[j] = 1;
                if(i > 0)
                    curr[j] += prev[j];
                if(j > 0)
                    curr[j] += curr[j-1];
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
