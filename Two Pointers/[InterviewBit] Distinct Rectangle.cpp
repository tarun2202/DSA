/*	Distinct Rectangle
	Given a sorted array of distinct integers A and an integer B, find and return how many rectangles with distinct 
	configurations can be created using elements of this array as length and breadth whose area is lesser than B. 
	(Note that a rectangle of 2 x 3 is different from 3 x 2 if we take configuration into view) For example:
		Input: nums = [2 3 5],  B = 15
		Output: 6 
		Explanation: (2 x 2, 2 x 3, 2 x 5, 3 x 2, 3 x 3, 5 x 2)
	
	naive approach--> 	  TC: O(n^2)	SC: O(1)
	optimised approach--> TC: O(n) 		SC: O(1)	

*/

#include<bits/stdc++.h>
using namespace std;
//Optimised Approach
int countDistinctRectangle(vector<int>&nums,int n,int area){
	int count=0;
	int i=0,j=n-1;
	while(i<=j){
		if(nums[i]*nums[j]>=area)
			j--;
		//since my input array elements are distinct, so there will be no duplicate configurations	
		else {
			//since rectangle of 2 x 3 is different from 3 x 2: therefore multiply the (j-i+1) by 2
			//subtract -1: because we don't want to consider the same configuation twice. 
			count += 2*(j-i+1)-1; 
			i++;
		}
	}	
	return count;
}

//naive appraoch
/*int countDistinctRectangle(vector<int>&nums,int n,int area){
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(nums[i]*nums[j]<area)
				count++;
		}
	}
	return count;
}*/

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int area;
	cin>>area;
	int ans=countDistinctRectangle(nums,n,area);
	cout<<ans;	
}
