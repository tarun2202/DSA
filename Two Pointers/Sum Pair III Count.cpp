/*	Count pairs with given sum
	Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum 
	is equal to target.
		Input: N = 9, target = 10, arr[] = {1, 4, 4, 5, 5, 5, 6, 6, 11}
		Output: 
		
	time complexity: O(n)
	space complexity: O(1)	
	
	NOTE: 1) array is already considered as sorted in ASC order. 
		  2) handles cases of repeated(duplicate) elements.
*/

#include<bits/stdc++.h>
using namespace std;
int sumPairIII(vector<int>&nums,int target){
	int n=nums.size();
	int i=0,j=n-1,ans=0;
	while(i<j){
		if(nums[i]+nums[j]>target)
			j--;
		else if(nums[i]+nums[j]<target)
			i++;
		else{
			if(nums[i]==nums[j]){
				int l=j-i+1;
				ans+= l*(l-1)/2;
				break;
			}
			int v1=nums[i], v2=nums[j], c1=0, c2=0;
			while(nums[i]==v1){
				i++; 
				c1++;
			}
			while(nums[j]==v2){
				j--;
				c2++;
			}
			ans+= c1*c2;
		}		
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int target;
	cin>>target;
	int ans=sumPairIII(nums,target);
	cout<<ans;
}
