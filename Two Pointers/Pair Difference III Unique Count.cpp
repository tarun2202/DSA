/*	532. K-diff Pairs in an Array
	Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
	Input: nums = [3,1,4,1,5], k = 2
	Output: 2
	Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
		
		time complexity: O(nlogn)
		space complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;
int findUniquePairDifference(vector<int>&nums, int diff){
	sort(nums.begin(),nums.end());
	int i=0,j=1,count=0;
	while(j<nums.size()){
		int n1=nums[j],n2=nums[i];
		if(nums[j]-nums[i]==diff){
			if(diff==0){
				while(nums[i]==n2){
					i++;
					j++;
				}
				count += 1;
			}
			else{
				while(nums[i]==n2)
					i++; 
				while(nums[j]==n1)
					j++; 
				count += 1;
			}
		}
		else if(nums[j]-nums[i]<diff)
			j++;
		else {
			i++;
			if(i==j)	
				j++;
		}		
	}
	return count;
}
int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int diff;
	cin>>diff;	
	int ans=findUniquePairDifference(nums,diff);
	cout<<ans;
}
