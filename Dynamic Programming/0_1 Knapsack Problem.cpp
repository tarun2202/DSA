/*	0/1 Knapsack Problem
	You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total 
	value in the knapsack.
		Input: N = 3 W = 4 values[] = {1,2,3} weight[] = {4,5,1}
		Output: 3
*/

class Solution
{
    public:
    //Memorization [Top-Down DP]--> TC: O(N*W)  SC: O(N*W)
    /*int utilFunction(int i, int W, int wt[], int val[], vector<vector<int>>&dp){
        if(W<0)
            return INT_MIN;
        if(W==0 || i<0)
            return 0;
        if(dp[i][W] != -1)
            return dp[i][W];
        int notTaken = utilFunction(i-1, W, wt, val, dp);
        int taken = val[i] + utilFunction(i-1, W-wt[i], wt, val, dp);
        dp[i][W] = max(taken, notTaken);
        return dp[i][W];
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) { 
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return utilFunction(n-1, W, wt, val, dp);
    }*/
    
    //Tabulation [Bottom-Up DP]--> TC: O(N*W)  SC: O(N*W)
    /*int knapSack(int w, int wt[], int val[], int n) { 
        vector<vector<int>> ans(n+1, vector<int>(w+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                ans[i][j]=ans[i-1][j];
                if(j>=wt[i-1])
                    ans[i][j]=max(ans[i-1][j], val[i-1]+ans[i-1][j-wt[i-1]]);
            }
        }
        return ans[n][w];
    }*/
    
    //Space optimization
    int knapSack(int w, int wt[], int val[], int n) { 
        vector<int>ans(w+1, 0);
        vector<int>temp(w+1);
        for(int i=1;i<=n;i++){
            temp[0]=0;
            for(int j=1;j<=w;j++){
                temp[j]=ans[j];
                if(j>=wt[i-1])
                    temp[j]=max(temp[j], val[i-1]+ans[j-wt[i-1]]);
            }
            ans=temp;
        }
        return ans[w];
    }
};
