/*	Subarray with Given Sum=0
	Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.
		Input: N=5 arr: [4 2 -3 1 6]
		Output: Yes
		Explanation: 2, -3, 1 is the subarray with sum 0.

	Naive approach--> TC: O(n^2)	SC: O(1)	//generating all subarrays and check for sum=0 for each subarray 
	Optimised Approach--> TC: O(n)	SC: O(n)	//using the concept of hash Table
*/

#include<bits/stdc++.h>
using namespace std;
bool checkSubarray(int arr[],int n){
	unordered_map<int,int>m;
	int psum=0;
	m.insert({psum,1});
	for(int i=0;i<n;i++){
		psum += arr[i];
		if(m.find(psum)!=m.end())
			return true;
		m.insert({psum,1});	
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<checkSubarray(arr,n);
}
