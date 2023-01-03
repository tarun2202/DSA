/*	Knapsack with Duplicate Items
	Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
	The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
	Note: Each item can be taken any number of times.
		Input: N = 2, W = 3 val[] = {1, 1} wt[] = {2, 1}
		Output: 3
		Explanation: 1.Pick the 2nd element thrice.
					 2.Total profit = 1 + 1 + 1 = 3. Also the total weight = 1 + 1 + 1  = 3 which is <= W.

	time complexity: O(N*W)
	space complexity: O(N*W)
*/

class Solution{
public:
	//Top-Down DP [Memorization]
    int utilFunction(int i, int W, int wt[], int val[], vector<vector<int>>&dp){
        if(W<0)
            return INT_MIN;
        if(W==0 || i<0)
            return 0;
        if(dp[i][W] != -1)
            return dp[i][W];
        int notTaken = utilFunction(i-1, W, wt, val, dp);
        int taken = val[i] + utilFunction(i, W-wt[i], wt, val, dp);
        dp[i][W] = max(taken, notTaken);
        return dp[i][W];
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int n, int W, int val[], int wt[]){ 
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return utilFunction(n-1, W, wt, val, dp);
    }
};

