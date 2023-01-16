/*	188. Best Time to Buy and Sell Stock IV
	You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an in0teger k.
	Find the maximum profit you can achieve. You may complete at most k transactions.
	Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
		Input: k = 2, prices = [2,4,1]
		Output: 2
		Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
		
*/

class Solution {
public:
    //Memorization --> TC: O(N.2.k)+O(N)     SC: O(N.2.k)
    /*int getAns(int i, int buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(i == prices.size() || k == 0)
            return 0;
        if(dp[i][buy][k] != -1)
            return dp[i][buy][k];
        int profit = 0;
        if(buy==0) //can buy stock 
            profit = max(0 + getAns(i+1, 0, k, prices, dp), 
                        -prices[i] + getAns(i+1, 1, k, prices, dp));        
        if(buy==1) //can sell stock
            profit = max(0 + getAns(i+1, 1, k, prices, dp), 
                        +prices[i] + getAns(i+1, 0, k-1, prices, dp));
        return dp[i][buy][k] = profit;                
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return getAns(0, 0, k, prices, dp);
    }*/

    //Tabulation--> TC: O(N.2.3)    SC: O(N.2.3)
    /*int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+2, 0)));
        for(int i=n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap=1; cap<=k; cap++){
                    if(buy==0)  // We can buy the stock
                        dp[i][buy][cap] = max(0 + dp[i+1][0][cap], -prices[i] + dp[i+1][1][cap]);
                    if(buy==1)  // We can sell the stock
                        dp[i][buy][cap] = max(0 + dp[i+1][1][cap],  prices[i] + dp[i+1][0][cap-1]);
                }
            }
        }
        return dp[0][0][k];
    }*/

    //Space Optimization for Tabulation--> TC: O(N.2.3)    SC: O(2.3)
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int> (k+1, 0));
        vector<vector<int>> curr(2, vector<int> (k+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap=1; cap<=k; cap++){
                    if(buy==0)  // We can buy the stock
                        curr[buy][cap] = max(0 + ahead[0][cap], -prices[i] + ahead[1][cap]);
                    if(buy==1)  // We can sell the stock
                        curr[buy][cap] = max(0 + ahead[1][cap],  prices[i] + ahead[0][cap-1]);
                }
            }
            ahead = curr;
        }
        return ahead[0][k];
    }
};
