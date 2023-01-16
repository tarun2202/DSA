/*	Rod Cutting
	Given a rod of length N inches and an array of prices, price[]. pricei denotes the value of a piece of length i. 
	Determine the maximum value obtainable by cutting up the rod and selling the pieces.
		Input:	N = 8	Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
		Output: 22
		Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5+17=22.
*/

class Solution{
  public:
  	//Memorization -->TC: O(N^2)	SC: O(N^2) + O(N)    
	/*int getAns(int ind, int N, int price[], vector<vector<int>> &dp){
        if(ind==0)
            return price[0]*N;
        if(dp[ind][N] != -1)
            return dp[ind][N];
        int notTaken = 0 + getAns(ind-1, N, price, dp);
        int taken=INT_MIN;
        int rodLen = ind+1;
        if(rodLen<=N)
            taken = price[ind]+getAns(ind, N-rodLen, price, dp);
        return dp[ind][N] = max(taken, notTaken);    
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return getAns(n-1, n, price, dp);
    }*/
    
    //Tabulation--> TC: O(N^2)  SC: O(N^2)
    /*int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        for(int i=0; i<=n; i++)
            dp[0][i] = price[0]*i;
        for(int ind=1; ind<n; ind++){
            for(int len=0; len<=n; len++){
                int notTaken = 0 + dp[ind-1][len];
                int taken = INT_MIN;
                int rodLen = ind+1;
                if(rodLen <= len)
                    taken = price[ind] + dp[ind][len-rodLen];
                dp[ind][len] = max(taken, notTaken);    
            }
        }    
        return dp[n-1][n];
    }*/
    
    //Space Optimization for Tabulation--> TC: O(N^2)  SC: O(N)
    int cutRod(int price[], int n) {
        vector<int> curr(n+1, 0);
        for(int i=0; i<=n; i++)
            curr[i] = price[0]*i;
        for(int ind=1; ind<n; ind++){
            for(int len=0; len<=n; len++){
                int notTaken = 0 + curr[len];
                int taken = INT_MIN;
                int rodLen = ind+1;
                if(rodLen <= len)
                    taken = price[ind] + curr[len-rodLen];
                curr[len] = max(taken, notTaken);    
            }
        }    
        return curr[n];
    }
};
