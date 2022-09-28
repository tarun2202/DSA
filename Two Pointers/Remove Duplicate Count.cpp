/*	Remove duplicate elements from sorted Array
	Given a sorted array A[] of size N, delete all the duplicated elements from A[].Update the array such that if 
	there are X distinct elements in it then the first X positions of the array should be filled with them in 
	increasing order.
	
		Input:	N = 5	Array = {2, 2, 2, 2, 2}
		Output: 1

	Time Complexity: O(N)
	Auxiliary Space: O(1)
*/

#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>&nums,int n){
	if(n==0 || n==1)
		return n;
	int i,j=0;
	for(i=0;i<n-1;i++){
		if(nums[i]!=nums[i+1])
			nums[j++]=nums[i];
	}
	nums[j++]=nums[n-1];
	return j;	
}
int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int ans=removeDuplicates(nums,n);	
	cout<<ans;
}
