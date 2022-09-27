/*	Pair Differrence II Count	
	Given an array nums of size n and a number diff, you need to write a program to find the counrt if there exists a 
	pair of elements in the array whose difference is diff.
		
		Input: nums= {5, 20, 3, 2, 5, 80}	, diff=78
		Output: 1
		Input: nums= {10, 2, 2, 2, 5, 6, 10, 10} , diff=8
		Output: 9
		
	Naive approach--> TC: O(n^2)
					  SC: O(n) //to store elements
	Optimised approach--> TC: O(n)	SC: O(n) //using 2 pointers
						  TC: O(n)  SC: O(n) //using map
						  				   	
*/

#include<bits/stdc++.h>
using namespace std;
//naive approach
/*int findPairDifference(vector<int>&nums, int diff){
	sort(nums.begin(),nums.end());
	int n=nums.size();
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j && nums[i]-nums[j]==diff){
				count++;
			}
		}
	}
	return count;	
}*/


int findPairDifference(vector<int>&nums, int diff){
	sort(nums.begin(),nums.end());
	int i=0,j=1,count=0;
	while(j<nums.size()){
		int n1=nums[j],n2=nums[i],c1=0,c2=0;
		if(nums[j]-nums[i]==diff){
			if(diff==0){
				while(nums[i]==n2){
					i++;
					j++;
					c1++;
				}
				count += c1*(c1-1)/2;
			}
			else{
				while(nums[i]==n2){
					i++; c1++;
				}
				while(nums[j]==n1){
					j++; c2++;
				}
				count+=c1*c2;
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
	int ans=findPairDifference(nums,diff);
	cout<<ans;
}

