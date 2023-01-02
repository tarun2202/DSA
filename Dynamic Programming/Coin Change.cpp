/*	322. Coin Change
	You are given an integer array coins representing coins of different denominations and an integer amount representing 
	a total amount of money.
	Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by
	any combination of the coins, return -1.
		Input: coins = [1,2,5], amount = 11
		Output: 3
		Explanation: 11 = 5 + 5 + 1
	
	time complexity: O(N*M)
	space complexity: O(N)
		where N: amount value, M: size of coins[]	
*/

class Solution {
public:
    //top-down DP
    /*long minCoin(int amt, vector<int> &coins, vector<long> &ans){
        if(amt==0)
            return 0;
        if(amt<0)
            return INT_MAX;
        if(ans[amt]!=-1)
            return ans[amt];    
        ans[amt]=INT_MAX;
        for(int i=0; i<coins.size(); i++)
            ans[amt]=min(ans[amt], 1+minCoin(amt-coins[i], coins, ans));
        return ans[amt];        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<long>ans(amount+1, -1);
        long res=minCoin(amount, coins, ans);
        return (res<INT_MAX) ? res: -1;
    }*/

    // Bottom-Up DP
    int coinChange(vector<int>& coins, int amount) {
        vector<long>dp(amount+1, -1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            dp[i]=INT_MAX;
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i){
                    dp[i]=min(dp[i], 1+dp[i-coins[j]]);
                }
            }
        }
        return (dp[amount]<INT_MAX) ? dp[amount] : -1;
    }
};
