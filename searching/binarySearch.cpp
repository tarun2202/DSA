/*	704. Binary Search
	Given an array of integers nums which is sorted in ascending order, and an integer target, 
	write a function to search target in nums. If target exists, then return its index. 
	Otherwise, return -1.
	
	Input: nums = [-1,0,3,5,9,12], target = 9
	Output: 4
	Explanation: 9 exists in nums and its index is 4
	
	time complexity: O(log2n)
*/

#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&arr,int target){
	int beg = 0;
	int end = arr.size()-1;
	int mid;
	while(beg <= end){
		mid = (beg + end) / 2;
		if(target==arr[mid])
			return mid;
		else if(target>arr[mid])
			beg = mid + 1;
		else
			end = mid - 1;		
	}
	return -1;
}
int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int target;
	cin>>target;	
	int res = binarySearch(arr,target);	
	if(res!=-1)
		cout<<"element "<<target<<" found at index "<<res;
	else
		cout<<"element "<<target<<" not found!";
}
