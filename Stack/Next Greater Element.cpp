/*	Next Greater Element
	Given an array arr[ ] of size N having elements, the task is to find the next greater element for each element of
	the array in order of their appearance in the array.
	Next greater element of an element in the array is the nearest element on the right which is greater than the 
	current element.
	If there does not exist next greater of current element, then next greater element for current element is -1. 
	For example, next greater of the last element is always -1.
		Input: N = 4, arr[] = [1 3 2 4]
		Output: 3 4 4 -1
	
	Naive Approach--> 	  TC: O(n^2) 	SC: O(n)
	Optimised Approach--> TC: O(n)		SC: O(n)	
*/

#include<bits/stdc++.h>
using namespace std;
//naive approach
/*vector<int> findNGE(vector<int>&nums, int n){
	vector<int>NGE(n);
	for(int i=0;i<n;i++){
		NGE[i]=-1;
		for(int j=i+1;j<n;j++){
			if(nums[j]>nums[i]){
				NGE[i]=nums[j];
				break;
			}
		}
	}
	return NGE;
}*/

//optimised Approach
vector<int> findNGE(vector<int>&nums, int n){
	vector<int>ans(n);
	stack<int>st;
	st.push(0);
	for(int i=1;i<n;i++){
		while(!st.empty() && nums[i]>nums[st.top()]){
			ans[st.top()]=nums[i];
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		ans[st.top()]=-1;
		st.pop();
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	vector<int>ans=findNGE(nums,n);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";	
}
