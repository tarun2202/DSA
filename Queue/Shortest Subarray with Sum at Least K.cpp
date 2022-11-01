/*	862. Shortest Subarray with Sum at Least K
	Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with 
	a sum of at least k. If there is no such subarray, return -1.
		Input: nums = [2,7,3,-8,4,10], k = 12
		Output: 2
		explanation: subarray- [4,10]
		
	naive approach    -->	TC: O(n^2)	SC: O(1)
	optimised approach-->	TC: O(n)	SC: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

//naive approach- generating all possible subarrays and then looking for valid subarray
/*int shortestSubarray(vector<int>&nums, int k){
	int n=nums.size();
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=nums[j];
			if(sum>=k)
				ans=min(ans,j-i+1);
		}
	}
	return (ans==INT_MAX)? -1: ans;
}*/

//optimised approach: using the concept of sliding window and prefix Sum
int shortestSubarray(vector<int> nums, int k) {
    int n = nums.size();
    long long int presum[n];
    presum[0]=nums[0];
    for(int i=1;i<n;i++) 
        presum[i]=presum[i-1]+nums[i];
    deque<pair<long long,int>>dq;
    dq.push_back({0,-1}); // This is because in the starting, the deque is empty so if we didn't include this may miss out on things when the nums[0] itself is >=k
    int mini = INT_MAX; // The maximum possible signed integer
    for(int i=0;i<n;i++){
	    long long int val = presum[i];
	    while(!dq.empty() && dq.back().first>=val)
	        dq.pop_back();
	    dq.push_back({presum[i],i});
	    while(!dq.empty() && val-dq.front().first>=k){
		    mini = min(mini, i-dq[0].second);
		    dq.pop_front();
	    }
    }
    return (mini == INT_MAX)? -1:mini;
}

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int k;
	cin>>k;
	int ans=shortestSubarray(nums,k);
	cout<<ans;	
}
