/*	72. Edit Distance
	Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
	You have the following three operations permitted on a word:
		-> Insert a character
		-> Delete a character
		-> Replace a character
	
	Input: word1 = "horse", word2 = "ros"
	Output: 3
	Explanation: horse -> rorse (replace 'h' with 'r')
				 rorse -> rose (remove 'r')
				 rose -> ros (remove 'e')
	
	time complexity: O()
	space complexity: O()			 	
*/

class Solution {
public:
    // Memorization--> TC: O(M*N)      SC: O(M*N)
    /*int findMinDis(string &w1, int i, string &w2, int j, vector<vector<int>> &dp){
        if(i == -1)
            return j+1;
        if(j == -1)
            return i+1;
        if(dp[i][j] != -1)
            return dp[i][j];    
        if(w1[i] == w2[j])
            return dp[i][j] = findMinDis(w1, i-1, w2, j-1, dp);
        int insertChar = 1 + findMinDis(w1, i, w2, j-1, dp);
        int deleteChar = 1 + findMinDis(w1, i-1, w2, j, dp);
        int replaceChar = 1 + findMinDis(w1, i-1, w2, j-1, dp);
        return dp[i][j] = min({insertChar, deleteChar, replaceChar});            
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return findMinDis(word1, m-1, word2, n-1, dp);
    }*/

    // Tabulation--> TC: O(M*N)      SC: O(M*N)
    /*int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        int minEditDis = 0;
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        // base case when w1 is empty
        for(int j=0; j<=n; j++)
            dp[0][j] = j;
        // base case when w2 is empty    
        for(int i=0; i<=m; i++)
            dp[i][0] = i;   
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});      
            }
        }    
        return dp[m][n];
    }*/

    // Space Optimization of Tabulation Approach--> TC: O(M*N)      SC: O(N)
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> curr(n+1, 0);
        vector<int> prev(n+1, 0);
        
		// base case when w1 is empty
        for(int j=0; j<=n; j++)
            prev[j] = j;  
            
        for(int i=1; i<=m; i++){
            curr[0] = i;
            for(int j=1; j<=n; j++){
                if(word1[i-1] == word2[j-1])
                    curr[j] = prev[j-1];
                else
                    curr[j] = 1 + min({prev[j-1], curr[j-1], prev[j]});      
            }
            prev = curr;
        }    
        return prev[n];
    }
};
