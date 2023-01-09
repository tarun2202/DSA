/*	44. Wildcard Matching
	Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
		'?' Matches any single character.
		'*' Matches any sequence of characters (including the empty sequence).
	The matching should cover the entire input string (not partial).
		Input: s = "aa", p = "a"
		Output: false
		Explanation: "a" does not match the entire string "aa".
	
	time complexity: O(M*N)
	space complexity: O(m*n)	
*/

class Solution {
public:
    // Memorization --> TC: O(N)+O(M*N)     SC: O(M*N)
    /*bool wildCardMatching(string &s, int i, string &p, int j, int lastIndexOfAllStar, 
                           vector<vector<int>> &dp ){
        
        // when s gets exhausted: return true if p contain only *, otherwise false.
        if(i == -1)
            return j <= lastIndexOfAllStar;
        
        //when p string gets exhausted
        if(j==-1)
            return false;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // when p[j]=='?' :ignore the current characters and compare the rest of the strings    
        if(p[j]=='?')
            return dp[i][j] = wildCardMatching(s, i-1, p, j-1, lastIndexOfAllStar, dp);
        
        //when p[j]=='*'
        //two cases: 1) when compare with empty sequence. 2) when comparing with sequence of any length[1...m]     
        if(p[j]=='*'){
            bool notTake = wildCardMatching(s, i, p, j-1, lastIndexOfAllStar, dp);
            bool take = wildCardMatching(s, i-1, p, j, lastIndexOfAllStar, dp);
            return dp[i][j] = (take || notTake);
        }
        
        // when last characters of both string matches
        return dp[i][j] = s[i]==p[j] && wildCardMatching(s, i-1, p, j-1, lastIndexOfAllStar, dp);    
    }
    
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        // precomputation to find the length of all * in p from [0....i]
        int lastIndexOfAllStar=-1;
        int i=0;
        while(i<n){
            if(p[i]=='*')
                i++;
            else
                break;    
        }
        lastIndexOfAllStar = i-1;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return wildCardMatching(s, m-1, p, n-1, lastIndexOfAllStar, dp);
    }*/

    //Tabulation -->    TC: O(N)+O(M*N)     SC: O(M*N)
    /*bool isMatch(string S, string P) {
        int m = S.size();
        int n = P.size();
        vector<vector<bool>> ans(m+1, vector<bool> (n+1, false));
        ans[0][0] = true;
        for (int j = 1; j <= n; j++)
            if (P[j - 1] == '*')
                ans[0][j] = ans[0][j - 1];
        
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (P[j - 1] == '*')
                    ans[i][j] = ans[i][j - 1] || ans[i - 1][j];
                else if (P[j - 1] == '?' || S[i - 1] == P[j - 1])
                    ans[i][j] = ans[i - 1][j - 1];
                else
                    ans[i][j] = false;
            }
        }
        return ans[m][n]; 
    }*/

    //Space Optimization of Tabulation-->    TC: O(N)+O(M*N)     SC: O(N)
    bool isMatch(string S, string P) {
        int m = S.size();
        int n = P.size();
        vector<bool> prev(n+1, false);
        vector<bool> curr(n+1, false);
        prev[0] = true;
        for (int j = 1; j <= n; j++)
            if (P[j - 1] == '*')
                prev[j] = prev[j - 1];
        
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (P[j - 1] == '*')
                    curr[j] = curr[j - 1] || prev[j];
                else if (P[j - 1] == '?' || S[i - 1] == P[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[n]; 
    }
};



