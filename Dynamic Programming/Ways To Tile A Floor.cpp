/*	Ways To Tile A Floor
	Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, the task is to find the number of ways the floor 
	can be tiled. A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile. Print 
	the answer modulo 109+7.
		Input: W = 3
		Output:3
		Explanation: We need 3 tiles to tile the board of size  2 x 3. We can tile in following ways:
					1) Place all 3 tiles vertically. 
					2) Place first tile vertically. and remaining 2 tiles horizontally.
					3) Place first 2 tiles horizontally and remaining tiles vertically.
					
	time complexity: O(N)
	space complexity: O(1)				
*/

class Solution {
  public:
    //memorization--> TC: O(N)	SC: O(N)
    /*long long helper(long long i, long long n, vector<long long>&dp){
        if(i==n)    return 1;
        if(i>n)     return 0;
        if(dp[i]!=-1)   return dp[i];
        return dp[i]=(helper(i+1, n, dp)%1000000007 + helper(i+2, n, dp)%1000000007)%1000000007;
    }
    long long numberOfWays(long long n){
        vector<long long> dp(n+1, -1);
        long long i=0;
        return helper(i, n, dp);
    }*/
    
    //tabulation--> TC: O(N)	SC: O(N)
    /*long long numberOfWays(long long n) {
        vector<long long>dp(n+1,-1);
        long long m=1000000007;
        dp[0] = 1;
        dp[1] = 1;
        for(long long i=2;i<=n;i++)
            dp[i]=(dp[i-1]+dp[i-2])% m;
        return dp[n];    
    }*/
    
    //space optimization--> TC: O(N)	SC: O(1)
    long long numberOfWays(long long n) {
        //vector<long long>dp(n+1,-1);
        long long m=1000000007;
        long long prev = 1;
        long long prev2 = 1;
        for(long long i=2;i<=n;i++){
            long long curr = ((prev%m)+(prev2%m))%m;
            prev2=prev;
            prev=curr;
        }
        return prev;  
    }
};
