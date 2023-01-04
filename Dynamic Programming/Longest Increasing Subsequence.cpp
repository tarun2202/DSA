/*	300. Longest Increasing Subsequence
	Given an integer array nums, return the length of the longest strictly increasing subsequence.
		Input: nums = [10,9,2,5,3,7,101,18]
		Output: 4
		Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

*/

class Solution {
public:
    //Top-Down DP [Memorization]--> TC: O(n^2)  SC: O(n^2)
    /*int findLength(int idx, int prev_idx, int n, vector<int> &arr, vector<vector<int>>&dp){
        if(idx == n)
            return 0;
        if(dp[idx][prev_idx+1] != -1)
            return dp[idx][prev_idx+1] ;   
        int notTake = 0 + findLength(idx+1, prev_idx, n, arr, dp);
        int take = 0;
        if(prev_idx == -1 || arr[idx] > arr[prev_idx])
            take = 1 + findLength(idx+1, idx, n, arr, dp);
        dp[idx][prev_idx+1] = max(take, notTake);
        return dp[idx][prev_idx+1];        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        int idx=0;
        int prev_idx=-1;
        return findLength(idx, prev_idx, n, nums, dp);
    }*/

    //Bottom-up DP [Tabulation]--> TC: O(n^2)  SC: O(n^2)
    /*int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int prev_idx=idx-1; prev_idx>=-1; prev_idx--){
                int notTake = 0 + dp[idx+1][prev_idx+1];
                int take = 0;
                if(prev_idx == -1 || nums[idx]>nums[prev_idx])
                    take = 1 + dp[idx+1][idx+1];
                dp[idx][prev_idx+1]=max(take, notTake);    
            }
        }
        return dp[0][0];
    }*/

    //Space Optimization--> TC: O(n^2)  SC: O(n)
    /*int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>curr(n+1, 0);
        vector<int>next(n+1, 0);
        for(int idx=n-1; idx>=0; idx--){
            for(int prev_idx=idx-1; prev_idx>=-1; prev_idx--){
                int notTake = 0 + next[prev_idx+1];
                int take = 0;
                if(prev_idx == -1 || nums[idx] > nums[prev_idx])
                    take = 1 + next[idx+1];
                curr[prev_idx+1] = max(take, notTake);    
            }
            next=curr;
        }
        return curr[0];
    }*/

    //optimised approach using binary search --> TC: O(N.logN)  SC: O(N)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int idx=lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return len;
    }
};
