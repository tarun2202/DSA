/*	977. Squares of a Sorted Array
	Given an integer array nums sorted in non-decreasing order, return an array of the squares of each 
	number sorted in non-decreasing order.
		Input: nums = [-4,-1,0,3,10]
		Output: [0,1,9,16,100]
	
	Naive Approach: time complexity: O(nlogn)
					space complexity: O(1)
	Optimised Approach: time complexity: O(n)
						space complexity: O(n)				
					 	
*/

#include<bits/stdc++.h>
using namespace std;

//naive approach:
/*vector<int> sortedSquare(vector<int> &nums){
	int n=nums.size();
	for(int i=0;i<n;i++)
		nums[i]*=nums[i];
	sort(nums.begin(),nums.end());
	return nums;	
}*/

//optimised approach: 
vector<int> sortedSquare(vector<int> &nums){
	int n=nums.size();
	int i,j=0;
	for(i=0;i<n;i++){
		if(nums[i]>=0)
		break;
	}
	//i : pointing to the first index of the array(square Array) that is sorted in the asc order
	j=i-1; //pointing to the last index of the array(sqaure Array) that is sorted in desc order.
	vector<int>ans;
	while(i<n && j>=0){
		if(nums[i]*nums[i]<=nums[j]*nums[j]){
			ans.push_back(nums[i]*nums[i]);
			i++;
		}
		else{
			ans.push_back(nums[j]*nums[j]);
			j--;
		}
	}
	while(i<n){
		ans.push_back(nums[i]*nums[i]);
		i++;
	}
	while(j>=0){
		ans.push_back(nums[j]*nums[j]);
		j--;
	}
	return ans;		
}
int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	vector<int>ans;	
	ans =sortedSquare(nums);
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";	
}

