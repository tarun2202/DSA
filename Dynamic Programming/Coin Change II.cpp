/*	518. Coin Change II
	You are given an integer array coins representing coins of different denominations and an integer amount representing
	a total amount of money.
	Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination 
	of the coins, return 0.
	You may assume that you have an infinite number of each kind of coin.
	
		Input: amount = 5, coins = [1,2,5]
		Output: 4
		Explanation: there are four ways to make up the amount:
					5=5
					5=2+2+1
					5=2+1+1+1
					5=1+1+1+1+1
	
	memorization: TC: O(m*n)	SC: O(m*n)
	tabulation: TC: O(m*n)		SC: O(m*n)
	space coptimation: TC: O(m*n)	SC: O(n)					
					
*/

class Solution {
public:
    // recursive solution--> TC: exponential
    /*int findCombination(int amt, int i, vector<int> &coins){
        if(amt==0)
            return 1;
        if(amt<0)
            return 0;
        if(i<0)
            return 0;
        int taken = findCombination(amt-coins[i], i, coins);
        int notTaken = findCombination(amt, i-1, coins);
        return taken+notTaken;                
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return findCombination(amount, n-1, coins);
    }*/

    // Top-Down DP [Memorization]--> TC: O[(coins size)*(amount+1)]     SC: O[(coins size)*(amount+1)]
    /*int findCombination(int amt, int i, vector<int> &coins, vector<vector<int>> &dp){
        if(amt==0)
            return 1;
        if(amt<0)
            return 0;
        if(i<0)
            return 0;
        if(dp[i][amt]!=-1)
            return dp[i][amt];
        dp[i][amt]= findCombination(amt-coins[i], i, coins, dp) + findCombination(amt, i-1, coins, dp);
        return dp[i][amt];                
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return findCombination(amount, n-1, coins, dp);
    }*/

    //Tabulation [Bottom-Up DP]--> TC: O[(m+1)*(n+1)]     SC: O[(m+1)*(n+1)] 
    /*int change(int amount, vector<int>& coins) {
        int m=coins.size();
        int n=amount;
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        for(int i=0;i<=m;i++)
            dp[i][0]=1;
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=coins[i-1])
                    dp[i][j]+=dp[i][j-coins[i-1]];
            }
        } 
        return dp[m][n];       
    }*/

    //Space Optimisation
    int change(int amount, vector<int>& coins) {
        int m=coins.size();
        int n=amount;
        vector<int>dp(n+1, 0);
        dp[0]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(j>=coins[i-1])
                    dp[j]+=dp[j-coins[i-1]];
            }
        }
        return dp[n];
    }
};
