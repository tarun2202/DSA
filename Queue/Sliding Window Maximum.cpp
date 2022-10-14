/*	239. Sliding Window Maximum
	You are given an array of integers nums, there is a sliding window of size k which is moving from the very left 
	of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves 
	right by one position.
	Return the max sliding window.
		Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
		Output: [3,3,5,5,6,7]
		
	naive approach--> 	  TC: O(k(n-k+1))	SC: O(1)
	optimised approach--> TC: O(n)			SC: O(k)	
*/

#include<bits/stdc++.h>
using namespace std;

//naive approach- 
/*int findMaximum(int i, int j, vector<int>&nums){
	int maxm=INT_MIN;
	for(int k=i;k<=j;k++)
		maxm=max(maxm,nums[k]);
	return maxm;
}
vector<int> findMaxInWindow(vector<int> &nums, int k){
	int n=nums.size();
	vector<int>ans;
	for(int i=0;i<n-k+1;i++)
		ans.push_back(findMaximum(i,i+k-1,nums));
	return ans;	
}*/

// Optimised approach
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;
    for (int i=0; i<nums.size(); i++) {
        if (!dq.empty() && dq.front() == i-k) 
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i>=k-1) 
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int k;
	cin>>k;	
	vector<int> ans= findMaxInWindow(nums,k);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";	
}
