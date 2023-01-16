/*	309. Best Time to Buy and Sell Stock with Cooldown

*/

class Solution {
public:
    //Memorization--> TC: O(2.N)+O(N)   SC: O(N)    
    /*int getAns(int i, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(i>=prices.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];    
        int profit = 0;
        if(buy==0)
            profit = max(0+getAns(i+1, 0, prices, dp), -prices[i] + getAns(i+1, 1, prices, dp));
        else
            profit = max(0+ getAns(i+1, 1, prices, dp), prices[i] + getAns(i+2, 0, prices, dp));
        return dp[i][buy] = profit;            
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); 
        return getAns(0, 0, prices, dp);
    }*/

    //Tabulation--> TC: O(N.2)  SC: O(N.2)
    /*int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0)); 
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                if(buy==0)
                    dp[i][buy] = max(0 + dp[i+1][0], -prices[i] + dp[i+1][1]);
                else
                    dp[i][buy] = max(0 + dp[i+1][1], prices[i] + dp[i+2][0]);
            }
        }
        return dp[0][0];
    }*/

    //Space optimization for Tabulation--> TC: O(N.2)  SC: O(2)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> ahead1(2, 0);
        vector<int> ahead2(2, 0); 
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                if(buy==0)
                    curr[buy] = max(0 + ahead1[0], -prices[i] + ahead1[1]);
                else
                    curr[buy] = max(0 + ahead1[1], prices[i] + ahead2[0]);
            }
            ahead2 = ahead1;
            ahead1 = curr;
        }
        return curr[0];
    }
};
