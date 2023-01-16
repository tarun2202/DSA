/*	123. Best Time to Buy and Sell Stock III
	You are given an array prices where prices[i] is the price of a given stock on the ith day.
	Find the maximum profit you can achieve. You may complete at most two transactions.
	Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
		Input: prices = [3,3,5,0,0,3,1,4]
		Output: 6
		Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
		Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

*/

class Solution {
public:
    //Memorization --> TC: O(N.2.3)+O(N)     SC: O(N.2.3)
    /*int getAns(int i, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(i == prices.size() || cap == 0)
            return 0;
        if(dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        int profit = 0;
        if(buy==0) //can buy stock 
            profit = max(0 + getAns(i+1, 0, cap, prices, dp), 
                        -prices[i] + getAns(i+1, 1, cap, prices, dp));        
        if(buy==1) //can sell stock
            profit = max(0 + getAns(i+1, 1, cap, prices, dp), 
                        +prices[i] + getAns(i+1, 0, cap-1, prices, dp));
        return dp[i][buy][cap] = profit;                
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return getAns(0, 0, 2, prices, dp);
    }*/

    //Tabulation--> TC: O(N.2.3)    SC: O(N.2.3)
    /*int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i=n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    if(buy==0)  // We can buy the stock
                        dp[i][buy][cap] = max(0 + dp[i+1][0][cap], -prices[i] + dp[i+1][1][cap]);
                    if(buy==1)  // We can sell the stock
                        dp[i][buy][cap] = max(0 + dp[i+1][1][cap],  prices[i] + dp[i+1][0][cap-1]);
                }
            }
        }
        return dp[0][0][2];
    }*/

    //Space Optimization for Tabulation--> TC: O(N.2.3)    SC: O(2.3)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int> (3, 0));
        vector<vector<int>> curr(2, vector<int> (3, 0));
        for(int i=n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    if(buy==0)  // We can buy the stock
                        curr[buy][cap] = max(0 + ahead[0][cap], -prices[i] + ahead[1][cap]);
                    if(buy==1)  // We can sell the stock
                        curr[buy][cap] = max(0 + ahead[1][cap],  prices[i] + ahead[0][cap-1]);
                }
            }
            ahead = curr;
        }
        return ahead[0][2];
    }
};
