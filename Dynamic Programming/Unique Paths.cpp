/*	62. Unique Paths
	There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The 
	robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or 
	right at any point in time.
	Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the 
	bottom-right corner.
	The test cases are generated so that the answer will be less than or equal to 2 * 109.
		Input: m = 3, n = 2
		Output: 3
		Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
		1. Right -> Down -> Down
		2. Down -> Down -> Right
		3. Down -> Right -> Down
		
*/

class Solution {
public:
    // METHOD 1: 
    /*int uniquePaths(int m, int n) {
        int N=n+m-2;
        int r=m-1;
        double res=1;
        
        for(int i=1;i<=r;i++)
            res = res*(N-r+i)/i;
        return (int)res;    
    }*/

    // Memorization--> TC: O(R*C)    SC: O(R*C)
    /*int findCount(int i, int j, vector<vector<int>> &dp){
        if(i==0 || j==0)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];    
        int up = findCount(i-1, j, dp);
        int left = findCount(i, j-1, dp);
        return dp[i][j] = up + left;    
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findCount(m-1, n-1, dp);  
    }*/

    //Tabulation
    /*int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1]; 
    }*/

    // Space Optimization for bottom up DP approach
     int uniquePaths(int m, int n) {
        vector<int> prev(n, 1);
        vector<int> curr(n, 1);
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                curr[j] = prev[j] + curr[j-1];
            }
            prev = curr;
        }
        return prev[n-1]; 
    }  
};


