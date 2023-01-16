/*	714. Best Time to Buy and Sell Stock with Transaction Fee
	You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
	Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
	Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
		Input: prices = [1,3,2,8,4,9], fee = 2
		Output: 8
		Explanation: The maximum profit can be achieved by:
			- Buying at prices[0] = 1
			- Selling at prices[3] = 8
			- Buying at prices[4] = 4
			- Selling at prices[5] = 9
		The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*/

class Solution {
public:
    //Memorization --> TC: O(N.2)+O(N)      SC: O(N.2)
    /*int getAns(int i, int buy, int fees, vector<int> &prices, vector<vector<int>> &dp){
        if(i == prices.size())        
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];    
        int profit = 0;
        if(buy==0)
            profit = max(0+getAns(i+1, 0, fees, prices, dp),-fees-prices[i]+getAns(i+1, 1, fees, prices, dp));
        else
            profit = max(0+ getAns(i+1, 1, fees, prices, dp), prices[i]+getAns(i+1, 0, fees, prices, dp));
        return dp[i][buy] = profit;    
    }
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return getAns(0, 0, fee, prices, dp);
    }*/

    //Tabulation --> TC: O(2.N)     SC: O(2.N)
    /*int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int i=n-1; i>=0; i--){
            for(int buy =0; buy<=1; buy++){
                if(buy==0)
                    dp[i][buy] = max(0+dp[i+1][0], -prices[i]-fee+dp[i+1][1]);
                else
                    dp[i][buy] = max(0+dp[i+1][1], prices[i]+dp[i+1][0]);    
            }
        }
        return dp[0][0];
    }*/

    //Space Optimization for Tabulation --> TC: O(2.N)     SC: O(2) ~ O(1)
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> ahead(2, 0);
        for(int i=n-1; i>=0; i--){
            for(int buy =0; buy<=1; buy++){
                if(buy==0)
                    curr[buy] = max(0 + ahead[0], -prices[i]-fee + ahead[1]);
                else
                    curr[buy] = max(0 + ahead[1], prices[i] + ahead[0]);    
            }
            ahead = curr;
        }
        return curr[0];
    }
};
