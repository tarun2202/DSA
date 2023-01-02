/*	746. Min Cost Climbing Stairs
	You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, 
	you can either climb one or two steps.
	You can either start from the step with index 0, or the step with index 1.
	Return the minimum cost to reach the top of the floor.
		Input: cost = [1,100,1,1,1,100,1,1,100,1]
		Output: 6
	
	time complexity: O(N)
	space complexity: O(1)	
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        /*int dp[n];
        // base case
        if (n == 1)
            return cost[0];
        // initially to climb till 0-th or 1th stair
        dp[0] = cost[0];
        dp[1] = cost[1];
 
        // iterate for finding the cost
        for (int i = 2; i < n; i++) 
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
 
        // return the minimum
        return min(dp[n - 2],dp[n-1]);*/
        
        //space optimization--> TC: O(N)    SC: O(1)
        //prev and prev2 to remember the cost of reaching the last to stairs
        int prev=0;     
        int prev2=0;
        //traverse till nth stairs
        for(int i=0;i<n;i++){
            int currCost=cost[i]+min(prev, prev2);
            prev2=prev;
            prev=currCost;
        }
        return min(prev, prev2);    //returning the minimum cost to reach last staircase.
    }
};
