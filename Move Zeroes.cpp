/*	283. Move Zeroes
	Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero 
	elements.
	Note that you must do this in-place without making a copy of the array.
	
		Input: nums = [0,1,0,3,12]
		Output: [1,3,12,0,0]
	
	naive approach: TC: O(n)
					SC: O(n)
	optimised approach: O(n)
					SC: O(1)					
*/

#include<bits/stdc++.h>
using namespace std;

//naive appraoch
void moveZeroes(vector<int>&nums){
	vector<int>temp;
	for(int i=0;i<nums.size();i++){
		if(nums[i]!=0)
			temp.push_back(nums[i]);
	}
	for(int i=0;i<temp.size();i++)
		nums[i]=temp[i];
	for(int i=temp.size();i<nums.size();i++)
		nums[i]=0;	
}

//optimised approach
/*void moveZeroes(vector<int>&nums){
	int i=0,j=0;
	while(i<nums.size()){
		if(nums[i]!=0){
			nums[j]=nums[i];
			j++;
		}
		i++;
	}
	while(j<nums.size())
		nums[j++]=0;
}*/

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	moveZeroes(nums);
	for(int i=0;i<n;i++)
		cout<<nums[i]<<" ";	
}
