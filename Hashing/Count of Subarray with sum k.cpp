/*	Count Subarray with Given Sum k
	Given an array of positive and negative numbers. Find the count of subarray with sum=0.
		Input: N=5 arr: [2 1 4 -3 -2 3 -1 -2 6]
		Output: 3
		Explanation: subarray with sum 0: [1 4-3 -2 3 -1 -2], [1 4 -3 -2], [3 -1 -2]

	Naive approach--> TC: O(n^2)	SC: O(1)	//generating all subarrays and check for sum=0 for each subarray and increment count variable by 1 each time found subarray of sum =0
	Optimised Approach--> TC: O(n)	SC: O(n)	//using the concept of hash Table
*/

#include<bits/stdc++.h>
using namespace std;
int countSubarray(int arr[], int n, int k){
	unordered_map<int,int>m;
	int psum=0;
	int cnt=0;
	m.insert({psum,1}); //considering the empty prefix with sum =0
	for(int i=0;i<n;i++){
		psum += arr[i];
		if(m.find(psum-k)!=m.end()) //when exist the index where the sum=sum-k, increase counter by the frequency of that elements index
			cnt += m[psum-k];
		m[psum]++;	//updating the frequency of the current element	
	}
	return cnt;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
    int k;
    cin>>k;    
	cout<<countSubarray(arr,n,k);
}
