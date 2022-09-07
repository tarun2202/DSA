/*	162. Find Peak Element
	A peak element is an element that is strictly greater than its neighbors.
	Given a 0-indexed integer array nums, find a peak element, and return its index. 
	If the array contains multiple peaks, return the index to any of the peaks.
	
	Input: nums = [1,2,1,3,5,6,4]
	Output: 5
	Explanation: Your function can return either index number 1 where the peak element is 2, or index 
				 number 5 where the peak element is 6.

*/

#include<bits/stdc++.h>
using namespace std;
//Naive Approach: using for loop --> iterate over the whole array.
//time complexity: O(n)
/*
int findPeakElement(vector<int>&arr){
	int n=arr.size();
	if(arr[0]>arr[1]) 
		return 0;
	for(int i=1;i<n-1;i++){
		if(arr[i]>arr[i+1] && arr[i]>arr[i-1])
			return i; //return the first peak element.
	}
	if(arr[n-1]>arr[n-2])
		return n-1;
}
*/

//Optimise Appraoch : using binary search 
//time complexity: O(logn)
 
int findPeakElement(vector<int>&arr){
	int n=arr.size();
	int start=0,end=n-1;
	while(start<=end){
		int mid=(start+end)/2;
		//when mid=0: return 0th element as peak--> if it is greater than 1st element
		if(mid==0)
			return (arr[0]>arr[1]) ? 0 : 1;
		//when mid=n-1: return (n-1)th element as peak--> if it is greater than (n-2)th element
		if(mid==n-1)
			return (arr[n-1]>arr[n-2]) ? n-1 : n-2;
		//when mid is in-between the array
		if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
			return mid;
		//which part to choose to implement binary search, when mid!=peak element
		//always go for part for which the neighbouring element is greater than mid, as it is guarantee that
		//in that search space we will find our peak element
		if(arr[mid+1]>arr[mid])
			start=mid+1;
		else
			end=mid-1;			
	}
	return start;//when array has only 1 element in it.
}
int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int ans=findPeakElement(nums);
	cout<<ans;	
}
