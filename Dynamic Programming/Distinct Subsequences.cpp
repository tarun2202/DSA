/*	115. Distinct Subsequences
	Given two strings s and t, return the number of distinct subsequences of s which equals t.
	The test cases are generated so that the answer fits on a 32-bit signed integer.
		Input: s = "rabbbit", t = "rabbit"
		Output: 3
*/

class Solution {
public:
    // Memorization [Top-Down DP]--> TC: O(M*N)     SC: O(M*N)
    /*int countSubsequences(string &s, int i, string &t, int j, vector<vector<int>> &dp){
        if(j == -1)
            return 1;
        if(i == -1)
            return 0;
        
        if(dp[i][j] != -1) 
            return dp[i][j];   
        
        if(s[i]==t[j])
            return dp[i][j] = countSubsequences(s, i-1, t, j-1, dp) + countSubsequences(s, i-1, t, j, dp);
        else
            return dp[i][j] = countSubsequences(s, i-1, t, j, dp);            
    } 
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return countSubsequences(s, m-1, t, n-1, dp);
    }*/

    //Tabulation [Bottom-Up DP]--> TC: O(M*N)   SC: O(M*N)
    /*int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        int mod = 1e9+7;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    
        for(int i=0; i<m+1; i++)
            dp[i][0]=1;
    
        for(int j=1; j<n+1; j++)
            dp[0][j]=0;
        
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m][n];
    }*/

    //Space Optimization for Tabulation--> TC: O(M*N)       SC: O(N)
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        int mod = 1e9+7;
        vector<int> prev(n+1, 0);
        prev[0] = 1;
        vector<int> curr(n+1);
        curr[0] = 1;
          
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1])
                    curr[j] = (prev[j-1] + prev[j]) % mod;
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return prev[n];
    }
};
