/*	Pair Sum
	Given an array of integers nums and an integer target, return indices of the two numbers such that they add 
	up to target.
		Input: nums = [2,7,11,15], target = 9
		Output: [0,1]
	
	naive Approach--> TC: O(n^2)		
	optimised Approach--> TC:O(n)
*/

#include<bits/stdc++.h>
using namespace std;

//optimised Apporach
void findPairSum(vector<int>&nums, int target){
	int n=nums.size();
	vector<int>index;
	for()
}

//brute Force
void findPairSum(vector<int>&nums, int target){
	int n=nums.size();
	vector<int>index;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(nums[i]+nums[j]==target){
				index.push_back(i);
				index.push_back(j);
			}
		}
	}
	for(int i=0;i<index.size();i++)
		cout<<index[i]<<" ";
}

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int target;
	cin>>target;
	findPairSum(nums,target);	
}
