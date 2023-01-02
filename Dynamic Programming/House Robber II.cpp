/*	213. House Robber II
	You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
	All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
	Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two 
	adjacent houses were broken into on the same night.
	Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can 
	rob tonight without alerting the police.
		Input: nums = [1,2,3,1]
		Output: 4
		Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
		Total amount you can rob = 1 + 3 = 4.
		
	time complexity: O(N)
	space complexity: O(N)	
*/

class Solution {
public:
    int helper(vector<int> &arr){
        int n=arr.size();
        int first=max(0,arr[0]);
        if(n==1)    return first;
        int second=max(first, arr[1]);
        for(int i=2;i<n;i++){
            int curr=max(arr[i]+first, second);
            first=second;
            second=curr;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return max(nums[0],0);
        vector<int>temp1, temp2;
        for(int i=0;i<n;i++){
            if(i!=0)    temp1.push_back(nums[i]);
            if(i!=n-1)  temp2.push_back(nums[i]);
        }
        return max(helper(temp1), helper(temp2));
    }
};
