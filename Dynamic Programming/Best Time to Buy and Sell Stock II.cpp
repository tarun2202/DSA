/*	122. Best Time to Buy and Sell Stock II
	You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
	On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any 
	time. However, you can buy it then immediately sell it on the same day.
	Find and return the maximum profit you can achieve.
		Input: prices = [7,1,5,3,6,4]
		Output: 7
		Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
		Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
		Total profit is 4 + 3 = 7.
		
	time complexity: O()
	space complexity: O()	
*/

class Solution {
public:
    //Memorization--> TC: O(2.N)    SC: O(2.N) + O(N)recursion stack call
    /*long getAns(vector<int> &Arr, int ind, int buy, int n, vector<vector<int>> &dp ){
        if(ind==n) return 0; //base case
        
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
            
        long profit;
        
        if(buy==0){// We can buy the stock
            profit = max(0+getAns(Arr,ind+1,0,n,dp), -Arr[ind] + getAns(Arr,ind+1,1,n,dp));
        }
        else{
        //if(buy==1){// We can sell the stock
            profit = max(0+getAns(Arr,ind+1,1,n,dp), Arr[ind] + getAns(Arr,ind+1,0,n,dp));
        }
        
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int ans = getAns(prices, 0, 0, n, dp);
        return ans;
    }*/

    //Tabulation--> TC: O(N.2)      SC: O(2.N)
    /*int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;    //corresponds to base case
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                long profit;
                if(buy==0)// We can buy the stock
                    profit = max(0 + dp[i+1][0], -prices[i] + dp[i+1][1]);
                else
                    profit = max(0 + dp[i+1][1], +prices[i] + dp[i+1][0]);
                dp[i][buy] = profit;
            }
        }
        return dp[0][0];
    }*/

    //Space Optimization--> TC: O(N)    SC: O(2)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> ahead(2, 0);
        ahead[0] = ahead[1] = 0;    //corresponds to base case
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                long profit;
                if(buy==0)// We can buy the stock
                    profit = max(0 + ahead[0], -prices[i] + ahead[1]);
                else
                    profit = max(0 + ahead[1], +prices[i] + ahead[0]);
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return curr[0];
    }
};
