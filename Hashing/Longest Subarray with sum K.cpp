/*	Longest Subarray with Given Sum k
	Given an array of positive and negative numbers. Find the length of longest a subarray with sum=0.
		Input: N=5 arr: [2 1 4-3 -2 3 -1 -2 6], k=8
		Output: 7
		Explanation: subarray with sum 0: [2 1 4-3 -2 3 -1 -2 6]

	Naive approach--> TC: O(n^2)	SC: O(1)	//generating all subarrays and check for sum=0 for each subarray 
	Optimised Approach--> TC: O(n)	SC: O(n)	//using the concept of hash Table
*/

#include<bits/stdc++.h>
using namespace std;
int longestSubarray(int arr[], int n, int k){
	unordered_map<int,int>m;
	int psum=0;
	int ans=0;
	m.insert({psum,-1});
	for(int i=0;i<n;i++){
		psum += arr[i];
		if(m.find(psum-k)!=m.end())
			ans=max(ans, i-m[psum-k]);
		if(m.find(psum)==m.end())
			m.insert({psum,i});		
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
    int k;
    cin>>k;    
	cout<<longestSubarray(arr,n,k);
}
