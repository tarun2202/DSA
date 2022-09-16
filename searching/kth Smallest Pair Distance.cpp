/*	719. Find K-th Smallest Pair Distance
	The distance of a pair of integers a and b is defined as the absolute difference between a and b.
	Given an integer array nums and an integer k, return the kth smallest distance among all the pairs 
	nums[i] and nums[j] where 0 <= i < j < nums.length.
	
		Input: nums = [1,3,1], k = 1
		Output: 0
		Explanation: Here are all the pairs:
			(1,3) -> 2
			(1,1) -> 0
			(3,1) -> 2
		Then the 1st smallest distance pair is (1,1), and its distance is 0.
		
	time complexity: O(n.(Log(n))^2 )
	space complexity: O(1)

*/

#include <bits/stdc++.h>
using namespace std;
long long countSmallerPair(long long n, vector<int>&nums,long long k,long long mid){
	long long count=0;
	for(long long i=1;i<n;i++){
		long long curr=nums[i];
		long long low=i+1,high=n-1, m;
		while(low<=high){
			mid=low+(high-low)/2;
			if(nums[i]-curr > m)
				high=mid-1;
			else{
				count+=mid;
				low=mid+1;
			}	
		}
	}
	return count;
}
long long findSmallestPairDistance(int n,vector<int> &nums,long long k){
	long long left=1, right=nums[n-1]-nums[0], mid, ans=0;
	while(left<=right){
		mid=left+(right-left)/2;
		if(countSmallerPair(n,nums,k,mid)<k)
			left=right+1;
		else{
			if(countSmallerPair(n,nums,k,mid-1)<k){
				ans=mid;
				break;
			}
			else
				right=mid-1;
		}	
	}
	return ans;
}
int main() {
    int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	sort(nums.begin(),nums.end());	
	long long k;
	cin>>k;
	cout<<findSmallestPairDistance(n,nums,k);
}
