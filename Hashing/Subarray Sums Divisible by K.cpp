/*	Subarray Sum Divisible by K
	Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible
	by k.
		Input: N=5 arr: [2 -6 3 1 2 8 2 1]  K=7
		Output: 4
		Explanation: subarray with sum divisible by k: [2 -6 3 1], [-6 3 1 2], [3 1 2 8], [1 2 8 2 1]

	Naive approach--> TC: O(n^2)	SC: O(1)	//generating all subarrays and check for sum%k for each subarray and increment count by 1 subarray of sum%k==0
	Optimised Approach--> TC: O(n)	SC: O(n)	//using the concept of hash Table
*/

#include<bits/stdc++.h>
using namespace std;
int countSubarray(int arr[], int n, int k){
	unordered_map<int,int>m;
    m.insert({0,1});
    int cnt=0, psum=0;
    for(int i=0;i<n;i++){
        psum+=arr[i];
        int rem = psum % k;
        if(rem < 0) //when rem is negative: make rem positive    
            rem += k;
        if(m.find(rem)!=m.end())
            cnt+=m[rem];
        m[rem]++;
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
