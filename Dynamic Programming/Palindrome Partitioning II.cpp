/*	132. Palindrome Partitioning II
	Given a string s, partition s such that every substring of the partition is a palindrome.
	Return the minimum cuts needed for a palindrome partitioning of s.
		Input: str = "ababbbabbababa"
		Output: 3
		Explaination: After 3 partitioning substrings are "a", "babbbab", "b", "ababa".
	
	time complexity: O(N^2)
	space complexity: O(N)	
*/

class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    /*int f(int i, int n, string &str, vector<int> &dp) {
        //Base case:
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];
        int minCost = INT_MAX;
        //string[i...j]
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, str)) {
                int cost = 1 + f(j + 1, n, str, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, n, s, dp) - 1;
    }*/
    
    //Tabulation--> TC: O(N^2)      SC: O(N^2)
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        for(int i=n-1; i>=0; i--){
            dp[i] = INT_MAX;
            for(int j= i; j<n; j++){
                if(isPalindrome(i, j, s)){
                    int cost = 1 + dp[j+1];
                    dp[i] = min(dp[i], cost); 
                }
            }
        } 
        return dp[0] - 1;
    }
};
