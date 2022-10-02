/*	Longest Subarray Sum Divisible by K
	Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible
	by k.
		Input: N=5 arr: [2 7 6 1 4 5]  K=3
		Output: 4
		Explanation: longest subarray with sum divisible by k: [7 6 1 4]

	Naive approach--> TC: O(n^2)	SC: O(1)	//generating all subarrays and check for sum%k for each subarray and increment count by 1 subarray of sum%k==0
	Optimised Approach--> TC: O(n)	SC: O(n)	//using the concept of hash Table
*/

#include<bits/stdc++.h>
using namespace std;
//naive approach
/*int countSubarray(int arr[], int n, int k){
	int ans=0, sum;
	for(int i=0;i<n;i++){
		sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			if(sum%k==0){
				ans=max(ans,j-i+1);
			}
		}
	}
	return ans;	
}*/
//optimised approach
int countSubarray(int arr[], int n, int k){
	unordered_map<int,int>m;
    m.insert({0,-1});
    int ans=0, psum=0;
    for(int i=0;i<n;i++){
        psum+=arr[i];
        int rem = psum % k;
        if(rem < 0) //when rem is negative: make rem positive    
            rem += k;
        if(m.find(rem)!=m.end())
            ans=max(ans,i-m[rem]);
        if(m.find(rem)==m.end())
            m.insert({rem,i});
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
	cout<<countSubarray(arr,n,k);
}
