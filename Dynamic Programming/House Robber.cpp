/*	198. House Robber
	You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
	the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected 
	it will automatically contact the police if two adjacent houses were broken into on the same night.
	Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can 
	rob tonight without alerting the police.
		Input: nums = [2,7,9,3,1]
		Output: 12
		Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
		Total amount you can rob = 2 + 9 + 1 = 12.
	
	time complexity: O()
	space complexity: O()	
*/

class Solution {
public:
    //memorization: (top-down DP)--> TC: O(N)   SC: O(N)
    /*int maxSum(int i, int n, vector<int>&nums, vector<int>&ans){
        if(i>=n)    
            return 0;
        if(ans[i]!=-1)
            return ans[i];
        ans[i]=max(nums[i]+maxSum(i+2, n, nums, ans), maxSum(i+1, n, nums, ans));
        return ans[i];        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        vector<int>ans(n+1,-1);
        return maxSum(i, n, nums, ans);
    }*/

    //tabulation (bottom-up DP)--> TC: O(N)   SC: O(N)
    /*int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        ans[0]=max(0, nums[0]);
        if(n==1)    //when nums have only 1 element
            return ans[0];
        ans[1]=max(ans[0], nums[1]);
        for(int i=2;i<n;i++){
            ans[i]=max(nums[i]+ans[i-2], ans[i-1]);
        }
        return ans[n-1];
    }*/

    //Method 3: Space optimization--> TC: O(N)  SC: O(1)
    int rob(vector<int>& nums) {
        int n=nums.size();
        int first=max(0, nums[0]);
        if(n==1)
            return first;
        int second=max(first, nums[1]);
        for(int i=2;i<n;i++){
            int curr=max(nums[i]+first, second);
            first=second;
            second=curr;
        }
        return second;
    }
};
