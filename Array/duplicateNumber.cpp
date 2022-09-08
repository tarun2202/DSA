/*	287. Find the Duplicate Number
	Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] 
	There is only one repeated number in nums, return this repeated number.
		  	Input: nums = [1,3,4,2,2]
			Output: 2
*/

#include <bits/stdc++.h>
using namespace std;
/*
	naive approach --> first sort the array and then look for adjacent elements, if same--> return the current
	element, i.e., duplicate number.
	time complexity: O(nlogn)
	space complexity:O(1)

int findDuplicate(vector <int> & nums,int n){
	sort(nums.begin(),nums.end());
    int ans=-1;
	for(int i=0;i<n-1;i++){
		if(nums[i]==nums[i+1])
			ans= nums[i];	
	}
	return ans;	
}
/*
	better approach --> make the frequency array and then traverse over the whole array and check if its 
	frequency id greater than 2, return that element--> that is our duplicate number.  
	time complexity: O(n)
	space complexity:O(n)

int findDuplicate(vector <int> & nums,int n){
	vector<int>freq(n,0);
	int ans=-1;
	for(int i=0;i<n;i++){
		if(freq[nums[i]]==0)
			freq[nums[i]]+=1;
		else 	
			ans= nums[i];	
	}
	return ans;	
}
*/
/*
	optimised approach --> using linked list cycle method
	
	since there exists a duplicate number, there must be the cycle formed. 
	the slow pointer moves by 1 step and fast pointer moves by two step, and there exists a cycle. so the 
	first collision is bound to happen.
	Now take the fast pointer and place it at the first element and move the fast and slow pointer both 
	by 1 step. The point where they collide will be the duplicate number.
	  
	time complexity: O(n)
	space complexity:O(1)
*/

int findDuplicate(vector <int> & nums,int n){
	int fast =nums[0];
	int slow=nums[0];
	do{
		slow=nums[slow];
		fast=nums[nums[fast]];
	}while(slow!=fast);
	fast=nums[0];
	while(slow!=fast){
		slow=nums[slow];
		fast=nums[fast];
	}
	return slow;//here at this point slow and fast both are pointing to same element, duplicate number.
}
int main() {
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int ans=findDuplicate(nums,n);
    cout<<ans;
}
