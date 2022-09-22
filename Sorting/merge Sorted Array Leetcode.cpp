/*	88. Merge Sorted Array
	You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m 
	and n, representing the number of elements in nums1 and nums2 respectively.
	Merge nums1 and nums2 into a single array sorted in non-decreasing order.
		Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
		Output: [1,2,2,3,5,6]
	
	time complexity: O(m+n)
	space complexity: O(1)	
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> mergeProcess(vector<int>&arr1, int m, vector<int>&arr2, int n){
	int i=m-1;
	int j=n-1;
	int k=m+n-1;
	while(i>=0 && j>=0){
		if(arr1[i] > arr2[j])
			arr1[k--] = arr1[i--];
		else
			arr1[k--] = arr2[j--];	
	}
	while(j>0)
		arr1[k--]=arr2[j--];
	return arr1;
}
int main(){
	int m,n;
	cin>>m;
	vector<int>arr1(m);
	for(int i=0;i<m;i++)
		cin>>arr1[i];
	cin>>n;
	vector<int>arr2(n);	
	for(int i=0;i<n;i++)
		cin>>arr2[i];
	arr1=mergeProcess(arr1,m,arr2,n);
	for(int i=0;i<m+n;i++)
		cout<<arr1[i]<<" ";
}
