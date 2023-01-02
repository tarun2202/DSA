/*	70. Climbing Stairs
	You are climbing a staircase. It takes n steps to reach the top.
	Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
		Input: n = 3
		Output: 3
		Explanation: There are three ways to climb to the top.
		1. 1 step + 1 step + 1 step
		2. 1 step + 2 steps
		3. 2 steps + 1 step
	
	time complexity: memorization (top-down dp)--> TC: O(N)		SC: O(N)
					 tabulation (bottom-up dp) --> TC: O(N)		SC: O(N)
					 space optimisation		   --> TC: O(N)		SC: O(1) 
*/

class Solution {
public:
    // memorization approach--> TC: O(n)    SC: O(n)
    /*int helper(int i, int n, vector<int> &dp){
        //termination condition
        if(i>n)     return 0;
        if(i==n)    return 1;
        //memorization
        if(dp[i]!=-1)   return dp[i];
        return dp[i]=helper(i+1, n, dp) + helper(i+2, n, dp);    
    }
    int climbStairs(int n) {
        int i=0;
        vector<int>dp(n+1,-1);
        return helper(i, n, dp);
    }*/

    // Tabulation--> TC: O(N)   SC: O(N)
    /*int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];    
    }*/

    // space optimization--> TC: O(N)   SC: O(1)
    int climbStairs(int n) {
       int prev=1;	// to reach 1st step--> only 1 way possible, to take 1 step
       int prev2=1;	// at 0th stair to reach 1st stair --> 1 step
        for(int i=2;i<=n;i++){
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;    
    }
};

//recursive approach--> TC: O(2^n)
/*class Solution {
public:
    int climbStairs(int n) {
        if(n==0)    return 1;
        if(n<0)     return 0;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};*/
