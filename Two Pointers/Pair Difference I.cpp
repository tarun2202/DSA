/*	Pair Differrence	
	Given an array nums of size n and a number diff, you need to write a program to find if there exists a pair of 
	elements in the array whose difference is diff.
		Input: nums= {5, 20, 3, 2, 5, 80}	, diff=78
		Output: 1
	Naive approach--> TC: O(n^2)
					  SC: O(1) //to store elements
	Optimised approach--> TC: O(n)	SC: O(1) //using 2 pointers
						  TC: O(n)  SC: O(n) //using map			   	
*/

#include<bits/stdc++.h>
using namespace std;

//naive approach
bool findPairDifference(vector<int>&nums, int diff){
	sort(nums.begin(),nums.end());
	int n=nums.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j && nums[i]-nums[j]==diff){
				return true;
			}
		}
	}
	return false;	
}

//optimised approach
/*bool findPairDifference(vector<int> &nums, int diff){
	sort(nums.begin(),nums.end());
	int i=0,j=1;
	while(j<nums.size()){
		if(nums[j]-nums[i]==diff){
            return true;
		}
		else if(nums[j]-nums[i]<diff)
			j++;
		else {
			i++;
			if(i==j)	
				j++;
		}		
	}
    return false;
}*/

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int diff;
	cin>>diff;	
	bool ans = findPairDifference(nums,diff);
	cout<<ans;
}


