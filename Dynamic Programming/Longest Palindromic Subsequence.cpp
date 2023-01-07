/*	516. Longest Palindromic Subsequence
	Given a string s, find the longest palindromic subsequence's length in s.
	A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without 
	changing the order of the remaining elements.
		Input: s = "bbbab"
		Output: 4
		Explanation: One possible longest palindromic subsequence is "bbbb".	
*/

class Solution {
public:
    //Memorization--> TC: O(M^2)    SC: O(M^2)
    /*int utilFunc(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j] = 1 + utilFunc(i-1, j-1, s1, s2, dp);
        return dp[i][j] = max(utilFunc(i-1, j, s1, s2, dp), utilFunc(i, j-1, s1, s2, dp));
    }
    int findLCSLength(string &s1, string &s2){
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return utilFunc(m-1, n-1, s1, s2, dp);
    }
    int longestPalindromeSubseq(string s) {
        string rev=s;
        reverse(rev.begin(), rev.end());
        int ans = findLCSLength(s, rev);
        return ans;
    }*/

    //Tabulation
    /*int findLCSLength(string &s1, string &s2){
        int m = s1.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]= 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);    
            }
        }
        return dp[m][m];
    }
    int longestPalindromeSubseq(string s) {
        string rev=s;
        reverse(rev.begin(), rev.end());
        int ans = findLCSLength(s, rev);
        return ans;
    }*/

    //Space Optimization--> TC: O(M^2)    SC: O(M)
    /*int findLCSLength(string &s1, string &s2){
        int m = s1.size();
        vector<int> curr(m+1, 0); 
        vector<int> prev(m+1, 0);
        for(int i=1; i<=m; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1]==s2[j-1])
                    curr[j]= 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);    
            }
            prev=curr;
        }
        return prev[m];
    }
    int longestPalindromeSubseq(string s) {
        string rev=s;
        reverse(rev.begin(), rev.end());
        int ans = findLCSLength(s, rev);
        return ans;
    }*/

    // using palindrome approach--> Memorization
    /*int findLPSLength(int i, int j, string &s, vector<vector<int>> &dp){
        if(i>j)
            return 0;
        if(i==j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==s[j])
            return dp[i][j] = 2 + findLPSLength(i+1, j-1, s, dp);
        else
            return dp[i][j] = max(findLPSLength(i, j-1, s, dp), findLPSLength(i+1, j, s, dp));               
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int i=0, j=n-1;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return findLPSLength(i, j, s, dp);
    }*/

    //Tabulation:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //case when there is only character in substring i.e., i and j points to same character.
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        // when there are more than 2 charcters in the substring to consider for findding palindromic subsequences
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);                
            }
        }
        return dp[0][n-1];
    }
};
