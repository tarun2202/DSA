/*	Longest Common Substring
	Given two strings. The task is to find the length of the longest common substring.
		Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
		Output: 4
		Explanation: The longest common substring is "CDGH" which has length 4.

	time complexity: O(N^2)
	space complexity: O(N^2)
*/

class Solution{
    public:
    //Tabulation DP approach--> TC: O(N^2)  SC: O(N^2)
    /*int longestCommonSubstr (string s1, string s2, int n, int m){
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int maxLength = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    int val = 1 + dp[i-1][j-1];
                    dp[i][j] = val;
                    maxLength = max(maxLength, val);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return maxLength;
    }*/
    
    //Space Optimization --> TC: O(N^2)     SC: O(N)
    int longestCommonSubstr (string s1, string s2, int n, int m){
        vector<int> curr(m+1, 0);
        vector<int> prev(m+1, 0);
        int maxLength = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1]==s2[j-1]){
                    int val = 1 + prev[j-1];
                    curr[j] = val;
                    maxLength = max(maxLength, val);
                }
                else
                    curr[j] = 0;
            }
            prev=curr;
        }
        return maxLength;
    }
};
